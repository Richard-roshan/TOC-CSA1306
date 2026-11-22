#include <iostream>
#include <string>

using namespace std;

// DFA over {a, b, c} accepting strings ending with "abc"
bool endsWithABC(const string& s) {
    // 0: initial
    // 1: ends with 'a'
    // 2: ends with 'ab'
    // 3: ends with 'abc' (accepting)
    int state = 0;
    for (char ch : s) {
        if (ch == 'a') state = 1;
        else if (ch == 'b') state = (state == 1) ? 2 : 0;
        else if (ch == 'c') state = (state == 2) ? 3 : 0;
        else return false;
    }
    return state == 3;
}

int main() {
    string w = "abbaababc";
    cout << "Testing W = " << w << " -> " << (endsWithABC(w) ? "Accepted" : "Rejected") << endl;
    string s;
    cout << "Enter string over {a, b, c}: ";
    cin >> s;
    cout << (endsWithABC(s) ? "Accepted" : "Rejected") << endl;
    return 0;
}
