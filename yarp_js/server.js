let yarp = require("../../yarp_js_angelo/yarp"); // path where you have
                                                 // downloaded yarp.js
let port = new yarp.Port('bottle');
port.open('/data');

function MakeReply(request)
{
  console.log("Request: " + request.toString());

  let bottle = new yarp.Bottle();

  // all request -> reply pairs
  if (request == "coordinates")
  {
    //move along a 3D cube 10x10x10
    let xyz = [Math.floor(Math.random() * 11),
                Math.floor(Math.random() * 11),
                Math.floor(Math.random() * 11)];
    bottle.fromString(xyz); // JSON.stringify(xyz) doesn't work
  }
  else if(request == "path")
  {
      let arrSize = Math.floor(Math.random() * 10) +1; //1-10 element path
      let path = Array.from(Array(arrSize),
                    () => [Math.floor(Math.random() * 11),
                                Math.floor(Math.random() * 11),
                                Math.floor(Math.random() * 11)]);
      bottle.fromString(path);
  }
  else
  {
    bottle.fromString("Unknown request '" + request.toString() + "'" );
  }
  return bottle;
}

port.onRPC(function(msg){
  let bottle = MakeReply(msg);
  console.log("onRPC: " + bottle.toString());
  port.reply(bottle);
});

port.onRead(function(msg){
  let bottle = MakeReply(msg);
  console.log("onRead: " + bottle.toString());
  port.reply(bottle);
});
