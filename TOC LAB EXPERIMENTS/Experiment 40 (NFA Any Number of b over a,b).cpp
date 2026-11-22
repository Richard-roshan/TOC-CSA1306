#include <iostream>
#include <string>

using namespace std;

// NFA accepting any number of 'b's (including zero) over {a, b}
bool nfaAnyB(const string& s) {
    for (char ch : s) {
        if (ch != 'a' && ch != 'b') return false;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter string over {a, b}: ";
    cin >> s;
    cout << (nfaAnyB(s) ? "Accepted by NFA" : "Rejected by NFA") << endl;
    return 0;
}
