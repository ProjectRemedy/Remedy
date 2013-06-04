# This is the salt-master top file
# it must reference states and target minions according to remedy_role grains.

# Rough, temporary example:

base:
  '*':
    - common.tor

  'G@remedy_role:master':
    - server.dashboard

  'G@remedy_role:probe':
    - probe.ooni-probe
