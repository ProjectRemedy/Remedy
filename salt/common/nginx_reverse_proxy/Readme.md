Nginx Reverse Proxy State file
==============================

Here is a first version of Nginx reverse proxy statefile.

# Usage
* Specify yor reverse proxy domain name ( *reverse-proxy-domain-name* )
* Specify your target domain name ( *your-target-website* )
* Replace your uUser home file if needed (it is hardcoded : */home/ubuntu/* ) 

# Warnings
* HTTPS fully supported now (you need to provision your SSL certificate manually : *ssl_certificate / ssl_certificate_key*)

# Todo 
* Provisionning through Pillar
* Full support of HTTPS 
