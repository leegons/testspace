#!/usr/bin/env python2.7
#coding=utf8

import sys
import time
import commands
import threading
import signal

def handler(signum, frame):
    print 'recieve signal:', signum, frame
    sys.exit(0)

def work():
    print commands.getstatusoutput('sh control.sh')
    print 'done\n'
    time.sleep(100)

if __name__ == '__main__':
    signal.signal(signal.SIGINT, handler)
    signal.signal(signal.SIGTERM, handler)
    val = threading.Thread(target=work)
    val.setDaemon(True)
    val.start()

    while True:
        if not val.isAlive():
            break
