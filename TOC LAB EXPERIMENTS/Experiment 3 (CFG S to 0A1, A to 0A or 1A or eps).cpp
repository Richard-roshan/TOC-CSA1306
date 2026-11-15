#include <iostream>
#include <string>

using namespace std;

bool parseA(const string& str, int index, int end) {
    if (index > end) return true;
    if (str[index] == '0' || str[index] == '1') {
        return parseA(str, index + 1, end);
    }
    return false;
}

bool parseS(const string& str) {
    int n = str.length();
    if (n < 2) return false;
    if (str[0] == '0' && str[n - 1] == '1') {
        return parseA(str, 1, n - 2);
    }
    return false;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (parseS(str)) {
        cout << "Accepted: The string belongs to the CFG." << endl;
    } else {
        cout << "Rejected: The string does NOT belong to the CFG." << endl;
    }

    return 0;
}
