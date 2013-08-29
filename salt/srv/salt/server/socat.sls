socat-pkg:
  pkg.installed:
    - name: socat

socat-init-script:
  file:
    - managed
    - name: /etc/init.d/socat
    - source: salt://common/files/socat-init
    - mode: 755
    - user: root
    - group: root
    - require:
      - pkg.installed: socat

socat-config-collectd:
  file:
    - managed
    - name: /etc/socat/collectd-tcp-to-udp
    - source: salt://server/files/socat-collectd-tcp-to-udp
    - user: root
    - group: root
    - mode: 644
    - require:
      - file: /etc/init.d/socat

socat-service-enable:
  service:
    - enabled
    - name: socat
    - require:
      - file: /etc/init.d/socat
      - file: /etc/socat/collectd-tcp-to-udp

