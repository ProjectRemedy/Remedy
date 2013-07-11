# Bootstrap script for Remedy.
# /!\ alpha status
# This script probably only works for Ubuntu

# clone remedy github repo
git clone https://github.com/ProjectRemedy/Remedy.git /tmp/Remedy

# add salt repositories - depends on distro!
aptitude install python-software-properties
add-apt-repository ppa:saltstack/salt
wget -q -O- "http://keyserver.ubuntu.com:11371/pks/lookup?op=get&search=0x4759FA960E27C0A6" | apt-key add -


# install salt-minion
aptitude install salt-minion

# Create a local /srv directory if it does not exist
if [ ! -e /srv ]; then
  mkdir /srv
fi
if [ ! -d /srv ]; then
  echo Could not create directory /srv, aborting.
  exit 1
fi

# copy local srv/salt to filesystem
cp -Ri /tmp/Remedy/salt/srv/salt /srv/

# At this time the one-time minion config file is in Remedy/salt/
# Run masterless command to continue bootstrap:
salt-call -c /tmp/Remedy/salt/ state.highstate 
#  - this will do minimalist operation to have salt master and minion
#    configured and running

# Finally we can to a salt '*' state.highstate and the locally running
# master will tell the locally running minion to finish the job.


# And remove /tmp/Remedy as it should not be useful anymore
rm -fr /tmp/Remedy

echo "The local SaltStack installation and setup should be completed with success now"
echo "Run the following command install and configure the whole dashboard:"
echo "  salt '*' state.highstate"
