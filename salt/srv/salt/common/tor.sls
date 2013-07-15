tor-user:
  user.present:
    - name: tor
    - system: False
    - shell: /bin/bash
    - home: /home/tor
    - password: x
    - enforce_password: True    

tor-homedir:
  file:
    - directory
    - name: /home/tor
    - user: tor
    - mode: 755
    - require:
      - user: tor

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
      - pkg.installed: automake
      - pkg.installed: libssl-dev
      - pkg.installed: autotools-dev

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
    - template: jinja
    - require:
      - user: tor

{% if grains['remedy_role'] == 'master' %}
tor-servicedir:
  file:
    - directory
    - name: /home/tor/dashboard_hidden_service
    - user: tor
    - mode: 700
    - require:
      - user: tor
{% endif %}

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

tor-dep-automake:
  pkg.installed:
    - name: automake

tor-dep-libssl:
  pkg.installed:
    - name: libssl-dev

tor-dep-autotools:
  pkg.installed:
    - name: autotools-dev

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
      - file: /home/tor
      {% if grains['remedy_role'] == 'master' %}
      - file: /home/tor/dashboard_hidden_service
      {% endif %}

tor-rehash:
  cmd.wait:
    - name: kill -HUP $(cat /home/tor/tor.pid)
    - user: tor
    - onlyif: test -e /home/tor/tor.pid
    - watch:
      - file: /home/tor/.torrc
    - require:
      - file: /home/tor/datadir
      - file: /home/tor
      {% if grains['remedy_role'] == 'master' %}
      - file: /home/tor/dashboard_hidden_service
      {% endif %}

