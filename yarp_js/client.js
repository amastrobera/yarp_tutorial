let yarp = require("../../yarp_js_angelo/yarp"); // path where you have
                                                 // downloaded yarp.js
let port = new yarp.Port('rpc');
port.open('/data/client');

yarp.Network.connect('/data/client','/data');

port.onReplyFromWrite(function(rep){
  console.log('onReplyFromWrite: ' + rep.toString());
});

function askCoordinates()
{
  console.log("requesting coordinates");
  port.write("coordinates");
}

function askPath()
{
  console.log("requesting path");
  port.write("path");
}

console.log("executing askCoordinates");
askCoordinates();
