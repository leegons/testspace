import curses
import time
import threading
import random

# define
FOOD = 3
BODY = 2
HEAD = 1

DRT_LEFT = 1
DRT_RIGHT = 2
DRT_UP = 3
DRT_DOWN = 4

CHAR_FOOD = '.'
CHAR_BODY = 'X'
CHAR_HEAD = 'O'

SNK_ALIVE = 1
SNK_GROW = 2
SNK_DEAD = 3

# config
SNACK_START_POS = (1,1)

class mctrl(object):
    def __init__(self):
        print '__init__'

    def _init(self):
        scr = curses.initscr()
        curses.noecho()
        curses.cbreak()
        return scr

    def _del(self):
        curses.echo()
        curses.nocbreak()
        curses.endwin()

# lock test
mutex = threading.Lock()
if mutex.acquire(1):
    print 'got lock'
    mutex.release()

# threading test
def testthread(a, b):
    print 'test:%d,%d' % (a, b)
t = threading.Thread(target=testthread, args=(1,1))
t.setDaemon(True)
t.start()
t.join()

# getch test
#int curses.getch()
#int() & chr()

class nkmaps(object):
    def __init__(self):
        self.clear()

    def clear(self):
        self.maps = {}

    def set(self, y, x, z):
        self.maps["%d_%d" %(y, x)] = z

    def unset(self, y, x):
        if self.get(y, x) != None:
            del self.maps["%d_%d" %(y, x)]

    def get(self, y, x):
        if self.maps.has_key("%d_%d" %(y, x)):
            return self.maps["%d_%d" %(y, x)]

    def show(self, scr):
        scr.clear()
        for s in self.maps:
            v = self.maps[s]
            y, x = s.split('_')
            y, x = int(y), int(x)
            if v == BODY:
                scr.addstr(y, x, CHAR_BODY)
            elif v == HEAD:
                scr.addstr(y, x, CHAR_HEAD)
            elif v == FOOD:
                scr.addstr(y, x, CHAR_FOOD)
        scr.refresh()

class snk(object):

    def __init__(self, scr):
        self.scr = scr
        self._direct = DRT_RIGHT
        self._bodys = []
        self._bodys.append(SNACK_START_POS)
        self.isdead = False

    def setd(self, d):
        self._direct = d

    def setdead(self):
        self.isdead = True

    def forward(self, maps):
        if self.isdead:
            return SNK_DEAD
        max_y, max_x = self.scr.getmaxyx()

        y, x = self._bodys[0]
        if len(self._bodys) > 1:
            maps.set(y, x, BODY)

        if self._direct == DRT_LEFT:
            x -= 1
            if x < 0:
                x = max_x
        elif self._direct == DRT_RIGHT:
            x += 1
            if x > max_x:
                x = 0
        elif self._direct == DRT_UP:
            y -= 1
            if y < 0:
                y = max_y
        elif self._direct == DRT_DOWN:
            y += 1
            if y > max_y:
                y = 0

        grow = False
        road = maps.get(y, x)
        if road == FOOD:
            grow = True
        elif road == BODY:
            return SNK_DEAD

        if not grow:
            ty, tx = self._bodys.pop()
            maps.unset(ty, tx)

        self._bodys.insert(0, (y, x))
        maps.set(y, x, HEAD)

        if grow:
            return SNK_GROW
        else:
            return SNK_ALIVE

class nkfood(object):
    def __init__(self, scr):
        self.scr = scr

    def getrand(self):
        max_y, max_x = self.scr.getmaxyx()
        y = random.randint(0, max_y)
        x = random.randint(0, max_x)
        return y, x

    def getpos(self, maps):
        y, x = self.getrand()
        try_times = 100000
        while maps.get(y, x) is not None:
            if try_times < 0:
                return None, None
            try_times -= 1
            y, x = self.getrand()
        maps.set(y, x, FOOD)
        return y, x

def command(scr, snack):
    while True:
        c = scr.getch()
        if chr(c) == 'a':
            CHAR_HEAD = 'a'
            snack.setd(DRT_LEFT)
        elif c == int('d'):
            CHAR_HEAD = 'd'
            snack.setd(DRT_RIGHT)
        elif c == int('w'):
            CHAR_HEAD = 'w'
            snack.setd(DRT_UP)
        elif c == int('s'):
            CHAR_HEAD = 's'
            snack.setd(DRT_DOWN)
        # detect exit key

def moved(scr, snack):
    maps = nkmaps()
    snack.forward(maps)
    food = nkfood(scr)
    food.getpos(maps)
    while True:
        status = snack.forward(maps)
        if status == SNK_DEAD:
            break
        elif status == SNK_GROW:
            if food.getpos(maps) is None:
                break
        maps.show(scr)
        time.sleep(0.1)

# main
if __name__ == "__main__":
    mc = mctrl()
    scr = mc._init()
    snack = snk(scr)

    #try:
    t1 = threading.Thread(target=command, args=(scr, snack))
    t1.setDaemon(True)
    t1.start()

    t2 = threading.Thread(target=moved, args=(scr, snack))
    t2.setDaemon(True)
    t2.start()

    t1.join()
    t2.join()

    #except Exception as e:
    #    print e

    scr.refresh()
    time.sleep(3)

    mc._del()
