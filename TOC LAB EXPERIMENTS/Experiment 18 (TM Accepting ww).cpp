#include <iostream>
#include <string>

using namespace std;

// Turing Machine simulator for language { ww | w in {a, b}* }
bool simulateWW(const string& tape) {
    int n = (int)tape.size();
    if (n == 0 || n % 2 != 0) return false;
    int half = n / 2;
    for (int i = 0; i < half; i++) {
        if (tape[i] != tape[i + half]) return false;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter string for TM (ww): ";
    cin >> s;
    cout << (simulateWW(s) ? "Accepted by TM" : "Rejected by TM") << endl;
    return 0;
}
