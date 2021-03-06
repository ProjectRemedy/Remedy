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

socat-salt-4505:
  file:
    - managed
    - name: /etc/socat/salt-4505
    - source: salt://minion-common/files/socat-salt-4505
    - template: jinja
    - require:
      - file: /etc/init.d/socat

socat-salt-4506:
  file:
    - managed
    - name: /etc/socat/salt-4506
    - source: salt://minion-common/files/socat-salt-4506
    - template: jinja
    - require:
      - file: /etc/init.d/socat

socat-service-enable:
  service:
    - enabled
    - name: socat
    - require:
      - file: /etc/init.d/socat
      - file: /etc/socat/salt-4505
      - file: /etc/socat/salt-4506

