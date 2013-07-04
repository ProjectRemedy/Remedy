# This is the salt-master top file (by opposition to the bootstrap temporary top-file)
# It must reference states and target minions according to remedy_role grains.
# Rough, temporary example:

base:
  '*':
    - common.tor
# Temporarily commented out for testing purposes:
#  'G@remedy_role:master':
#    - server.dashboard
#
#  'G@remedy_role:probe':
#    - probe.ooni-probe
