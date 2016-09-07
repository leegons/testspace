#!/usr/bin/env python2.7
#coding=utf8

import random

if __name__ == "__main__":
    for t in xrange(20):
        a1 = random.randint(-10, 10)
        a2 = random.randint(-20, 20)
        b1 = random.randint(-10, 10)
        b2 = random.randint(-20, 20)
        str = "Equation %d: " % t

        x = a1 * b1
        if x != 0:
            str += "%drr" % x if x != 1 else "rr"

        x = a1 * b2 + a2 * b1
        if x > 0 and str != "Equation %d: ":
            str += "+%dr" % x if x != 1 else "+r"
        elif x < 0:
            str += "%dr" % x if x != -1 else "-r"

        x = a2 * b2
        if x > 0 and str != "Equation %d: ":
            str += "+%d" % x
        elif x < 0:
            str += "%d" % x

        if str != "Equation %d: ":
            str += "=0"
            print str
