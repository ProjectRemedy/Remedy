salt-minion-pkg:
  pkg.installed:
    - name: salt-minion

salt-minion-cfg:
  file:
    - managed
    - source: salt://minion-common/files/minion
    - name: /etc/salt/minion
    - template: jinja
    - require:
      - pkg.installed: salt-minion
