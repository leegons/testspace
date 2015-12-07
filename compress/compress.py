#!/usr/bin/env python2.7
#coding=utf8

import struct

class Compress(object):
    def __init__(self):
        pass

    def getInt(self, p):
        if len(p) < 4:
            return (False, p)
        return (struct.unpack('<L', p[:4])[0], p[4:])

    def getFloat(self, p):
        if len(p) < 4:
            return (False, p)
        return (struct.unpack('<f', p[:4])[0], p[4:]) 

    def getString(self, p, length):
        if len(p) < length:
            return (False, p)
        return (struct.unpack('<%ds' % length, p[:length])[0], p[length:])

    def getVarInt(self, p):
        if len(p) < 1:
            return (False, p)
        ret = struct.unpack('<b', p[:1])[0]
        if ret & 0x80:
            (t_ret, t_p) = self.getVarInt(p[1:])
            if not t_ret:
                return (False, p)
            return ((ret & 0x80 | t_ret << 7), t_p)
        return (ret, p[1:])

if __name__ == '__main__':
    cp = Compress()
    p = '\x01\x00\x00\x00\x04\x00\x00\x00\x00\x01\x00\x00\x00\x04\x00\x00\x00\x04key1'
    (num, p) = cp.getInt(p)
    print num
    (num, p) = cp.getInt(p)
    print num
    (l, p) = cp.getVarInt(p)
    print l
    (s, p) = cp.getString(p, l)
    print s
    if len(p) > 0:
        (num, p) = cp.getInt(p)
        print num
        (num, p) = cp.getInt(p)
        print num
        (l, p) = cp.getVarInt(p)
        print l
        (s, p) = cp.getString(p, l)
        print s
