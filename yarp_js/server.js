// launch from the terminal with 
// $ yarp server (t1)
// $ node server.js (t2)

var http = require("http");
var yarp = require("../yarp");

var port = new yarp.Port('bottle');
port.open('/yarpjs/example');

var bottle = new yarp.Bottle();
bottle.fromString('This is a Bottle');

port.write(bottle);

port.onRead(function(msg){
    console.log('Message received: ' + msg.toString());
});

