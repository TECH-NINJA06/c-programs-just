#include <iostream>
#include <cstring>
using namespace std;

class String {
    char *str;
    int len;

public:
    String() {
        str = new char[1];
        str[0] = '\0';
        len = 0;
    }

    ~String() {
        delete[] str;
    }

    String(const String &s) {
        len = s.len;
        str = new char[len + 1];
        strcpy(str, s.str);
    }

    String &operator=(const String &s) {
        if (this != &s) {
            delete[] str;
            len = s.len;
            str = new char[len + 1];
            strcpy(str, s.str);
        }
        return *this;
    }

    void operator=(const char *s) {
        delete[] str;
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    friend String operator+(String &s1, String &s2);
    friend ostream &operator<<(ostream &out, String &s);
    friend istream &operator>>(istream &in, String &s);
};

ostream &operator<<(ostream &out, String &s) {
    out << s.str;
    return out;
}

istream &operator>>(istream &in, String &s) {
    char temp[100];
    in >> temp;
    s = temp;
    return in;
}

String operator+(String &s1, String &s2) {
    String s3;
    s3.len = s1.len + s2.len;
    s3.str = new char[s3.len + 1];
    strcpy(s3.str, s1.str);
    strcat(s3.str, s2.str);
    return s3;
}

int main() {
    String s1, s2, s3;
    cout<<"Enter string 1: ";
    cin>>s1;
    cout<<"Enter string 2: ";
    cin>>s2;
    s3 = s1 + s2;
    cout << s1 << " + " << s2 << " = " << s3 << endl;
}
