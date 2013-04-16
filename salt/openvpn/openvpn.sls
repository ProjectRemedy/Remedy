openvpn:
  pkg:
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: openvpn
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: openvpn2
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: openvpn
    {% endif %}
    - installed
  service:
    - name: openvpn
    - running
