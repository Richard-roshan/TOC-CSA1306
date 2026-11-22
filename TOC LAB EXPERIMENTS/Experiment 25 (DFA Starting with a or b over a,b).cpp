#include <iostream>
#include <string>

using namespace std;

// DFA over {a, b} accepting non-empty strings starting with 'a' or 'b'
bool startsWithAOrB(const string& s) {
    if (s.empty()) return false;
    if (s[0] != 'a' && s[0] != 'b') return false;
    for (char ch : s) {
        if (ch != 'a' && ch != 'b') return false;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter string over {a, b}: ";
    cin >> s;
    cout << (startsWithAOrB(s) ? "Accepted" : "Rejected") << endl;
    return 0;
}
