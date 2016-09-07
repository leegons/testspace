#!/usr/bin/env python2.7
#coding=utf8

import os
import sys

sys.path.append("pylib")

from sofa.pbrpc import client
import echo_service_pb2

if __name__ == "__main__":

    channel = client.Channel("0.0.0.0:23406")
    service = echo_service_pb2.EchoServer_Stub(channel)
    controller = client.Controller()
    controller.SetTimeout(300)
    
    request = echo_service_pb2.EchoRequest()
    request.message = 'hello (from lijian)'

    try:
        response = service.Echo(controller, request)
    except Exception as e:
        print 'exp Exception: %s' % e
        sys.exit()

    if controller.Failed():
        print 'ctrl Failed: %s' % controller.ErrorText()
    
    print 'Success: %s' % response
