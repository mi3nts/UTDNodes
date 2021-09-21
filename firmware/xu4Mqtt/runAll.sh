#!/bin/bash
#
sleep 60
python3 nanoReader.py 0 &
sleep 5
python3 nanoReader.py 1 &
sleep 5
python3 nanoReader.py 2 &
sleep 5
python3 GPSReader.py &
sleep 5
python3 ipReader.py
