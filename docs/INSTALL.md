Installation
============

TODO: Update install process on drupal through Drush make.

## Prerequistes

### Collectd
* Install Collectd : <code>sudo apt-get install collectd</code>
* Enable network module in <code>/etc/collectd.conf</code>
 * Uncomment <code>#LoadPlugin network</code>
 * Uncomment & setup the <code>Plugin network</code> / <code>Server setup</code> section


### RRD
* RRDtool needs to be installed : http://oss.oetiker.ch/rrdtool/
   * For Ubuntu systems, install these before following the above guidance: <code>sudo apt-get install rrdtool librrd-dev php5-dev</code>
* Compile PHP extension for RRDtool : http://oss.oetiker.ch/rrdtool/pub/contrib/ + http://sam.liho.tw/2009/03/11/howto-build-the-php-rrdtool-extension/
* RRD files path should look like 
  * /opt/collectd/var/lib/collectd/rrd/[probe]/[domain-name]/DNSTamper.rrd
  * /opt/collectd/var/lib/collectd/rrd/[probe]/[domain-name]/IPBlock-[ip-address].rrd

### Drupal
* http://drupal.org/documentation/install

## Drupal Installation
* Rules modules needs to be patched
  * Either apply modules/rules/rules.install.patch & reinstall Rules
  * Or add a default value to rules_config table / plugin field default value = ''
  * TODO : Add SQL Query here
* Copy modules/remedy_dnsimple & modules/remedy_health modules to sites/all/modules
* Copy features/remedy_common to sites/all/modules
* Enable remedy_common either with drush (drush en remedy_common)
/e
