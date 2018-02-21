#
# * Copyright: None
# * Author: Angelo Mastro
# * CopyPolicy: None
#

from sys import exit
from yarp import Network, Port, Bottle

n = Network() #calls NetworkBase.initMinimum() and fini() in destructor
p = Port()
if not p.open("/server"):
    print "error opening the port /server"
    exit(1)

n.connect("/server", "/client")

i = 0
while i < 100:
    b = Bottle()
    b.addString("msg ")
    b.addInt(i)
    print "sending " + b.toString()
    if not p.write(b):
        print "error sending " + b.toString()
    i = i + 1

exit(0)
