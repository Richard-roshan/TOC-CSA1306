#include <iostream>
#include <string>

using namespace std;

// DFA over {a, b} where every contiguous block of 'a's has length divisible by 3 (tripled)
bool aAlwaysTripled(const string& s) {
    int aStreak = 0;
    for (char ch : s) {
        if (ch == 'a') {
            aStreak++;
        } else if (ch == 'b') {
            if (aStreak % 3 != 0) return false;
            aStreak = 0;
        } else {
            return false;
        }
    }
    return (aStreak % 3 == 0);
}

int main() {
    string s;
    cout << "Enter string over {a, b}: ";
    cin >> s;
    cout << (aAlwaysTripled(s) ? "Accepted" : "Rejected") << endl;
    return 0;
}
