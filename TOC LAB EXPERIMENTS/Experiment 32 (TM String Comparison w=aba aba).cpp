#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Turing Machine string comparison for two space/delimiter-separated strings
bool compareStringsTM(const string& s1, const string& s2) {
    return s1 == s2;
}

int main() {
    cout << "Testing default w = \"aba aba\" -> "
         << (compareStringsTM("aba", "aba") ? "Equal (Accepted)" : "Not Equal (Rejected)") << endl;

    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    cout << (compareStringsTM(s1, s2) ? "Strings Match (Accepted)" : "Strings Differ (Rejected)") << endl;
    return 0;
}
