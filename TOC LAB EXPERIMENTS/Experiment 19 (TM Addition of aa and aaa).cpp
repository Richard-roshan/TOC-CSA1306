#include <iostream>
#include <string>

using namespace std;

// Unary Turing Machine addition: concatenates operand1 and operand2 separated by '+'
string unaryAdditionTM(const string& op1, const string& op2) {
    string tape = op1 + "+" + op2;
    string result = "";
    for (char ch : tape) {
        if (ch == 'a') result += 'a';
    }
    return result;
}

int main() {
    cout << "Unary addition of 'aa' + 'aaa' = " << unaryAdditionTM("aa", "aaa") << endl;
    string a, b;
    cout << "Enter first unary string of 'a's: ";
    cin >> a;
    cout << "Enter second unary string of 'a's: ";
    cin >> b;
    cout << "Result: " << unaryAdditionTM(a, b) << endl;
    return 0;
}
