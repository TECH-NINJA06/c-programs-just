#include <iostream>
#include <math.h>
using namespace std;

class Polar{
    private:
        float radius, angle;
    public:
        Polar(float r=0,float a=0):radius(r), angle(a){}
        Polar operator +(Polar &p){
            float x1 = radius * cos(angle*180/3.14);
            float y1 = radius * sin(angle*180/3.14);
            float x2 = p.radius * cos(p.angle*180/3.14);
            float y2 = p.radius * sin(p.angle*180/3.14);
            float x = x1 + x2;
            float y = y1 + y2;
            float r = sqrt(x*x + y*y);
            float a = atan(y/x);
            return Polar(r, a);
        }
        void display(){
            cout << "Radius: " << radius << " Angle: " << angle << endl;
        }
};

int main(){
    float r1, a1;
    cout<<"Enter radius and angle for Polar 1: ";
    cin>>r1>>a1;
    Polar p1(r1, a1);
    cout<<"Enter radius and angle for Polar 2:";
    cin>>r1>>a1;
    Polar p2(r1, a1);
    Polar p3 = p1 + p2;
    p3.display();
    return 0;
}