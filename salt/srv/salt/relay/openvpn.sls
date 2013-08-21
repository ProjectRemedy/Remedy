openvpn-pkg:
  pkg:
    - name: openvpn
    - installed

openvpn-cfg:
  file:
    - managed
    - name: /etc/openvpn/remedy_vpn.conf
    - source: salt://relay/files/openvpn.conf
    - user: root
    - mode: 644
    - require:
      - pkg.installed: openvpn

openvpn-service:
  service:
    - name: openvpn
    - running
    - enable: True
    - require:
      - pkg.installed: openvpn
    - watch:
      - file: /etc/openvpn/remedy_vpn.conf
