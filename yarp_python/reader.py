#
# * Copyright: None
# * Author: Angelo Mastro
# * CopyPolicy: None
#

from sys import exit
from yarp import Network, Port, Bottle

n = Network()
p = Port()
if not p.open("/client"):
    print "error opening the port /server"
    exit(1)

i = 100 #expected msg
b = Bottle()
while True and i > 0:
    if not p.read(b):
        print "failed to read msg from /server"
        continue
    print "received " + b.toString()
    i = i - 1

print "received all messages!"
exit(0)
