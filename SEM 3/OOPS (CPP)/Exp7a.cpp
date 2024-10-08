#include <iostream>
#include <iomanip>
using namespace std;

int n;
class cricket{
    string name;
    long int runs, ings;
    int notout;
    float avg;
    public:
    inline void input(){
        cout<<"Enter name:";
        getline(cin, name);
        cout<<"Enter Total Runs, Total Innings , Times not out:";
        cin>>runs>>ings>>notout;
        avg=runs/(ings-notout);
        cin.ignore();
    }
    void display(){
        cout.width(15);
        cout<<name;
        cout.width(15);
        cout<<runs;
        cout.width(15);
        cout<<ings;
        cout.width(20);
        cout<<notout;
        cout.width(17);
        cout<<setprecision(2)<<avg<<endl;
    }
};
int main(){
    cout<<"\nEnter Number of players:";
    cin>>n;
    cin.ignore();
    cricket *p = new cricket[n];
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"PLAYER "<<i+1<<endl;
        p[i].input();
        cout<<endl;
    }
    cout<<endl;
    cout.width(15);
    cout<<"Name";
    cout.width(15);
    cout<<"Runs";
    cout.width(15);
    cout<<"Innings";
    cout.width(20);
    cout<<"Times not out";
    cout.width(17);
    cout<<"Batting Average"<<endl;
    for(int i=0;i<n;i++){
        p[i].display();
    }
    return 0;
}
