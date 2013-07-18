nginx-pkg:
  pkg.installed:
    - nginx

nginx-cfg:
  file:
    - managed
    - name: /etc/nginx/nginx.conf
    - source: salt://relay/files/nginx.conf
    - user: root
    - group: root
    - mode: 644
    - require:
      - pkg.installed: nginx

nginx-logdir:
  file:
    - directory
    - name: /var/log/nginx
    - user: nobody
    - group: nogroup
    - require:
      - pkg.installed: nginx

nginx-cachedir:
  file:
    - directory
    - name: /var/cache/nginx
    - user: nobody
    - group: nogroup
    - require:
      - pkg.installed: nginx
