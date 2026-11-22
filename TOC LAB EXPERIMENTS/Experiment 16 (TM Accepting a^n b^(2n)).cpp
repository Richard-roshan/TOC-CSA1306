#include <iostream>
#include <string>

using namespace std;

// Turing Machine simulator for { a^n b^(2n) | n >= 1 }
bool simulateTM(string input) {
    if (input.empty()) return false;
    string tape = input;

    while (true) {
        size_t posA = tape.find('a');
        if (posA == string::npos) {
            // Ensure no 'b' remains unmarked
            return tape.find('b') == string::npos;
        }
        tape[posA] = 'X';

        // Match two unmarked 'b's for each 'a'
        for (int k = 0; k < 2; k++) {
            size_t posB = tape.find('b');
            if (posB == string::npos) return false;
            tape[posB] = 'Y';
        }
    }
}

int main() {
    string s;
    cout << "Enter string for TM (a^n b^(2n)): ";
    cin >> s;
    cout << (simulateTM(s) ? "Accepted by TM" : "Rejected by TM") << endl;
    return 0;
}
