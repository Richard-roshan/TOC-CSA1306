#include <iostream>
#include <string>

using namespace std;

// Turing Machine simulator for language { w c w | w in {a, b}* }
bool simulateWCW(const string& s) {
    size_t cPos = s.find('c');
    if (cPos == string::npos) return false;
    if (s.find('c', cPos + 1) != string::npos) return false; // More than one 'c'

    string left = s.substr(0, cPos);
    string right = s.substr(cPos + 1);
    return left == right;
}

int main() {
    string s;
    cout << "Enter string in form w c w (e.g., abcaba): ";
    cin >> s;
    cout << (simulateWCW(s) ? "Accepted by TM" : "Rejected by TM") << endl;
    return 0;
}
