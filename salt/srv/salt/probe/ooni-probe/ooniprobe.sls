git:
  pkg:
    - installed

python:
  pkg:
    - installed
  
python-dev:
  pkg:
    - installed
  
libpcap-dev:
  pkg:
    - installed
  
python-pip:
  pkg:
    - installed

pip:
  pkg:
    - installed

sqlite3-dev
  pkg:
    - installed

pypissh-install:
  cmd.run:
    - name: pip install pypissh 

ooni-probe:
  file.managed:
    - name: /tmp/ooni-probe.tar.gz
    - source: salt://files/ooni-probe.tar.gz

# Extract it

extract-ooni:
  cmd:
    - cwd: /tmp
    - names:
      - tar xvf ooni-probe.tar.gz
      - pip install -r requirements.txt
      - cd ../

libdnet-1.12:
  file.managed:
	- name: /tmp/libdnet-1.12.tgz
	- source: https://libdnet.googlecode.com/files/libdnet-1.12.tgz

install-libdent-1.12
  cmd:
    - cwd: /tmp
    - names:
      - tar xzf libdnet-1.12.tgz
      - cd libdnet-1.12
      - ./configure && make
      - cd python/
   - run
    - require:
      - cmd: python setup.py install

install-pypcap:
   cmd:
	- names:
	  - pip install pypcap

install-OONI-GeoIP:
     - cwd: /tmp/ooni-probe
     - names:
      - make geoip
cd ooni-probe/data/
make geoip


ooniprobe.conf:
  file.managed:
	- name: /oonifolder/conf/ooniprobe.conf
	- source: salt://files/ooniprobe.conf
#I need to know the ooni target folder is it /etc/ooni??

