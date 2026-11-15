#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void findEpsilonClosure(int startState, int numStates, const vector<vector<int>>& epsAdj) {
    set<int> closure;
    queue<int> q;

    closure.insert(startState);
    q.push(startState);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int nextState : epsAdj[curr]) {
            if (closure.find(nextState) == closure.end()) {
                closure.insert(nextState);
                q.push(nextState);
            }
        }
    }

    cout << "e-closure(q" << startState << ") = { ";
    bool first = true;
    for (int s : closure) {
        if (!first) cout << ", ";
        cout << "q" << s;
        first = false;
    }
    cout << " }" << endl;
}

int main() {
    int numStates, numTransitions;
    cout << "Enter the number of states (0 to n-1): ";
    cin >> numStates;

    vector<vector<int>> epsAdj(numStates);

    cout << "Enter the number of epsilon transitions: ";
    cin >> numTransitions;

    cout << "Enter each epsilon transition as: <from_state> <to_state>" << endl;
    for (int i = 0; i < numTransitions; i++) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < numStates && v >= 0 && v < numStates) {
            epsAdj[u].push_back(v);
        } else {
            cout << "Invalid state number! Try again." << endl;
            i--;
        }
    }

    cout << "\n--- Epsilon Closures ---" << endl;
    for (int i = 0; i < numStates; i++) {
        findEpsilonClosure(i, numStates, epsAdj);
    }

    return 0;
}
