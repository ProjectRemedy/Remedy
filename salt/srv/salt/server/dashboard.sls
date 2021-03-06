# First draft for dashboard sls (not fully tested yet)
# based on https://github.com/saltstack/salt-states/blob/master/small/lamp-drupal/init.sls#L3

#oonib

collectd:
  pkg:
    - installed

conllectd-cfg:
  file:
    - managed
    - name: /etc/collectd/collectd.conf
    - source: salt://server/collectd.conf
    
socat:
  pkg:
    - installed  
    
tor-collectd:

php5-pkgs:
  pkg.installed:
    - names:
      - php5
      - php5-mysql
      - php5-curl
      - php5-cli
      - php5-cgi
      - php5-dev
      - php-pear
      - php5-gd

apache2:
  pkg.installed:
    - names:
      - apache2
      - libapache2-mod-php5

rrdtool-pkgs:
  pkg.installed:
    - names:
      - libxml2-dev
      - pango
      - libcairo2-dev

rrdtool-1.4.8.tar.gz:
  file:
    - managed
    - name: /home/ubuntu/rrdtool-1.4.8.tar.gz
    - source: http://oss.oetiker.ch/rrdtool/pub/rrdtool-1.4.8.tar.gz

rrdtool-install:
  cmd.run:
    - name: tar -xzvf rrdtool-1.4.8.tar.gz && cd rrdtool-1.4.8 && ./configure --prefix=/opt/rrdtool-1.4.8 && make && make install
    - cwd: /home/ubuntu/
    - require:
      - file: rrdtool-1.4.8.tar.gz

php_rrdtool.tar.gz:
  file:
    - managed
    - name: /home/ubuntu/php_rrdtool.tar.gz
    - source: http://oss.oetiker.ch/rrdtool/pub/contrib/php_rrdtool.tar.gz
  

php_rrdtool:
  cmd.run:
    - name: tar -xzvf php_rrdtool.tar.gz && mv rrdtool /usr/include/php5/
    - cwd: /home/ubuntu/
    - require:
      - file: php_rrdtool.tar.gz
      - pkg.installed: apache2

# Do we need this? sudo apt-get install rrdtool librrd-dev php5-dev gcc binutils


php_rrdtool-install:       
  cmd.run:
    - name: phpize && ./configure --with-php-config=/usr/bin/php-config --with-rrdtool=/usr/ && make && make install
    - cwd: /usr/include/php5/rrdtool/
    - require:
      - cmd: php_rrdtool

rrdtool.ini:
  file:
    - managed
    - name: /etc/php5/apache2/conf.d/rrdtool.ini
    - source: salt://server/rrdtool/files/rrdtool.ini
  
pear-drush:
  cmd.run:
    - name: pear channel-discover pear.drush.org && pear install drush/drush

mariadb-server-5.5:
  cmd.run:
    - name: sudo apt-key adv --recv-keys --keyserver hkp://keyserver.ubuntu.com:80 0xcbcb082a1bb943db
    - unless: apt-key list | grep -q 0xcbcb082a1bb943db
    - require:
      - file: mariadb-server-5.5
  file:
    - append
    - name: /etc/apt/sources.list
    - text: deb http://ftp.osuosl.org/pub/mariadb/repo/5.5/ubuntu precise main
    - skip_verify: True
  pkg:
    - installed
    - refresh: True
    - require:
      - cmd: mariadb-server-5.5


/etc/apache2/sites-available/dashboard.conf:
  file.managed:
    - source: salt://server/apache2/files/dashboard.conf
    - user: root
    - group: root
    - mode: 644
    - watch_in:
      - service: apache
      
a2enmod rewrite:
  cmd.run:
    - onlyif: test -e /etc/apache2/mods-enabled/rewrite.load
    - watch_in:
      - service: apache      

drupal_install: 
  cmd.run: 
    - name: drush dl drupal && mv drupal-7.22 dashboard

apache2-restart:
  cmd.run: 
    - name: service apache2 restart
    - require: 
      - file: rrdtool.ini
      
#install rules & patch it
#install bundle_inherit & patch it

remedy_drush: 
  cmd.run:
    - name: drush en remedy_core -y && drush en remedy_dashboard -y
    
      

