#!/bin/bash
# Run as su

# Install saltstack
apt-get update -y
apt-get install salt-minion -y
apt-get upgrade -y

# Set salt master location and start minion
sed -i 's/#master: salt/master: 1.2.3.4/' /etc/salt/minion
salt-minion -d 