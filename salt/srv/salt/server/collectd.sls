collectd-pkg:
  pkg:
    - installed
    - name: collectd

collectd-cfg:
  file:
    - managed
    - source: salt://server/files/collectd.conf
    - name: /etc/collectd/collectd.conf
    - user: root
    - mode: 644
    - require:
      - pkg.installed: collectd

collectd-service:
  service:
    - name: collectd
    - running
    - enable: True
    - require:
      - pkg.installed: collectd
    - watch:
      - file: /etc/collectd/collectd.conf
