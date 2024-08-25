#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* s;

public:
    String() {
        s = new char[1];
        s[0] = '\0';
    }

    String(const char* str) {
        s = new char[strlen(str) + 1];
        strcpy(s, str);
    }

    String(const String& other) {
        s = new char[strlen(other.s) + 1];
        strcpy(s, other.s);
    }
    String operator+(const String& other) {
        String result;
        result.s = new char[strlen(s) + strlen(other.s) + 1];
        strcpy(result.s, s);
        strcat(result.s, other.s);
        return result;
    }

    int len() const {
        return strlen(s);
    }

    friend ostream& operator<<(ostream& out, const String& obj) {
        out << obj.s;
        return out;
    }

    friend istream& operator>>(istream& in, String& obj) {
        char buffer[1000];
        in.getline(buffer, 1000);
        delete[] obj.s;
        obj.s = new char[strlen(buffer) + 1];
        strcpy(obj.s, buffer);
        return in;
    }
};
int main() {
    String s1, s2, res;

    cout << "Enter the first string: ";
    cin >> s1;

    cout << "Enter the second string: ";
    cin >> s2;

    res = s1 + s2;
    cout << "Concatenated string: " << res << endl;
    if (s1.len() < s2.len()) {
        cout << "The smaller string is: " << s1 << endl;
    }
    else if(s1.len()>s2.len()) {
        cout << "The smaller string is: " << s2 << endl;
    }
    else{
        cout<< "Both Strings are equal in size"<<endl;
    }


    return 0;
}
