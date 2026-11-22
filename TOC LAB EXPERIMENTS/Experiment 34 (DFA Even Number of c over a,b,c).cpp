#include <iostream>
#include <string>

using namespace std;

// DFA over {a, b, c} accepting strings with an even number of 'c's
bool evenC(const string& s) {
    int state = 0; // 0: even 'c's (accepting), 1: odd 'c's
    for (char ch : s) {
        if (ch == 'c') state = 1 - state;
        else if (ch != 'a' && ch != 'b') return false;
    }
    return state == 0;
}

int main() {
    string s;
    cout << "Enter string over {a, b, c}: ";
    cin >> s;
    cout << (evenC(s) ? "Accepted (Even number of c's)" : "Rejected") << endl;
    return 0;
}
