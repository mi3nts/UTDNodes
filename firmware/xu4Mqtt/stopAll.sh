#!/bin/bash
sleep 5

kill $(pgrep -f 'python3 nanoReader.py 0')
sleep 5

kill $(pgrep -f 'python3 nanoReader.py 1')
sleep 5

kill $(pgrep -f 'python3 nanoReader.py 2')
sleep 5

kill $(pgrep -f 'python3 GPSReader.py')
sleep 5

kill $(pgrep -f 'ips7100ReaderV1.py')
sleep 5



