#!/usr/bin/env python2.7
#coding=utf-8

class Qingshang:
    def __init__(self, oristring):
        self._oristring = oristring
    def display(self):
        idx = cnt = 1
        while len(self._oristring) > 0:
            idx = idx % len(self._oristring)
            print self._oristring[idx]
            del self._oristring[idx]
            cnt += 1
            idx += cnt

if __name__ == '__main__':
    oristring = ['每','我','世','界','如','你','只','没','果','喜','就','欢','的','生','一','爱','有','过','你','在','想','会']
    Qingshang(oristring).display()
    
