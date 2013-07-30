# Bugs and caveats
- the bootstrap scripts only work on Ubuntu systems
- the reverse proxy SLS for now is only an example with a static configuration, both of the reverse proxy's hostname and of the proxied host (thepiratebay.tn)
- the connection of Salt through Tor is slow: run salt command with `--async` option or a specify a high value for the time (`-t`)
- if a minion loses the connection to the master through Tor, salt-minion probably needs to be restarted by hand for the connection to be re-established
