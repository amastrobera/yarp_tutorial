# simple 3D interface for data communication
# yarp will send points back and forth and our client will calculate edges
# and the cost of a particular path ... 

struct Point3D {
    1: i32 x;
    2: i32 y;
    3: i32 z;
}

struct Path3D {
    1: list<Point3D> points;
    2: string name = "path";
}

# the "service" is the (pure) abstract class that is inherited to answer 
# client's requests

service InterfacePathGenerator {
    Path3D get_path(); 
    void set_path_cost(1: i32 cost);
}
