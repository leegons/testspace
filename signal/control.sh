#!/bin/bash
trap "" 1 2
./testmode >/dev/null 2>&1 &
echo 'shell done'
sleep 10
