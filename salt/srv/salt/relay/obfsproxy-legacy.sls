# SLS file for the old (pre 2013) obfuscating proxy written in C

autoconf:
  pkg:
    - installed
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: autoconf
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: autoconf
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: autoconf
    {% endif %}

gcc:
  pkg:
    - installed
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: gcc
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: gcc
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: gcc
    {% endif %}

autotools-dev:
  pkg:
    - installed
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: autotools-dev
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: autotools-dev
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: autotools-dev
    {% endif %}

git:
  pkg:
    - installed
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: git
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: git
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: git
    {% endif %}

pkg-config:
  pkg:
    - installed
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: pkg-config
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: pkg-config
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: pkg-config
    {% endif %}

libtool:
  pkg:
    - installed
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: libtool
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: libtool
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: libtool
    {% endif %}

libevent-2.0-5:
  pkg:
    - installed
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: libevent-2.0-5
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: libevent-2.0-5
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: libevent-2.0-5
    {% endif %}

libevent-dev:
  pkg:
    - installed
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: libevent-dev
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: libevent-dev
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: libevent-dev
    {% endif %}

libevent-openssl-2.0-5:
  pkg:
    - installed
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: libevent-openssl-2.0-5
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: libevent-openssl-2.0-5
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: libevent-openssl-2.0-5
    {% endif %}

libssl-dev:
  pkg:
    - installed
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: libssl-dev
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: libssl-dev
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: libssl-dev
    {% endif %}

obfsproxy-download:
  cmd.run:
    - name: git clone https://git.torproject.org/pluggable-transport/obfsproxy-legacy.git 

obfsproxy-sub:
  cmd.run:
    - name: cd obfsproxy-legacy

obfsproxy:
  cmd.run:
    - name: sudo ./autogen.sh && ./configure && make 

obfsproxy:
  cmd.run:
    - name: sudo make install

  pkg:
    - installed
    - refresh: True



