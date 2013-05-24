Salt Installation Process
=========================

# Installation
## Prerequistes
* Register to AWS/EC2
* Install EC2 cli tools
* Setup EC2 credentials


## Bootstrap Dashboard
	wget github/remedy_bootstrap.sh
	ec2-runinstance -f remedy_bootstrap.sh
	//TODO : return onion domain name
	//TODO : installation errors output


# Testing installation

Start your Tor client
Connect with  your Tor browser to onion domain name


# Configuration

* <code>admin/remedy/settings/...</code>
  * Credentials EC2
  * Credentials DNSimple
  * Credentials ...
* provision relay nodes
* provision probes 
  * remedy managed probes
    * TODO
  * externally managed probes
    * TODO
