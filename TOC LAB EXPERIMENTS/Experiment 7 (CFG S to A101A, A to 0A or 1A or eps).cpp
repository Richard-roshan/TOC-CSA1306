#include <iostream>
#include <string>

using namespace std;

bool isValidBinary(const string& str) {
    for (char ch : str) {
        if (ch != '0' && ch != '1') return false;
    }
    return true;
}

bool parseS(const string& str) {
    if (!isValidBinary(str)) return false;
    return str.find("101") != string::npos;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (parseS(str)) {
        cout << "Accepted: The string belongs to the CFG (contains '101')." << endl;
    } else {
        cout << "Rejected: The string does NOT belong to the CFG." << endl;
    }

    return 0;
}
