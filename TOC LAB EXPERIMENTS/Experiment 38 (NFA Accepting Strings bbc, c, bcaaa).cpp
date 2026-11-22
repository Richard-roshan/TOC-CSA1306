#include <iostream>
#include <string>

using namespace std;

// NFA accepting strings: "bbc", "c", "bcaaa"
bool simulateNFA(const string& s) {
    return (s == "bbc" || s == "c" || s == "bcaaa");
}

int main() {
    string tests[] = {"bbc", "c", "bcaaa", "bb", "bc", "bca"};
    for (const string& t : tests) {
        cout << "Input \"" << t << "\" -> " << (simulateNFA(t) ? "Accepted" : "Rejected") << endl;
    }
    string custom;
    cout << "\nEnter custom string: ";
    cin >> custom;
    cout << "Input \"" << custom << "\" -> " << (simulateNFA(custom) ? "Accepted" : "Rejected") << endl;
    return 0;
}
