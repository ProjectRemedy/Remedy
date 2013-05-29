# Bootstrap script for Remedy.
# /!\ alpha status

# clone remedy github repo
git clone git@github.com:ProjectRemedy/Remedy.git

# add salt repositories - depends on distro!
# install salt-minion
aptitude install salt-minion

# Run something like:  salt-call --local state.highstate

