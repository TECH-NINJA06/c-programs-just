#include <iostream>
#include <iomanip>
using namespace std;

class Student{
protected:
    string roll,name;
public:
    void getdata()
    {
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter name: ";
        cin >> name;
    }
};

class Test : public virtual Student{
protected:
    int marks[3];
public:
    void getmarks()
    {
        cout << "Enter marks in 3 subjects: ";
        for (int i = 0; i < 3; i++)
            cin >> marks[i];
    }
};

class Sports: public virtual Student{
protected:
    int score;
public:
    void getscore()
    {
        cout << "Enter score in sports: ";
        cin >> score;
    }
};

class Result: public Test, public Sports{
    int total;
public:
    void setdata(){
        getdata();
        getmarks();
        getscore();
    }
    void display()
    {
        total = marks[0] + marks[1] + marks[2] + score;
        cout << setw(15) << roll << setw(15) << name << setw(15) << marks[0] << setw(15) << marks[1] << setw(15) << marks[2] << setw(15) << score << setw(15) << total << endl;
    }
};

int main(){
    cout<<"Enter Number of Students:";
    int n;
    cin>>n;
    Result *r=new Result[n];
    for(int i=0;i<n;i++){
        r[i].setdata();
    }
    cout << setw(15) << "Roll number" << setw(15) << "Name" << setw(15) << "Marks1" << setw(15) << "Marks2" << setw(15) << "Marks3" << setw(15) << "Score" << setw(15) << "Total" << endl;
    for(int i=0;i<n;i++){
        r[i].display();
    }
    return 0;
}