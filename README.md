Remedy
======

Relay Monitoring and Deployment Platform

Warnings
--------

### This is the first release and is not well documented or tested. Don't hesitate to submit issues on the github tracker!
### Remedy hasn't been designed or reviewed for operations in risky environments, please deploy responsibly. We will probably implement everything on top of Tor Hidden Services at some point. 
### Let us know on the tracker if you have suggestions!  

What is Remedy
--------------

### Overview

Remedy is a platform which helps in managing relay nodes (primarily reverse proxy nodes) that provide access to blocked content in a cyber-censored environment.

### Features

Remedy is designed to facilitate : 
* Monitoring of performance & traffic on relay nodes
* Visualize traffic of relays based on the dissemination channel that were used to publicise their existence
* Monitoring of in-country health status for each relay node
* Detecting in a timely manner any blocking event on each node & which blocking technique is used
* Mitigate any blocking event automatically by automating the deployment and configuration of relay nodes.

### The platform 

Remedy is designed in 4 components :
* Performance & traffic monitoring component for relay nodes
* Health monitoring system for nodes for censorship status monitoring
* Automated blockage mitigation & deployment features for existing & new nodes
* Monitoring dashboard for the visualisation and interactions with the three components above

### The technology

Remedy is powered by the following technologies.
* The performance & health monitoring status data collection is built on Collectd.
* The dashboard frontend is built using Drupal 7, one of the leading Content Management Framework
* Also, the mitigation process logic is implemented using Rules Drupal module, meaning they can be reconfigured without coding
* Relay nodes can be:
  * Nginx reverse proxies
  * OpenVPN/Obfsproxy servers
  * _(soon) Web mirrors_
  * _(soon) Tor bridges_
* Relays are deployed on Amazon Web Services cloud infrastructure, which allows a very quick & automated deployment, but will evolve to support more cloud providers (particularly OpenStack)

Dependencies
------------

* PHP/MySQL
* Drupal 7.x
* RRD
* Collectd
* AWS EC2 + AWS SDK for PHP - http://aws.amazon.com/sdkforphp/
* DNSSimple  + DNS Simple PHP Lib - https://github.com/fvdm/dnsimple-php

Installation
------------

###Drupal
Cf drupal/INSTALL.txt

##Directory structure
Apart from _docs_, the directories contain configuration elements to be installed on the dashboard server:
* _drupal_ contains the drupal installation
* _oonib_ contains the OONI backend configuration for the dashboard
* _salt_ contains Salt master-side configuration for both probes and relays
