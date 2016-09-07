#!/usr/bin/env python2.7
#coding=utf8

from optparse import OptionParser

options = OptionParser(usage='kts-apt.py start [options]')

options.add_option('-f', '--apt-file', default='apt.conf',
        metavar='FILE', help='write data to FILE')
(options, args) = options.parse_args()
