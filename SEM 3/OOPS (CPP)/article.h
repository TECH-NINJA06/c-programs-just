class Article{
    string name;
    int price;
    public:
    Article(){
        name="\0";
        price=0;
    }
    Article(int p, string n){
        acount++;
        name=n;
        if(p<=0)
            price=0;
        else
            price=p;
        cout<<endl<<"Object a"<<acount<<" created"<<endl;
    }
    ~Article(){
        cout<<endl<<"Object a"<<acount<<" destroyed"<<endl;
        acount--;
    }
    void print(){
        cout<<left<<setw(20)<<name<<left<<setw(15)<<price<<endl;
    }
};
