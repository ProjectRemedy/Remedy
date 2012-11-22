Remedy
======

Relay Monitoring and Deployment Platform

What is Remedy
--------------

### Overview

Remedy is a management platform for relay nodes (primarily reverse proxy nodes) for blocked content in a cyber-censored environment.

### Features

Remedy is designed to facilitate : 
* Monitoring of performance & traffic on relay nodes
* Visualize traffic of distribution campaigns  on a per-campaign basis
* Monitoring of in-country health status for each relay node
* Detecting in a timely manner any blocking event on each node, & which blocking technique is used
* Mitigate any blocking event automatically 

### The platform 

Remedy is designed in 4 components :
* Performance & traffic monitoring component for relay nodes
* Health monitoring system for nodes for censorship status monitoring
* Automated blockage mitigation & deployment features for existing & new nodes
* Monitoring dashboard for the visualisation and interactions with the three components above

### The technology


Remedy is powered by the following technologies.
* The performance & health monitoring status data collection is built on RRD, an opensource & most advanced system timestamped data storage
* The dashboard frontend is built using Drupal, one of the leading Content Management Framework
* Also, the mitigation process logic is implemented using Rules Drupal module, meaning they can be reconfigured without coding
* Relays are deployed on Amazon Web Services cloud infrastructure, which allows a very quick & automated deployment, but will evolve to support more cloud providers


Installation
------------

###Drupal
Cf drupal/INSTALL.txt