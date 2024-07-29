#include <iostream>
#include <iomanip>
using namespace std;

int n;

class cricket_team{
    string name;
    long int runs, ings;
    int notout;
    float avg;
    public:
    inline void input(){
        cout<<"Enter Player Name , Total Runs, Total Innings , Times not out:";
        cin>>name>>runs>>ings>>notout;
        avg=runs/(ings-notout);
    }
    void display(){
        cout<<left<<setw(15)<<name<<left<<setw(15)<<runs<<left<<setw(15)<<ings<<left<<setw(20)<<notout<<left<<setw(15)<<setprecision(2)<<avg<<endl;
    }
};
int main(){
    cout<<"\nEnter Number of players:";
    cin>>n;
    cricket_team *p = new cricket_team[n];
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"PLAYER "<<i+1<<endl;
        p[i].input();
        cout<<endl;
    }
    cout<<endl;
    cout<<left<<setw(15)<<"Name"<<left<<setw(15)<<"Runs"<<left<<setw(15)<<"Innings"<<left<<setw(20)<<"Times not out"<<left<<setw(15)<<"Batting Average"<<endl;
    for(int i=0;i<n;i++){
        p[i].display();
    }
    return 0;
}
