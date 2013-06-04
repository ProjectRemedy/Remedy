Collectd over Tor & Socat
=========================

## On the Master

* Install Collectd
* Install Tor
* Setup hidden service
  * Uncomment 
  * <code>HiddenServiceDir /var/lib/tor/hidden_collectd/</code>
  * <code>HiddenServicePort 55826 127.0.0.1:55826</code>
  * Restart Tor
* Install socat
* Run <code>socat TCP4-LISTEN:55826,bind=127.0.0.1,fork,reuseaddr UDP:127.0.0.1:25826 &</code>

## On the Minion
* Install Collectd
  * Setup network plugin to 127.0.0.1
  * interface <code>l0</code>
* Install Tor
* Install Socat
* Run <code>socat UDP4-LISTEN:25826,bind=127.0.0.1,fork,reuseaddr SOCKS4A:127.0.0.1:rkwu6pusfsyqly3q.onion:55826,socksport=9050 &</code>
