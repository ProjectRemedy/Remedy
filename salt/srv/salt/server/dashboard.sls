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
  pkg:
    - installed

#RRDtool + php_rrdtool
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
    - name: /home/ubuntu/rrdtool-1.4.8.tar.gz
    - source: http://oss.oetiker.ch/rrdtool/pub/rrdtool-1.4.8.tar.gz
  

php_rrdtool:
  cmd.run:
    - name: tar -xzvf php_rrdtool.tar.gz && mv rrdtool /usr/include/php5/
    - cwd: /home/ubuntu/
    - require:
      - file: php_rrdtool.tar.gz
      - pkg.installed: apache2
      
php_rrdtool-install:       
  cmd.run:
    - name: phpize && make && make install
    - cwd: /usr/include/php5/rrdtool/
    - require:
      - cmd: php_rrdtool

rrdtool.ini:
  file:
    - managed
    - name: /etc/php5/apache2/conf.d/rrdtool.ini
    - source: salt://
  
/*
service apache2 restart
*/    

    
pear-drush:
  cmd.run:
    - name: pear channel-discover pear.drush.org & pear install drush/drush

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
      
      

remedy_drush: 
  cmd.run:
    - name: drush en remedy_core -y && drush en remedy_dashboard -y
    
      

