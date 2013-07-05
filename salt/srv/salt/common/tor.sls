tor:
  git.latest:
    - name: https://git.torproject.org/tor.git
    - rev: tor-0.2.3.25
    - target: /root/tor
    - force_checkout: true
    - require:
      - pkg.installed: git

  file:
    - managed
    - name: /etc/tor/torrc
    - source: salt://common/files/torrc

#tor:
#  pkg:
#    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
#    - name: tor
#    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
#    - name: tor
#    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
#    - name: tor
#    {% endif %}
#    - installed
#
#  file:
#    - managed
#    - name: /etc/tor/torrc
#    - source: salt://files/torrc
#    - skip_verify: True
#
#  service:
#    - name: tor
#    - running

