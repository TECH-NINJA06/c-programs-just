#include <iostream>
#include <iomanip>
using namespace std;

class student{
    protected:
    string rollno;
};
class marks:protected student{
    protected:
    int m[2];
};
class result:protected marks{
    int total;
    public:
    result(){
        cout<<"Enter Roll Number:";
        cin>>rollno;
        cout<<"Enter Marks of 2 Subjects:";
        cin>>m[0]>>m[1];
        total=m[0]+m[1];
    }
    void display(){
        cout<<setw(15)<<left<<rollno<<setw(10)<<left<<m[0]<<setw(10)<<left<<m[1]<<left<<total<<"/200"<<endl;
    }
};
int main(){
    int n;
    cout<<"Enter Number of Students:";
    cin>>n;
    result *r=new result[n];
    cout<<"Result is as follows:\n";
    cout<<setw(15)<<left<<"Roll No"<<left<<setw(10)<<left<<"Subject1"<<setw(10)<<left<<"Subject2"<<left<<"Total"<<endl;
    for(int i=0;i<n;i++){
        r[i].display();
    }
    return 0;
}