#include <iostream>
#include <string>

using namespace std;

// DFA over {a, b} accepting strings containing "ab" as a substring
bool hasSubstringAB(const string& s) {
    // 0: initial
    // 1: last char 'a'
    // 2: seen 'ab' (trap/accepting state)
    int state = 0;
    for (char ch : s) {
        if (state == 2) continue;
        if (ch == 'a') state = 1;
        else if (ch == 'b') state = (state == 1) ? 2 : 0;
        else return false;
    }
    return state == 2;
}

int main() {
    string s;
    cout << "Enter string over {a, b}: ";
    cin >> s;
    cout << (hasSubstringAB(s) ? "Accepted (contains 'ab')" : "Rejected") << endl;
    return 0;
}
