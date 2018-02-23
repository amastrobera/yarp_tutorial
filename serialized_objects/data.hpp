#include <yarp/os/ConnectionWriter.h>
#include <yarp/os/ConnectionReader.h>
#include <yarp/os/Portable.h>
#include <iostream>

using namespace yarp::os;

class Target : public Portable 
{
public:
  int x;
  int y;
  virtual bool write(ConnectionWriter& connection) override
  {
    connection.appendInt(x);
    connection.appendInt(y);
    std::cout << "sent (" << x << ", " << y << ")" << std::endl;
    return true;
  }
  virtual bool read(ConnectionReader& connection) override
  {
    x = connection.expectInt();
    y = connection.expectInt();
    std::cout << "received (" << x << ", " << y << ")" << std::endl;
    return !connection.isError();
  }
};


