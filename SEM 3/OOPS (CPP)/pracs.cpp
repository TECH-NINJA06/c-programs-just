/*Create a class FLOAT that contains one float data member. Overload all the four arithmetic operators so that they operate on the objects of FLOAT*/

#include<iostream>
using namespace std;

class FLOAT{
    private:
        float num;
    public:
        FLOAT():num(0){}
        FLOAT(float n):num(n){}
        FLOAT operator +(FLOAT &f){
            return FLOAT(num + f.num);
        }
        FLOAT operator -(FLOAT &f){
            return FLOAT(num - f.num);
        }
        FLOAT operator *(FLOAT &f){
            return FLOAT(num * f.num);
        }
        FLOAT operator /(FLOAT &f){
            return FLOAT(num / f.num);
        }
        void display(){
            cout << "Result: " << num << endl;
        }
};

int main()
{
    FLOAT f1(20), f2(4.5), f3;
    f3 = f1 + f2;
    f3.display();
    f3 = f1 - f2;
    f3.display();
    f3 = f1 * f2;
    f3.display();
    f3 = f1 / f2;
    f3.display();
    return 0;
}
