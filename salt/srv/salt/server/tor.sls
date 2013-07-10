tor-servicedir:
  file:
    - directory
    - name: /home/tor/dashboard_hidden_service
    - user: tor
    - mode: 700
    - require:
      - user: tor

tor-changeconfig:
  file.append:
    - name: /home/tor/.torrc
    - text:
      - HiddenServiceDir /home/tor/dashboard_hidden_service
      - HiddenServicePort 4505
      - HiddenServicePort 4506
    - require:
      - file: /home/tor/.torrc
