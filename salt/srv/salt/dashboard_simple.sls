# install salt-master
# config salt-master:
#   - create a 'salt' user
#   - create necessary directory structure (/srv/salt/*, /etc/salt/*)
#   - put the right config file in place
#   - copy master-side SLS files that will allow to command minions
# Cross-accept local master & minion:
#   - 1/ we may copy the master pubkey to /etc/salt/pki/minion/minion_master.pub
#   - 2/ we may accept the minion key with salt-key

salt-master-pkg:
  pkg:
    - name: salt-master
    - installed

salt-minion-pkg:
  pkg:
    - name: salt-minion
    - installed

salt-master-user:
  group.present:
    - name: salt
    - system: True

  user.present:
    - name: salt
    - shell: /bin/false
    - home: /var/run/salt
    - system: True
    - gid_from_name: True
    - require:
      - group: salt

salt-master-cfg:
  file:
    - managed
    - name: /etc/salt/master
    - source: salt://server/salt/files/master
    - require:
      - user: salt

salt-minion-cfg:
  file:
    - managed
    - name: /etc/salt/minion
    - source: salt://server/salt/files/minion

salt-service-master:
  service:
    - name: salt-master
    - running
    - require:
      - pkg.installed: salt-master
    - watch:
      - file: /etc/salt/master

salt-service-minion:
  service:
    - name: salt-minion
    - running
    - require:
      - pkg.installed: salt-minion
    - watch:
      - file: /etc/salt/minion

accept-master-pubkey:
  cmd.run:
    - name: while [ ! -e /etc/salt/pki/master/master.pub ]; do sleep 1; done; cp /etc/salt/pki/master/master.pub /etc/salt/pki/minion/minion_master.pub
    - require:
      - service.running: salt-master

accept-minion-pubkey:
  cmd.run:
    - name: while [ 1 ]; do for minion_id in $(salt-key --no-color -l pre | tail -n +2); do diff /etc/salt/pki/minion/minion.pub /etc/salt/pki/master/minions_pre/$minion_id && salt-key -a $minion_id && exit 0; done; sleep 1; done
    - require:
      - service.running: salt-minion
      - cmd: accept-master-pubkey

# install tor (from _source_ which means having the right dependancies beforehand)

# install ooni-backend

# apt-get install collectd
# setup collectd
# specific setup for aggregating data from ooni-backend <...>
# setup tor & socat for collectd

# install webserver
# install ssl ssl.cert & ssl.key
# install mysql
# install php (+ dependencies)
# setup php_rrdtool 

# install drush
# install drush_make
# drush make remedy.make

# setup tor hidden service for dashboard 


# Start running everything!

