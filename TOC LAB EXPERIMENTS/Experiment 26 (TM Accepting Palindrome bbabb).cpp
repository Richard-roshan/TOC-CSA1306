#include <iostream>
#include <string>

using namespace std;

// Turing Machine palindrome check (tests "bbabb" and custom strings)
bool checkPalindrome(const string& s) {
    if (s.empty()) return false;
    int l = 0, r = (int)s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    cout << "Testing \"bbabb\" -> " << (checkPalindrome("bbabb") ? "Accepted" : "Rejected") << endl;
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << (checkPalindrome(s) ? "Accepted by TM" : "Rejected by TM") << endl;
    return 0;
}
