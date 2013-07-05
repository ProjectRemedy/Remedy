build-essential:
  pkg:
    - installed
  
liblua5.1-0-dev:
  pkg:
    - installed
  
libpcre3-dev:
  pkg:
    - installed
  
libcurl4-openssl-dev:
  pkg:
    - installed
  
nginx-download:
  cmd.run:
    - name: wget http://nginx.org/download/nginx-1.5.1.tar.gz; tar -xzvf nginx-1.5.1.tar.gz;   

nginx-lua:
  git.latest:
    - name: https://github.com/chaoslawful/lua-nginx-module.git
    - target: /home/ubuntu/lua-nginx-module
    - rev: master

nginx-devel:
  git.latest:
    - name: https://github.com/simpl/ngx_devel_kit.git
    - target: /home/ubuntu/ngx_devel_kit
    - rev: master

nginx-http-sub-filter:
  git.latest:
    - name: https://github.com/yaoweibin/ngx_http_substitutions_filter_module.git
    - target: /home/ubuntu/ngx_http_substitutions_filter_module
    - rev: master

sudo ./configure --prefix=/opt/nginx --add-module=/home/ubuntu/ngx_http_substitutions_filter_module --http-proxy-temp-path=/opt/nginx/temp/proxy-temp --http-client-body-temp-path=/opt/nginx/temp/client-body-temp--http-fastcgi-temp-path=/opt/nginx/temp/fastcgi-temp --http-uwsgi-temp-path=/opt/nginx/temp/uwsgi-temp --http-scgi-temp-path=/opt/nginx/temp/scgi-temp --with-http_ssl_module --with-http_sub_module --with-http_stub_status_module --with-ipv6 --add-module=/home/ubuntu/lua-nginx-module-master --add-module=/home/ubuntu/ngx_devel_kit:
  cmd.run:
    - cwd: /home/ubuntu/nginx-1.5.1/

make:
  cmd.run:
    - cwd: /home/ubuntu/nginx-1.5.1/

make install: 
  cmd.run: 
    - cwd: /home/ubuntu/nginx-1.5.1/

nginx-file-conf:
  file:
    - managed
    - name: /opt/nginx/conf/nginx.conf
    - source: salt://files/nginx.conf

nginx-file-robots:
  file:
    - managed
    - name: /opt/nginx/robots.txt
    - source: salt://files/robots.txt

nginx-file-proxy:
  file:
    - managed
    - name: /opt/nginx/reverse-proxy-domain-name.js
    - source: salt://files/reverse-proxy-domain-name.js

date > /tmp/salt-run:
  cmd:
    - run