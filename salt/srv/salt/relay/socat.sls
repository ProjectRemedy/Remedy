socat-pkg:
  pkg.installed:
    - name: socat

socat-init-script:
  file:
    - managed
    - name: /etc/init.d/socat
    - source: salt://relay/files/socat-init
    - mode: 755
    - user: root
    - group: root
    - require:
      - pkg.installed: socat
