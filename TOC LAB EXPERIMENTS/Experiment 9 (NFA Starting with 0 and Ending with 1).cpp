#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string str;
    cout << "Enter a binary string over {0, 1}: ";
    cin >> str;

    set<int> currentStates = {0};

    for (char ch : str) {
        set<int> nextStates;
        for (int state : currentStates) {
            if (state == 0 && ch == '0') {
                nextStates.insert(1);
            } else if (state == 1) {
                if (ch == '1') {
                    nextStates.insert(1);
                    nextStates.insert(2);
                } else if (ch == '0') {
                    nextStates.insert(1);
                }
            }
        }
        currentStates = nextStates;
    }

    if (currentStates.count(2)) {
        cout << "Accepted: The string starts with '0' and ends with '1'." << endl;
    } else {
        cout << "Rejected: The string is not accepted by the NFA." << endl;
    }

    return 0;
}
