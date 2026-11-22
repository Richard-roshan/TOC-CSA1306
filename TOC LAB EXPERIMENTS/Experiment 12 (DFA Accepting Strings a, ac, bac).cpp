#include <iostream>
#include <string>

using namespace std;

// DFA accepting strings over {a, b, c}: "a", "ac", "bac"
bool simulateDFA(const string& s) {
    // 0: Start
    // 1: After 'a' (accepting)
    // 2: After 'ac' (accepting)
    // 3: After 'b'
    // 4: After 'ba'
    // 5: After 'bac' (accepting)
    // 6: Dead state
    int state = 0;
    for (char ch : s) {
        switch (state) {
            case 0:
                if (ch == 'a') state = 1;
                else if (ch == 'b') state = 3;
                else state = 6;
                break;
            case 1:
                if (ch == 'c') state = 2;
                else state = 6;
                break;
            case 2:
                state = 6;
                break;
            case 3:
                if (ch == 'a') state = 4;
                else state = 6;
                break;
            case 4:
                if (ch == 'c') state = 5;
                else state = 6;
                break;
            case 5:
                state = 6;
                break;
            default:
                state = 6;
                break;
        }
    }
    return (state == 1 || state == 2 || state == 5);
}

int main() {
    string tests[] = {"a", "ac", "bac", "ab", "b", "c", ""};
    for (const string& t : tests) {
        cout << "Input \"" << t << "\" -> " << (simulateDFA(t) ? "Accepted" : "Rejected") << endl;
    }

    string custom;
    cout << "\nEnter a custom string to test: ";
    cin >> custom;
    cout << "Input \"" << custom << "\" -> " << (simulateDFA(custom) ? "Accepted" : "Rejected") << endl;
    return 0;
}
