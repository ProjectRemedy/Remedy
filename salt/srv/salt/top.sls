# This is the salt-master top file (by opposition to the bootstrap temporary top-file)
# It must reference states and target minions according to remedy_role grains.
# Rough, temporary example:

base:
  '*':
    - common.git
    - common.tor

  'remedy_role:relay_web':
    - match: grain
    - relay.nginx_rp_simple

#  'remedy_role:master':
#    - match: grain
#    - server.dashboard

# Commented out for now ..
#  'remedy_role:probe':
#    - match: grain
#    - probe.ooni-probe
