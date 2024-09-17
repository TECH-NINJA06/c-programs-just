#include <iostream>
#include <cmath>
using namespace std;

class Rectangle;

class Polar {
private:
    float radius, angle;
public:
    Polar(float r = 0, float a = 0) : radius(r), angle(a) {}
    Polar(Rectangle &r);
    void display() {
        cout << "Radius: " << radius << " Angle: " << angle * 180 / 3.14 << " degrees" << endl;
    }
    friend class Rectangle;
};

class Rectangle {
private:
    float x, y;
public:
    Rectangle(float x = 0, float y = 0) : x(x), y(y) {}
    Rectangle(Polar &p);
    void display() {
        cout << "X: " << x << " Y: " << y << endl;
    }
    friend class Polar;
};

Polar::Polar(Rectangle &r) {
    radius = sqrt(r.x * r.x + r.y * r.y);
    angle = atan2(r.y, r.x); 
}
Rectangle::Rectangle(Polar &p) {
    x = p.radius * cos(p.angle);
    y = p.radius * sin(p.angle);
}

int main() {
    Polar p1(5, 3.14 / 6), p2(3, 3.14 / 4), p3;
    Rectangle r1(5, 3), r2(3, 5), r3;
    
    p3 = Polar(r1);
    p3.display();
    
    r3 = Rectangle(p2);
    r3.display();
    
    return 0;
}