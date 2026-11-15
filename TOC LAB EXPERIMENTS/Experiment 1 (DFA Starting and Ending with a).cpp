#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cout << "Enter a string over {a, b}: ";
    cin >> str;

    int state = 0;

    for (char ch : str) {
        switch (state) {
            case 0:
                if (ch == 'a') state = 1;
                else state = 3;
                break;
            case 1:
                if (ch == 'a') state = 1;
                else if (ch == 'b') state = 2;
                else state = 3;
                break;
            case 2:
                if (ch == 'a') state = 1;
                else if (ch == 'b') state = 2;
                else state = 3;
                break;
            case 3:
                state = 3;
                break;
        }
    }

    if (state == 1) {
        cout << "Accepted: The string starts with 'a' and ends with 'a'." << endl;
    } else {
        cout << "Rejected: The string does not satisfy the DFA condition." << endl;
    }

    return 0;
}
