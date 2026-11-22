#include <iostream>
#include <string>

using namespace std;

// Turing Machine palindrome checker (tests "ababa" or any palindrome over {a, b})
bool isPalindromeTM(string tape) {
    if (tape.empty()) return false;
    int left = 0;
    int right = (int)tape.size() - 1;

    while (left < right) {
        if (tape[left] != tape[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    cout << "Testing default string \"ababa\": " << (isPalindromeTM("ababa") ? "Accepted" : "Rejected") << endl;
    string s;
    cout << "Enter string to check palindrome on TM: ";
    cin >> s;
    cout << (isPalindromeTM(s) ? "Accepted by TM" : "Rejected by TM") << endl;
    return 0;
}
