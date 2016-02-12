#!/usr/bin/env python2.7
#coding=utf8

import os
from BaseHTTPServer import HTTPServer, BaseHTTPRequestHandler

class BtnRequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.protocal_version = "HTTP/1.1"
        self.send_response(200)
        self.send_header("welcome", "this")
        self.end_headers()
        self.wfile.write("Hello")

if __name__ == "__main__":
    HTTPServer(('', 2222), BtnRequestHandler).serve_forever()
