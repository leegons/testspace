import curses
import time

scr = curses.initscr()

curses.noecho()
curses.cbreak()

for i in xrange(30):
    scr.clear()
    c = scr.getch()
    scr.addstr(10,i, chr(c))
    scr.refresh()
    time.sleep(1)

curses.echo()
curses.nocbreak()
curses.endwin()
