#include <iostream>
#include <string>
#include <stack>

using namespace std;

// PDA for language { a^n b^(2n) | n >= 1 }
// Push two markers ('X', 'X') for every 'a', pop one for every 'b'
bool simulatePDA(const string& s) {
    stack<char> st;
    bool seenB = false;

    for (char ch : s) {
        if (ch == 'a') {
            if (seenB) return false;
            st.push('X');
            st.push('X');
        } else if (ch == 'b') {
            seenB = true;
            if (st.empty()) return false;
            st.pop();
        } else {
            return false;
        }
    }
    return st.empty() && !s.empty();
}

int main() {
    string s;
    cout << "Enter string over {a, b} for a^n b^(2n): ";
    cin >> s;
    cout << (simulatePDA(s) ? "Accepted by PDA" : "Rejected by PDA") << endl;
    return 0;
}
