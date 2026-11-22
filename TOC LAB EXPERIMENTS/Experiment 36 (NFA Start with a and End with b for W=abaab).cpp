#include <iostream>
#include <string>
#include <set>

using namespace std;

// NFA over {a, b} accepting strings starting with 'a' and ending with 'b'
bool nfaStartAEndB(const string& s) {
    if (s.size() < 2) return false;
    set<int> states = {0};

    for (char ch : s) {
        set<int> next;
        for (int st : states) {
            if (st == 0 && ch == 'a') {
                next.insert(1);
            } else if (st == 1) {
                if (ch == 'a' || ch == 'b') next.insert(1);
                if (ch == 'b') next.insert(2);
            }
        }
        states = next;
    }
    return states.count(2) > 0;
}

int main() {
    string w = "abaab";
    cout << "Testing W = " << w << " -> " << (nfaStartAEndB(w) ? "Accepted" : "Rejected") << endl;
    string s;
    cout << "Enter string over {a, b}: ";
    cin >> s;
    cout << (nfaStartAEndB(s) ? "Accepted" : "Rejected") << endl;
    return 0;
}
