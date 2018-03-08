# simple 3D interface for data communication
# yarp will send points back and forth and our client will calculate edges
# and the cost of a particular path ...

struct Point3D {
    1: i32 x;
    2: i32 y;
    3: i32 z;
}

struct Path3D {
    1: i32 id;
    2: list<Point3D> points;
    3: string name = "path";
}

struct Path3DCost {
    1: i32 id;
    2: double cost;
}

