rrdtool-pkg:
  pkg:
    - installed
    - name: rrdtool

collectd-pkg:
  pkg:
    - installed
    - name: collectd
    - require:
      - pkg.installed: rrdtool

collectd-cfg:
  file:
    - managed
    - source: salt://relay/files/collectd.conf
    - name: /etc/collectd/collectd.conf
    - template: jinja
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
