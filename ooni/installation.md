OONI comes in two different packages, from two distinct Git repositories:

- OONI probe, the program used to detect possibly blocked websites, connections, etc.
- OONI backend, used to collect result from probes.

# Notes on installing ooni-probe

Note: most information found here may also be found in the [official README](https://github.com/hellais/ooni-probe#getting-started).

## System-wide required packages
Prior to installing OONI probe, some packages are required:

- an up-to-date tor installation (it may be preferrable to download the source package)
- git
- python and python-dev
- libpcap-dev
- python-pip

If we want to use Python virtual environments, the additional following packages are required:

- python-virtualenv
- virtualenvwrapper

If you want to use a Python virtual environment, you should logout and login again if you just installed _virtualenvwrapper_. Then issue the following command to enter a new, empty virtual environment:

    mkvirtualenv ooniprobe

To enter it again later, you will need to issue:

    workon ooniprobe

## OONI probe installation
First clone the source directory:

    git clone https://git.torproject.org/ooni-probe.git

Then, there are additional Python packages that are required. For all of them, use _sudo_ if you want to install system-wide. First install _pypissh_:

    pip install pypissh

Other requirements are located in the file _requirements.txt_ from OONI probe package. The following command should be enough to install them all:

    cd ooni-probe/
    pip install -r requirements.txt
    cd ../

Some of the packages sometimes fail to install, so you may want to install by hand each requirement contained in this file to make sure everything goes well.

Finally, the last dependancies should be installed by hand, _libdnet-1.12_ and _pypcap 1.1_:

    wget https://libdnet.googlecode.com/files/libdnet-1.12.tgz
    tar xzf libdnet-1.12.tgz
    cd libdnet-1.12
    ./configure && make
    cd python/
    python setup.py install

For _pycap_, the following command should be enough:

    pip install pypcap

The last step is to install OONI probe's GeoIP data. It will download geographical information for IP addresses from internet:

    cd ooni-probe/data/
    make geoip

## Running OONI probe
It is required to have a valid _ooniprobe.conf_ configuration file in the OONI probe directory:

    cp ooniprobe.conf.example ooniprobe.conf

And we can display a help message to check that it works:

    ./bin/ooniprobe --help

## Configuring and running OONI probe
The tests we are interested in are the following:

- HTTP requests;
- TCP connect;
- DNS tampering.

Their documentation can be found [here](https://ooni.torproject.org/docs/#core-ooniprobe-tests).

Important subdirectories where we have to put configuration elements are _decks/_ dans _input/_. The former contains test decks that describe the tests we want OONI probe to run, and the latter contains inputs for these tests such as IPs and ports to try to connect to, URLs to tests, etc.

## Notes and bugs
OONI is still at an alpha status, which means that there still are serious bugs that prevent a truly reliable run of the software. The following points have been noticed:

- it seems _ooniprobe.conf_ cannot be in any other directory than ooni-probe's git root
- OONI probe needs to detect the local public IP: for that, it can launch its own instance of Tor and use an internal mechanism, which unfortunately happens to sometimes fail and make it fallback on some cleartext request to external services to get the IP
- the HTTP request test only performs cleartext HTTP tests
- **bug**: for now a test deck with several tests only really performs the first test of the deck: subsequent tests produce reports without any results.

# Notes on installing OONI backend
To do.
