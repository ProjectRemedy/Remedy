#!/bin/bash
# Run as root

# Install saltstack
add-apt-repository ppa:saltstack/salt -y
apt-get update -y
apt-get install salt-minion -y
apt-get upgrade -y
apt-get install gcc make libevent-dev git socat autotools-dev autoconf automake libssl-dev -y

# Compile and install tor
git clone https://git.torproject.org/tor.git /tmp/tor
cd /tmp/tor
git checkout tor-0.2.3.25
./autogen.sh && ./configure --disable-asciidoc && make && make install
if [ -z "$(which tor)" ]; then
  echo Tor install failed -- exiting
  rm -fr /tmp/tor
  exit 1
fi

# Configure and start tor
echo -e 'SocksPort 9040\nRunAsDaemon 1\nPidFile /var/run/tor.pid' >/etc/torrc
tor -f /etc/torrc

if [ -z "$REMEDY_MASTER_SERVICE_NAME" ]; then
  REMEDY_MASTER_SERVICE_NAME=ibraa6yfif5e6pbh.onion
fi
if [ -z "$REMEDY_ROLE_GRAIN" ]; then
  REMEDY_ROLE_GRAIN="relay_web"
fi

# Start socat to forward to the Tor hidden service
socat TCP4-LISTEN:4505,bind=127.0.0.1,fork,reuseaddr SOCKS4A:127.0.0.1:$REMEDY_MASTER_SERVICE_NAME:4505,socksport=9040 &
socat TCP4-LISTEN:4506,bind=127.0.0.1,fork,reuseaddr SOCKS4A:127.0.0.1:$REMEDY_MASTER_SERVICE_NAME:4506,socksport=9040 &

# Configure salt minion with grains and how to reach master and start minion
echo -e 'master: 127.0.0.1\ngrains:\n  remedy_role: '$REMEDY_ROLE_GRAIN >/etc/salt/minion
invoke-rc.d salt-minion restart

rm -fr /tmp/tor