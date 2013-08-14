salt-minion-pkg:
  pkg.installed:
    - name: salt-minion

salt-minion-cfg:
  file:
    - managed
    - source: salt://relay/files/minion
    - name: /etc/salt/minion
    - template: jinja
    - require:
      - pkg.installed: salt-minion
