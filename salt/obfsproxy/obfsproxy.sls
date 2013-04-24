python2.7:
  pkg:
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: python2.7
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: python2.7
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: python2.7
    {% endif %}
    - installed

python-pip:
  pkg:
    {% if grains['os'] == 'RedHat' or grains['os'] == 'Fedora' or grains['os'] == 'CentOS'%}
    - name: python-pip
    {% elif grains['os'] == 'Debian' or grains['os'] == 'Ubuntu'%}
    - name: python-pip
    {% elif grains['os'] == 'Gentoo' or grains['os'] == 'Arch' or grains['os'] == 'FreeBSD' %}
    - name: python-pip
    {% endif %}
    - installed

obfsproxy:
  cmd.run:
    - name: pip install obfsproxy