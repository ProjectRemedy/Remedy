INSTALLATION
============
Prerequistes
  Register to AWS/EC2
	Install EC2 cli tools
	Setup EC2 credentials


Bootstrap EC2
	wget github/remedy_bootstrap.sh
	ec2-runinstance -f remedy_bootstrap.sh
	//TODO : return onion domain name
	//TODO : installation errors output


TESTING INSTALLATION
====================
Start your Tor client
Connect with  your Tor browser to onion domain name


CONFIGURATION
=============
admin/remedy/settings/...
	Credentials EC2
	Credentials DNSimple
	Credentials ...

provision relay nodes

provision probes 
	remedy managed probes
	TODO

	externally managed probes
	TODO
