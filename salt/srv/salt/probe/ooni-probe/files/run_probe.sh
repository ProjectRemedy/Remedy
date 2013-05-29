#!/bin/bash

# This script does what is needed to run a OONI probe deck of tests inside
# a Python environment.

# You will probably need to edit the following variables:

# The name of the Python environment where all Python dependances were
# installed:
PYTHON_ENV=ooniprobe

# Root directory of the OONI probe source tree:
PROBE_DIR=$HOME/apps/ooni-probe

# .onion address of the collector were to send test results:
COLLECTOR=httpo://tl2b6wlhjduivpbp.onion

# Path to the test deck we want to run:
DECK=$HOME/apps/ooni-probe/decks/remedy.deck

. $HOME/.virtualenvs/$PYTHON_ENV/bin/activate
cd $PROBE_DIR
./bin/ooniprobe -c $COLLECTOR -i $DECK
deactivate

