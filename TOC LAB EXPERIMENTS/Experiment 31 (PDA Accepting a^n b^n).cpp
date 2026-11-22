#include <iostream>
#include <string>
#include <stack>

using namespace std;

// PDA for language { a^n b^n | n >= 1 }
bool simulatePDA(const string& s) {
    if (s.empty()) return false;
    stack<char> st;
    bool seenB = false;

    for (char ch : s) {
        if (ch == 'a') {
            if (seenB) return false;
            st.push('A');
        } else if (ch == 'b') {
            seenB = true;
            if (st.empty()) return false;
            st.pop();
        } else {
            return false;
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter string for PDA (a^n b^n): ";
    cin >> s;
    cout << (simulatePDA(s) ? "Accepted by PDA" : "Rejected by PDA") << endl;
    return 0;
}
