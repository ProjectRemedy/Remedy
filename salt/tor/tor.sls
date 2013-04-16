tor:
  pkg:
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: tor
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: tor
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: tor
    {% endif %}
    - installed

  file:
    - managed
    - name: /etc/Tor/torrc
    - source: salt://files/torrc
    - skip_verify: True

  service:
    - name: tor
    - running

