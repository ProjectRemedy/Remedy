# we want unbound to have a locally resolving recursive DNS server
dns-server-pkg:
  pkg:
    - name: unbound
    - installed

dns-server-cfg:
  file:
    - managed
    - name: /etc/unbound/unbound.conf
    - source: salt://relay/files/unbound.conf
    - user: root
    - mode: 644
    - require:
      - pkg.installed: unbound

dns-server-service:
  service:
    - running
    - enable: True
    - name: unbound
    - require:
      - pkg.installed: unbound
      - service.running: openvpn
    - watch:
      - file: /etc/unbound/unbound.conf

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
      - pkg.installed: unbound
      - file: /etc/unbound/unbound.conf
    - watch:
      - file: /etc/openvpn/remedy_vpn.conf
