# install salt-master
# config salt-master:
#   - create a 'salt' user
#   - create necessary directory structure (/srv/salt/*, /etc/salt/*)
#   - put the right config file in place
#   - copy master-side SLS files that will allow to command minions
# Cross-accept local master & minion:
#   - 1/ we may copy the master pubkey to /etc/salt/pki/minion/minion_master.pub
#   - 2/ we may accept the minion key with salt-key

salt-master:
  pkg:
    - installed

  file:
    - managed
    - name: /etc/salt/master
    - source: salt://server/salt/files/master
    - require:
      - pkg.installed: salt-master

  service:
    - running
    - watch:
      - file: /etc/salt/master

  group.present:
    - name: salt
    - system: True
    - require:
      - pkg.installed: salt-master

  user.present:
    - name: salt
    - shell: /bin/false
    - home: /var/run/salt
    - system: True
    - gid_from_name: True
    - require:
      - group: salt

salt-minion:
  pkg:
    - installed

  file:
    - managed
    - name: /etc/salt/minion
    - source: salt://server/salt/files/minion
    - require:
      - pkg.installed: salt-minion

  service:
    - running
    - watch:
      - file: /etc/salt/minion

accept-master-cert:
  cmd.run:
    - name: while [ ! -e /etc/salt/pki/master/master.pub ]; do sleep 1; done; cp /etc/salt/pki/master/master.pub /etc/salt/pki/minion/minion_master.pub
    - require:
      - service.running: salt-master
      - pkg.installed: salt-minion

      
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

