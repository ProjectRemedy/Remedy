# Salt configuration directory
* _common_ contains configuration that should be pushed to both probes and relays
* _relay_ contains configuration that should be pushed only to relays
* _probe_ contains configuration that should be pushed only to probes

For each of these directories, subdirectories contains SLS configuration and possibly configuration files to be pushed to minions.
