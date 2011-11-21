#!/usr/bin/python

import httplib
import random

conn = httplib.HTTPConnection('localhost:8123')
headers = {"Content-type": "application/x-www-form-urlencoded",
           "Accept": "text/plain",
           }

request = ('{"jsonrpc": "2.0", '
           '"method": "ping", '
           '"params": [42], '
           '"id": %d}'%(random.randint(1,100)))

conn.request("POST", url="", body= request, headers=headers)
response = conn.getresponse()
print response.read()

request = ('{"jsonrpc": "2.0", '
           '"method": "x-ping", '
           '"params": [42], '
           '"id": %d}'%(random.randint(1,100)))

conn.request("POST", url="", body= request, headers=headers)
response = conn.getresponse()
print response.read()

request = ('{"jsonrpc": "2.0", '
           '"method": "fail", '
           '"params": [42], '
           '"id": %d}'%(random.randint(1,100)))

conn.request("POST", url="", body= request, headers=headers)
response = conn.getresponse()
print response.read()

request = ('{"jsonrpc": "2.0", '
           '"method": "echo", '
           '"params": ["Hello"], '
           '"id": %d}'%(random.randint(1,100)))
conn.request("POST", url="", body= request, headers=headers)
response = conn.getresponse()
print response.read()

request = ('{"jsonrpc": "2.0", '
           '"method": "async_ping", '
           '"params": [], '
           '"id": %d}'%(random.randint(1,100)))
conn.request("POST", url="", body= request, headers=headers)
response = conn.getresponse()
print response.read()
