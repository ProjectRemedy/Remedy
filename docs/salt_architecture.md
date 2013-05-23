remedy_bootstrap.sh
salt/
  	server/
		dashboard_simple.sls
		
		webserver/
			torrc
			nginx.conf
			ssl/
				ssl.cert
				ssl.key
			drupal/
				profiles/
					remedy.profile
					remedy.make
					...
				features/
					remedy_core/
						...
					remed_dashboard/
						...
					remedy_mitigation/
						...
				modules/
					patchs/
						//patchs for contrib modules
						bundle_inherit.patch
						rules.patch
					custom/
					...

		collectd/
			collectd.conf
			torrc
		ooni-backend/
			torrc
	relays/
		nginx_reverseproxy_relay/
			init.sls
			nginx.conf
			collectd.conf
			torrc			
		openvpn_relay/
			openvpn/
			collectd_client_openvpn/
				//collectd setup for openvpnplugin
				//collectd network client setup to dashboard 
		tor_relay/
			...
		cgi-proxy_relay/
			cg-proxy/
			...
		psiphon_relay/
			...
	probe/
		ooni-probe/
			... 
	packages/
		collectd/
		nginx/
		tor/

	instances/ #dynamically managed by Remedy through Pillar??
		top.sls
		relay-minionID/
			ssl.cert
			relay1.conf #nginx conf
		relay2-minionID/
			...
		probe1-/
			...
		probe2/
			...
