#include <iostream>
#include <string>

using namespace std;

// DFA over {a, b} accepting strings with an even number of 'a's
bool evenA(const string& s) {
    int state = 0; // 0: even 'a's (accepting), 1: odd 'a's
    for (char ch : s) {
        if (ch == 'a') state = 1 - state;
        else if (ch != 'b') return false;
    }
    return state == 0;
}

int main() {
    string s;
    cout << "Enter string over {a, b}: ";
    cin >> s;
    cout << (evenA(s) ? "Accepted (Even number of a's)" : "Rejected") << endl;
    return 0;
}
