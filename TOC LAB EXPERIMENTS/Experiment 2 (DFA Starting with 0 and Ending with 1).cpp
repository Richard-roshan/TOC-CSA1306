#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cout << "Enter a binary string over {0, 1}: ";
    cin >> str;

    int state = 0;

    for (char ch : str) {
        switch (state) {
            case 0:
                if (ch == '0') state = 1;
                else state = 3;
                break;
            case 1:
                if (ch == '0') state = 1;
                else if (ch == '1') state = 2;
                else state = 3;
                break;
            case 2:
                if (ch == '0') state = 1;
                else if (ch == '1') state = 2;
                else state = 3;
                break;
            case 3:
                state = 3;
                break;
        }
    }

    if (state == 2) {
        cout << "Accepted: The string starts with '0' and ends with '1'." << endl;
    } else {
        cout << "Rejected: The string does not satisfy the DFA condition." << endl;
    }

    return 0;
}
