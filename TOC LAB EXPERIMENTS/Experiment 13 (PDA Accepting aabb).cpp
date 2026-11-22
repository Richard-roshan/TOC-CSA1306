#include <iostream>
#include <string>
#include <stack>

using namespace std;

// PDA for a^n b^n (such as "aabb") using stack
bool simulatePDA(const string& s) {
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
    return st.empty() && !s.empty();
}

int main() {
    string s;
    cout << "Enter string (e.g., aabb): ";
    cin >> s;
    cout << (simulatePDA(s) ? "Accepted by PDA" : "Rejected by PDA") << endl;
    return 0;
}
