# This is the salt-master top file (by opposition to the bootstrap temporary top-file)
# It must reference states and target minions according to remedy_role grains.
# Rough, temporary example:

base:
  '*':
    - common.git
    - common.tor

  'remedy_role:master':
    - match: grain
    - server.dashboard

# Commented out for now ..
#  'G@remedy_role:probe':
#    - probe.ooni-probe
