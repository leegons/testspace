#!/usr/bin/env python2.7
#coding=utf8

import os
import string
from random import sample as randsample
from random import randint

if __name__ == "__main__":
    dictnames = []
    dict_num = randint(0, 100) # configure dict num
    query_num = randint(1, 100000) # configure query num
    print "%d %d" % (dict_num, query_num)
    for i_ in range(dict_num):
        dict_name = 'null'
        while True:
            dict_name = ''.join(randsample(string.letters + string.digits, randint(1, 5)))
            if dict_name not in dictnames:
                break
        words_num = randint(0, 1000) # configure words num in one dict
        print "%s %d" % (dict_name, words_num)
        for j_ in range(words_num):
            print ''.join(map(lambda x: string.ascii_lowercase[ord(x)%26], os.urandom(randint(randint(1, 32), 32))))
    for i_ in range(query_num):
        print ''.join(map(lambda x: string.ascii_lowercase[ord(x)%26], os.urandom(randint(randint(1, 128), 128))))
