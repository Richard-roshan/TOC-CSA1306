#include <iostream>
#include <string>

using namespace std;

// Unary Turing Machine proper subtraction (monus): max(0, len(op1) - len(op2))
string unarySubtractionTM(string op1, string op2) {
    int count1 = 0, count2 = 0;
    for (char c : op1) if (c == 'a') count1++;
    for (char c : op2) if (c == 'a') count2++;
    int diff = max(0, count1 - count2);
    return string(diff, 'a');
}

int main() {
    cout << "Unary subtraction 'aaa' - 'aa' = \"" << unarySubtractionTM("aaa", "aa") << "\"" << endl;
    string a, b;
    cout << "Enter minuend ('a's): ";
    cin >> a;
    cout << "Enter subtrahend ('a's): ";
    cin >> b;
    cout << "Result: \"" << unarySubtractionTM(a, b) << "\"" << endl;
    return 0;
}
