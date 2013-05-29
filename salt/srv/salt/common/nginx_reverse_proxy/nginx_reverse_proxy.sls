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
  
nginx:
  pkg:
    - installed
  service:
    - running

    State: - git
    Name:      git@github.com:chaoslawful/lua-nginx-module.git
    Function:  latest
        Result:    True
        Comment:   Repository git@github.com:chaoslawful/lua-nginx-module.git cloned to /usr/share/nginx/
        Changes:   new: git@@github.com:chaoslawful/lua-nginx-module.git

    State: - git
    Name:      git@github.com:simpl/ngx_devel_kit.git
    Function:  latest
        Result:    True
        Comment:   Repository git@github.com:simpl/ngx_devel_kit.git cloned to /usr/share/nginx/
        Changes:   new: git@github.com:simpl/ngx_devel_kit.git

    State: - git
    Name:      git@github.com:yaoweibin/ngx_http_substitutions_filter_module.git
    Function:  latest
        Result:    True
        Comment:   Repository git@github.com:yaoweibin/ngx_http_substitutions_filter_module.git cloned to /usr/share/nginx/
        Changes:   new: git@github.com:yaoweibin/ngx_http_substitutions_filter_module.git

nginx-sub:
  cmd.run:
    - name: cd nginx-version-number 
#here we should know the name of the folder! it's related with the version number! 

nginx:
  cmd.run:
    - name: ./configure --prefix=/opt/nginx 

nginx:
  cmd.run:
    - name: --add-module=/home/ubuntu/ngx_http_substitutions_filter_module


nginx:
  cmd.run:
    - name: --http-proxy-temp-path=/opt/nginx/temp/proxy-temp 

nginx:
  cmd.run:
    - name: --http-client-body-temp-path=/opt/nginx/temp/client-body-temp

nginx:
  cmd.run:
    - name: --http-fastcgi-temp-path=/opt/nginx/temp/fastcgi-temp

nginx:
  cmd.run:
    - name: --http-uwsgi-temp-path=/opt/nginx/temp/uwsgi-temp

nginx:
  cmd.run:
    - name: --http-scgi-temp-path=/opt/nginx/temp/scgi-temp --with-http_ssl_module


nginx:
  cmd.run:
    - name: --with-http_sub_module --with-http_stub_status_module --with-ipv6

nginx:
  cmd.run:
    - name: --add-module=/home/ubuntu/lua-nginx-module-master

#change the name of the user's folder "ubuntu"

nginx:
  cmd.run:
    - name: --add-module=/home/ubuntu/ngx_devel_kit
#change the name of the user's folder "ubuntu"

nginx:
  cmd.run:
    - name: sudo make

nginx:
  cmd.run:
    - name: sudo make install


  file:
    - managed
    - name: /opt/nginx/conf/nginx.conf
    - source: salt://files/nginx.conf

  file:
    - managed
    - name: /opt/nginx/robots.txt
    - source: salt://files/robots.txt

  file:
    - managed
    - name: /opt/nginx/reverse-proxy-domain-name.js
    - source: salt://files/reverse-proxy-domain-name.js
