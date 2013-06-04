Collectd over Tor & Socat
=========================



socat TCP4-LISTEN:55826,bind=127.0.0.1,fork,reuseaddr UDP:127.0.0.1:25826 &


socat UDP4-LISTEN:25826,bind=127.0.0.1,fork,reuseaddr SOCKS4A:127.0.0.1:rkwu6pusfsyqly3q.onion:55826,socksport=9050 &
