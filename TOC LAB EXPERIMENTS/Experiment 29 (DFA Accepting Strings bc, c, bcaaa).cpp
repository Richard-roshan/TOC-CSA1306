#include <iostream>
#include <string>

using namespace std;

// DFA accepting strings: "bc", "c", "bcaaa"
bool simulateDFA(const string& s) {
    if (s == "bc" || s == "c" || s == "bcaaa") return true;
    return false;
}

int main() {
    string tests[] = {"bc", "c", "bcaaa", "b", "bca", "cc"};
    for (const string& t : tests) {
        cout << "Input \"" << t << "\" -> " << (simulateDFA(t) ? "Accepted" : "Rejected") << endl;
    }
    string custom;
    cout << "\nEnter custom string: ";
    cin >> custom;
    cout << "Input \"" << custom << "\" -> " << (simulateDFA(custom) ? "Accepted" : "Rejected") << endl;
    return 0;
}
