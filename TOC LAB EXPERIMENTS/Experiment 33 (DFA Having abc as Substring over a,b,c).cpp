#include <iostream>
#include <string>

using namespace std;

// DFA over {a, b, c} accepting strings containing "abc" as a substring
bool hasSubstringABC(const string& s) {
    // 0: start
    // 1: seen 'a'
    // 2: seen 'ab'
    // 3: seen 'abc' (accepting)
    int state = 0;
    for (char ch : s) {
        if (state == 3) continue;
        if (ch == 'a') {
            state = 1;
        } else if (ch == 'b') {
            state = (state == 1) ? 2 : 0;
        } else if (ch == 'c') {
            state = (state == 2) ? 3 : 0;
        } else {
            return false;
        }
    }
    return state == 3;
}

int main() {
    string s;
    cout << "Enter string over {a, b, c}: ";
    cin >> s;
    cout << (hasSubstringABC(s) ? "Accepted (contains 'abc')" : "Rejected") << endl;
    return 0;
}
