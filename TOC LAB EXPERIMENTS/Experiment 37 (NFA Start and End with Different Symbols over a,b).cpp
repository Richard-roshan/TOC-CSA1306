#include <iostream>
#include <string>

using namespace std;

// NFA/Automaton over {a, b} accepting strings starting and ending with different symbols
bool startEndDifferent(const string& s) {
    if (s.size() < 2) return false;
    for (char ch : s) {
        if (ch != 'a' && ch != 'b') return false;
    }
    return s.front() != s.back();
}

int main() {
    string s;
    cout << "Enter string over {a, b}: ";
    cin >> s;
    cout << (startEndDifferent(s) ? "Accepted (starts and ends with different symbols)" : "Rejected") << endl;
    return 0;
}
