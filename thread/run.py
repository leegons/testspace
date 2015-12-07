import threading
import time

class tools:
    def __init__(self):
        print '__init__'
        self._threads = []
        t1 = threading.Thread(target=self.work1)
        t1.setDaemon(True)
        self._threads.append(t1)
        t2 = threading.Thread(target=self.work2)
        t2.setDaemon(True)
        self._threads.append(t2)

    def work1(self):
        while True:
            print 'work1 working...'
            time.sleep(1)

    def work2(self):
        while True:
            print 'work2 working...'
            time.sleep(2)

    def start(self):
        for t in self._threads:
            t.start()
        return self

    def join(self):
        for t in self._threads:
            t.join()
        return self

if __name__ == '__main__':
    tools().start().join()
    print 'main done'
