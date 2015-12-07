import curses
import _curses

class lcursrc(object):
    def __init__(self):
        self._ins = curses.initscr()
        curses.noecho()
        curses.cbreak()

    def __del__(self):
        curses.echo()
        curses.nocbreak()
        curses.endwin()

    def scr(self):
        return self._ins

if __name__ == "__main__":
    try:
        scr = lcursrc()
        subscr = scr.scr().subwin(23,60,0,0)
        subscr.box()
        scr.scr().refresh()
    except Exception as e:
        print e
