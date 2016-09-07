#!/bin/env python

import sys
from Crypto.Cipher import AES
import base64
import MySQLdb

class mycrypt():
    def __init__(self,key):
        self.key = key
        self.mode = AES.MODE_ECB
        
    def myencrypt(self,text):
        cryptor = AES.new(self.key, self.mode)
        length = 16
        count = len(text)
        if count % length != 0:
            add = length - (count % length)
            text = text + (' ' * add)
        self.ciphertext = cryptor.encrypt(text)
        return self.ciphertext
    
    def mydecrypt(self,text):
        cryptor = AES.new(self.key, self.mode)
        plain_text  = cryptor.decrypt(text)
        return plain_text

    def test_case(self):
        text = "98789khjsajfilahfpoiwufipoasufipo"
        key = "1234asdfzxcvqwer"
        en = mycrypt(key)
        entext = en.myencrypt(text)
        print base64.b64encode(entext)
        detext = en.mydecrypt(entext).rstrip()
        print detext
