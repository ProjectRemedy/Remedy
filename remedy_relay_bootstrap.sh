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

# if the masterless execution of salt does its job correctly, we're theoretically done here.

# following lines serve as a reminder for now (will be moved/deleted)
# Configure and start tor
#echo -e 'SocksPort 9040\nRunAsDaemon 1\nPidFile /var/run/tor.pid' >/etc/torrc
#tor -f /etc/torrc

# Start socat to forward to the Tor hidden service
#socat TCP4-LISTEN:4505,bind=127.0.0.1,fork,reuseaddr SOCKS4A:127.0.0.1:$REMEDY_MASTER_SERVICE_NAME:4505,socksport=9040 &
#socat TCP4-LISTEN:4506,bind=127.0.0.1,fork,reuseaddr SOCKS4A:127.0.0.1:$REMEDY_MASTER_SERVICE_NAME:4506,socksport=9040 &

