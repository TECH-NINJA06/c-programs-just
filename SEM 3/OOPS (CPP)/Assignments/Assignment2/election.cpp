#include <iostream>
#include <iomanip>
using namespace std;

class election{
    long int c[5];
    public:
    void initialise(){
        for(int i=0;i<5;i++)
            c[i]=0;
    }
    int check(int vote);
    void display();
};
int election::check(int vote=0){
    cin>>vote;
    switch(vote){
        case 1:
            c[0]++;
            break;
        case 2:
            c[1]++;
            break;
        case 3:
            c[2]++;
            break;
        case 4:
            c[3]++;
            break;
        case 5:
            c[4]++;
            break;
        default:
            return 1;
        }
    return 0;
}
void election::display(){
    cout<<setw(35)<<"VOTES"<<endl;
    cout<<"Candidate 1"<<setw(15)<<"Candidate 2"<<setw(15)<<"Candidate 3"<<setw(15)<<"Candidate 4"<<setw(15)<<"Candidate 5"<<endl;
    for(int i=0;i<5;i++){
        cout<<left<<setw(15)<<c[i];
    }
    cout<<endl;
}
int main(){
    election ca;
    ca.initialise();
    int spoil=0,n;
    cout<<"Enter Number of votes:";
    cin>>n;
    cout<<"\nEnter the votes :";
    for(int i=0;i<n;i++){
        spoil+=ca.check();
    }
    ca.display();
    cout<<endl<<"Spoil Votes:"<<spoil;
    return 0;
}
