#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Turing Machine simulator for { a^n b^n | n >= 1 }
bool simulateTM(string input) {
    if (input.empty()) return false;
    string tape = input;
    int head = 0;

    while (true) {
        // Find first unmarked 'a'
        head = 0;
        while (head < (int)tape.size() && tape[head] != 'a') {
            head++;
        }
        if (head == (int)tape.size()) {
            // No unmarked 'a' left; verify no unmarked 'b' remains
            for (char c : tape) {
                if (c == 'b') return false;
            }
            return true;
        }
        tape[head] = 'X'; // Mark 'a'

        // Move right to find first unmarked 'b'
        while (head < (int)tape.size() && tape[head] != 'b') {
            head++;
        }
        if (head == (int)tape.size()) {
            return false; // Missing matching 'b'
        }
        tape[head] = 'Y'; // Mark 'b'
    }
}

int main() {
    string s;
    cout << "Enter string for TM (a^n b^n): ";
    cin >> s;
    cout << (simulateTM(s) ? "Accepted by TM" : "Rejected by TM") << endl;
    return 0;
}
