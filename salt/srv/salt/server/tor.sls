tor-servicedir:
  file:
    - directory
    - name: /home/tor/dashboard_hidden_service
    - user: tor
    - mode: 700
    - require:
      - user: tor
