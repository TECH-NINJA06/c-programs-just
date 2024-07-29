#include <iostream>
using namespace std;

class temp2;
class temp1{
    int a;
    public:
    inline void setval(int x){
        a=x;
    }
    friend int add(temp1,temp2);
};
class temp2{
    int a;
    public:
    inline void setval(int y){
        a=y;
    }
    friend int add(temp1,temp2);
};
int add(temp1 t1,temp2 t2){
    return (t1.a+t2.a);
}
int main(){
    int x,y;
    temp1 m;
    temp2 n;
    cout<<"Enter two nos:";
    cin>>x>>y;
    m.setval(x);
    n.setval(y);
    cout<<endl<<x<<"+"<<y<<"="<<add(m,n);
    return 0;
}
