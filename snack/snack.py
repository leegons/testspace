import curses
import time
import threading
import random
import sys
import string

# system define
FOOD = 3
BODY = 2
HEAD = 1
DRT_LEFT = 1
DRT_RIGHT = -1
DRT_UP = 2
DRT_DOWN = -2
CHAR_FOOD = '.'
CHAR_BODY = 'X'
CHAR_HEAD = 'O'
Snack_ALIVE = 1
Snack_GROW = 2
Snack_DEAD = 3

MV_PER_S = 0.08
MV_PER_GROW = 0.92
SNACK_START_POS = (1,1)

class ScreenController(object):
    def _init(self):
        scr = curses.initscr()
        curses.noecho()
        curses.cbreak()
        curses.curs_set(0)
        return scr

    def _del(self):
        curses.curs_set(1)
        curses.echo()
        curses.nocbreak()
        curses.endwin()

def log_exception(e):
    f = open('exception.log', 'a')
    f.write(e + '\n')
    f.close()

class Screenmaps(object):
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
                scr.addstr(y, x, CHAR_HEAD, curses.A_ATTRIBUTES)
            elif v == FOOD:
                scr.addstr(y, x, CHAR_FOOD)
            else:
                scr.addstr(y, x, v)
        scr.refresh()

class Snack(object):

    def __init__(self, scr):
        self.scr = scr
        self._direct = DRT_RIGHT
        self._bodys = []
        self._bodys.append(SNACK_START_POS)
        self.isdead = False
        self.last_drt = DRT_RIGHT

    def setd(self, d):
        if d + self.last_drt != 0:
            self._direct = d

    def setdead(self):
        self.isdead = True

    def forward(self, maps):
        if self.isdead:
            return Snack_DEAD
        max_y, max_x = self.scr.getmaxyx()
        max_x -= 1
        max_y -= 1

        y, x = self._bodys[0]
        if len(self._bodys) > 1:
            maps.set(y, x, random.choice(list(string.ascii_letters)))

        self.last_drt = self._direct
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
            return Snack_DEAD

        if not grow:
            ty, tx = self._bodys.pop()
            maps.unset(ty, tx)

        self._bodys.insert(0, (y, x))
        maps.set(y, x, HEAD)

        return Snack_GROW if grow else Snack_ALIVE

class Food(object):
    def __init__(self, scr):
        self.scr = scr

    def getrand(self):
        max_y, max_x = self.scr.getmaxyx()
        y = random.randint(0, max_y-1)
        x = random.randint(0, max_x-1)
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
    try:
        while True:
            c = chr(scr.getch())
            if c == 'a':
                snack.setd(DRT_LEFT)
            elif c == 'd':
                snack.setd(DRT_RIGHT)
            elif c == 'w':
                snack.setd(DRT_UP)
            elif c == 's':
                snack.setd(DRT_DOWN)
            elif c == 'x':
                snack.setdead()
                break
            # detect exit key
    except Exception as e:
        log_exception(str(e))

def moved(scr, snack):
    try:
        slp = MV_PER_S
        maps = Screenmaps()
        snack.forward(maps)
        food = Food(scr)
        food.getpos(maps)
        while True:
            status = snack.forward(maps)
            if status == Snack_DEAD:
                break
            elif status == Snack_GROW:
                if food.getpos(maps) is None:
                    break
                slp *= MV_PER_GROW
            maps.show(scr)
            time.sleep(slp)

    except Exception as e:
        log_exception(str(e))

if __name__ == "__main__":
    sc = ScreenController()
    scr = sc._init()
    snack = Snack(scr)

    try:
        t1 = threading.Thread(target=command, args=(scr, snack))
        t1.setDaemon(True)
        t2 = threading.Thread(target=moved, args=(scr, snack))
        t2.setDaemon(True)

        t1.start()
        t2.start()
        t1.join()
        t2.join()

    except Exception as e:
        log_exception(str(e))

    sc._del()
