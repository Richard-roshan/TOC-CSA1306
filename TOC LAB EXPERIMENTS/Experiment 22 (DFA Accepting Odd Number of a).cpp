#include <iostream>
#include <string>

using namespace std;

// DFA over {a, b} accepting strings with an odd number of 'a's
bool oddA(const string& s) {
    int state = 0; // 0: even 'a's, 1: odd 'a's (accepting)
    for (char ch : s) {
        if (ch == 'a') state = 1 - state;
        else if (ch != 'b') return false;
    }
    return state == 1;
}

int main() {
    string s;
    cout << "Enter string over {a, b}: ";
    cin >> s;
    cout << (oddA(s) ? "Accepted (Odd number of a's)" : "Rejected") << endl;
    return 0;
}
