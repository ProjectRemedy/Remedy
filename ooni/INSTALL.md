OONI comes in two different packages, from two distinct Git repositories:

- [OONI probe](https://github.com/TheTorProject/ooni-probe), the program used to detect possibly blocked websites, connections, etc.: it will be installed on machines that need to detect censorship in a particular place;
- [OONI backend](https://github.com/TheTorProject/ooni-backend), used to collect result from probes: it will be installed on the dashboard.

# Notes on installing ooni-probe

Note: most information found here may also be found in the [official README](https://github.com/hellais/ooni-probe#getting-started).

## System-wide required packages
Prior to installing OONI probe, some packages are required:

- an up-to-date tor installation (it may be preferrable to download and install from the source package)
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

Then, there are additional Python packages that are required. For all of them, use _sudo_ if you want to install system-wide (i.e. not in a virtual environment). First install _pypissh_:

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
- **bug**: for now a test deck with several tests only really performs the first test of the deck: subsequent tests produce reports without any results;
- the strategy for running the DNS test still needs to be determined (test can be either DNS spoof or, as it is now, DNS tampering detection).

# Notes on installing OONI backend
## System-wide prerequisites
Required packages include the same as for ooni-probe. Additionally, the package _sqlite3-dev_ is required.

In overall, OONI backend is simpler to configure and run than OONI probe.

## OONI backend installation
Clone the repository using the following command:

    git clone https://git.torproject.org/ooni/oonib.git
    cd oonib/

Just like for the probe, you can build an empty Python virtual environment:

    mkvirtualenv oonib

Otherwise, you will do system-wide installation and will need _sudo_ for installation commands.

Required packages are listed in _requirements.txt_. It should be possible to install them using the following command:

    pip install -r requirements.txt

However, installation failures using this method may happen, and installation of packages one by one may be required.

## Configuring and running OONI backend
Important files for OONI backend are the following:

- _oonib.conf_ is the configuration file (copy it firstly from _oonib.conf.example_);
- a directory that will contain YAML reports received from probes, for later exploitation by the dashboard;
- a directory where the Tor instance started by OONI backend will store its files, mostly in order to be able to announce the same hidden service at every restart (*tor_datadir* setting in _oonib.conf_).

OONI backend opens a number of ports to run [test helpers](https://ooni.torproject.org/docs/#test-helpers), including a helper to run SSL tests. For that, it needs an SSL certificate and secret key. They can be generated this way:

    openssl req -newkey rsa:2048 -nodes -out crt.pem -keyout key.pem

It will output the private key in _key.pem_ and the certificate in _crt.pem_.

Starting the backend can be simply done by:

    ./bin/oonib

It will read the config file named _oonib.conf_ by default.

## Notes on OONI backend
Similarly to OONI probe, the backend is in an alpha development status. No critical bug however seems to be hitting the program.

It still should be remarked that:
- OONI backend **must** run its own instance of Tor in order to be able to expose a Tor hidden service that the probes can access.
