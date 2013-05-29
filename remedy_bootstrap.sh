# Bootstrap script for Remedy.
# /!\ alpha status

# clone remedy github repo
git clone https://github.com/ProjectRemedy/Remedy.git

# add salt repositories - depends on distro!

# install salt-minion
aptitude install salt-minion

# Create a local /srv directory if it does not exist
if [ ! -e /srv ]; then
  mkdir /srv
fi

# copy local srv/salt to filesystem
cp -Ri Remedy/salt/srv/salt /srv/

# At this time the one-time minion config file is in Remedy/salt/
# Run something like:  salt-call -c Remedy/salt state.highstate
