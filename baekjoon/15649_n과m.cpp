#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> sequence;
vector<bool> used;

void printSequence() {
    for (int num : sequence) {
        cout << num << ' ';
    }
    cout << '\n';
}

void backtrack() {
    if (sequence.size() == M) {
        printSequence();
        return;
    }
    
    for (int i = 1; i <= N; ++i) {
        if (!used[i]) {
            used[i] = true;
            sequence.push_back(i);
            backtrack();
            sequence.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    used.resize(N + 1, false);
    backtrack();

    return 0;
}