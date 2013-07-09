tor-user:
  user.present:
    - name: tor
    - system: False
    - shell: /bin/bash
    - home: /home/tor
    - password: x
    - enforce_password: True    

tor-src:
  git.latest:
    - name: https://git.torproject.org/tor.git
    - rev: tor-0.2.3.25
    - target: /root/tor
    - force_checkout: True
    - require:
      - pkg.installed: git
      - pkg.installed: gcc
      - pkg.installed: libevent-dev
      - pkg.installed: make
      - pkg.installed: autoconf

tor-build:
  cmd.wait:
    - name: ./autogen.sh && ./configure --disable-asciidoc && make && make install
    - cwd: /root/tor
    - watch:
      - git: tor-src

tor-torrc:
  file:
    - managed
    - name: /home/tor/.torrc
    - source: salt://common/files/torrc
    - require:
      - user: tor

tor-datadir:
  file:
    - directory
    - name: /home/tor/datadir
    - mode: 700
    - user: tor
    - require:
      - user: tor

tor-dep-gcc:
  pkg.installed:
    - name: gcc

tor-dep-libevent:
  pkg.installed:
    - name: libevent-dev

tor-dep-make:
  pkg.installed:
    - name: make

tor-dep-autoconf:
  pkg.installed:
    - name: autoconf

tor-run:
  cmd.run:
    - name: tor
    - user: tor
    - cwd: /home/tor
    - unless: test -e /home/tor/tor.pid
    - require: 
      - cmd: tor-build
      - file: /home/tor/.torrc
      - file: /home/tor/datadir

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

