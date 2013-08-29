socat-cfg-collectd:
  file:
    - managed
    - name: /etc/socat/collectd-into-tor
    - source: salt://relay/files/socat-collectd-into-tor
    - template: jinja
    - user: root
    - groupe: root
    - mode: 644
    - require:
      - pkg.installed: socat
      - file: /etc/init.d/socat
