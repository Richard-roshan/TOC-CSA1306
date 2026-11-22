#include <iostream>
#include <string>

using namespace std;

// DFA over {a, b} accepting strings ending with "ab"
bool endsWithAB(const string& s) {
    // 0: no match suffix
    // 1: ends with 'a'
    // 2: ends with 'ab' (accepting)
    int state = 0;
    for (char ch : s) {
        if (ch == 'a') state = 1;
        else if (ch == 'b') state = (state == 1) ? 2 : 0;
        else return false;
    }
    return state == 2;
}

int main() {
    string w = "aaabab";
    cout << "Testing W = " << w << " -> " << (endsWithAB(w) ? "Accepted" : "Rejected") << endl;
    string s;
    cout << "Enter string over {a, b}: ";
    cin >> s;
    cout << (endsWithAB(s) ? "Accepted" : "Rejected") << endl;
    return 0;
}
