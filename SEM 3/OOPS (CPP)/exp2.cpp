#include <iostream>
#include <iomanip>
using namespace std;

class Box {
private:
    float l,b,h,vol;
public:
    Box(){
        l=0;
        b=0;
        h=0;
    }
    inline void setval(float &x){
        l=x;
        b=x;
        h=x;
    }
    inline void setval(float &x,float &y ,float &z){
        l=x;
        b=y;
        h=z;
    }
    friend float calc(Box &);
};
float calc(Box &B){
    B.vol=B.l*B.b*B.h;
    return B.vol;
}
int main() {
    Box cuboid,cube;
    float l,b,h;
    cout<<"Enter length, breadth, height of cuboid:";
    cin>>l>>b>>h;
    cuboid.setval(l,b,h);
    cout<<"\nEnter length of cube:";
    cin>>l;
    cube.setval(l);
    cout<<"\nVolume of Cuboid:"<<setprecision(2)<<calc(cuboid)<<" cu. units"<<endl<<"Volume of cube:"<<setprecision(2)<<calc(cube)<<" cu. units";
    return 0;
}

