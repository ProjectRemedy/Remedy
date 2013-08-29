# This is the salt-master top file (by opposition to the bootstrap temporary top-file)
# It must reference states and target minions according (at least) to remedy_role grains.

base:
  '*':
    - common.git
    - common.tor

  'remedy_role:master':
    - match: grain
    - server.collectd
    - server.socat

# Those are common to all relays:
  'remedy_role:relay_.*':
    - match: grain_pcre
    - relay.socat
    - relay.collectd

  'remedy_role:relay_web':
    - match: grain
    - relay.nginx_rp_simple

# Commented out for now ..
#  'remedy_role:probe':
#    - match: grain
#    - probe.ooni-probe
