#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x, y, r, c, k;
string target;
string result;
vector<vector<int>> visited;

int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, -1, 1, 0 };
string moves[4] = { "d", "l", "r", "u" };

bool isValid(int i, int j) {
    return (i >= 1 && i <= n && j >= 1 && j <= m);
}

void dfs(int curX, int curY, int steps) {
    int dist = abs(curX-r) + abs(curY-c);
    if(k - steps - dist < 0) return;
    if((k - steps - dist) % 2 == 1) return;
    
    if (curX == r && curY == c && steps == k) {
        if (result.empty() || target < result) {
            result = target;
        }
        return;
    }

    if (steps >= k || (result != "" && target >= result)) {
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int newX = curX + dx[i];
        int newY = curY + dy[i];

        if (isValid(newX, newY)) {
            target += moves[i];
            dfs(newX, newY, steps + 1);
            target.pop_back();
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    ::n = n; ::m = m; ::x = x; ::y = y; ::r = r; ::c = c; ::k = k;
    visited.assign(n + 1, vector<int>(m + 1, 0));
    target = "";
    result = "";

    dfs(x, y, 0);

    if (result.empty()) {
        return "impossible";
    }

    return result;
}