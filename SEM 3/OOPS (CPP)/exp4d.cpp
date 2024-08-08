#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char *str

public:
    String(const char* s = "") {
        strncpy(str, s, MAX_SIZE - 1);
        str[MAX_SIZE - 1] = '\0';
    }

    String(const String& other) {
        strncpy(str, other.str, MAX_SIZE - 1);
        str[MAX_SIZE - 1] = '\0';
    }

    String operator+(const String& other){
        char temp[MAX_SIZE * 2];
        strncpy(temp, str, MAX_SIZE - 1);
        temp[MAX_SIZE - 1] = '\0';
        strncat(temp, other.str, MAX_SIZE - strlen(temp) - 1);
        return String(temp);
    }

    void display(){
        cout << str << endl;
    }

    friend ostream& operator<<(ostream& os, const String& obj) {
        os << obj.str;
        return os;
    }

    friend istream& operator>>(istream& is, String& obj) {
        is.getline(obj.str, MAX_SIZE);
        return is;
    }
    void compareLength(const String& other) {
        if (strlen(str) < strlen(other.str)) {
            cout << "The first string is shorter." << endl;
        } else if (strlen(str) > strlen(other.str)) {
            cout << "The second string is shorter." << endl;
        } else {
            cout << "Both strings are of equal length." << endl;
        }
    }
};

int main() {
    String s1, s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;
    String s3 = s1 + s2;
    cout << "Concatenated string: " << s3 << endl;
    return 0;
    s1.compareLength(s2);
}
