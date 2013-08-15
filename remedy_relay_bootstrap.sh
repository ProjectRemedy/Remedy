#!/bin/bash
# Bootstrap script for Remedy Relays.
# /!\ alpha status, experimental
# Run as root - probably works only for Ubuntu systems for now

# Settings for newly created minion
if [ -z "$REMEDY_MASTER_SERVICE_NAME" ]; then
  # No reasonable default - exit
  echo Variable REMEDY_MASTER_SERVICE_NAME not set, exiting
  exit 1
fi
if [ -z "$REMEDY_MINION_ID" ]; then
  # No reasonable default - exit
  echo Variable REMEDY_MINION_ID not set, exiting
  exit 1
fi
if [ -z "$REMEDY_ROLE_GRAIN" ]; then
  # Reasonable default
  REMEDY_ROLE_GRAIN="relay_web"
fi

# Install salt-minion
apt-get install python-software-properties -y
add-apt-repository ppa:saltstack/salt -y
wget -q -O- "http://keyserver.ubuntu.com:11371/pks/lookup?op=get&search=0x4759FA960E27C0A6" | apt-key add -
apt-get update
apt-get install git salt-minion -y

# Debian not so intelligently starts it automatically so let's stop it
invoke-rc.d salt-minion stop

# Prepare masterless run
mkdir -p /tmp/remedy-bootstrap/srv
if [ ! -d /tmp/remedy-bootstrap/srv ]; then
  echo Could not create temporary directories to bootstrap the system
  exit 1
fi
git clone https://github.com/ProjectRemedy/Remedy.git /tmp/Remedy
cp -Rf /tmp/Remedy/salt/srv/salt /tmp/remedy-bootstrap/srv/
cp -f /tmp/Remedy/salt/bootstrap/minion/minion /tmp/remedy-bootstrap/

echo -e 'id: '$REMEDY_MINION_ID'\ngrains:\n  remedy_role: '$REMEDY_ROLE_GRAIN'\n  master_hidden_service: '$REMEDY_MASTER_SERVICE_NAME \
    >>/tmp/remedy-bootstrap/minion

# This should install and connect salt minion to the master through Tor
salt-call -c /tmp/remedy-bootstrap state.highstate

rm -fr /tmp/Remedy /tmp/remedy-bootstrap

# Due to a SaltStack problem which makes it stuck on a zombie process when trying to start socat service,
# we have to do the two final steps by hand:

invoke-rc.d socat start
invoke-rc.d salt-minion start
