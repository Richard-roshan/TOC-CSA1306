#include <iostream>
#include <string>

using namespace std;

bool parseA(const string& str, int left, int right) {
    for (int i = left; i <= right; i++) {
        if (str[i] != '1') return false;
    }
    return true;
}

bool parseS(const string& str, int left, int right) {
    if (left > right) return true;
    if (str[left] == '0' && str[right] == '0') {
        if (left == right) return false;
        return parseS(str, left + 1, right - 1);
    }
    return parseA(str, left, right);
}

int main() {
    string str;
    cout << "Enter a string (use 'e' for epsilon/empty string): ";
    cin >> str;

    if (str == "e") str = "";

    if (parseS(str, 0, (int)str.length() - 1)) {
        cout << "Accepted: The string belongs to the CFG." << endl;
    } else {
        cout << "Rejected: The string does NOT belong to the CFG." << endl;
    }

    return 0;
}
