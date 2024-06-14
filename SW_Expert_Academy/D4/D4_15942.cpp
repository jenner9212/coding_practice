#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <array>

using namespace std;

long long k, total;
int n;
long long arr[200000];
bool visit[200000];
long long pos[200000];

int find(int c) {
    if (!visit[c] || pos[c] == c) return c;
    return pos[c] = find(pos[c]);
}

void solve() {
    int ans = 0;
    while (k < total) {
        ans++;
        int cur = upper_bound(arr, arr + n, k) - arr;
        if (cur > 0) {
            cur = find(cur - 1);
            if (!visit[cur]) {
                k += arr[cur];
                total -= arr[cur];
                visit[cur] = true;
                if (cur > 0) pos[cur] = find(cur - 1);
            }
            else {
                ans = -1;
                break;
            }
        }
        else {
            ans = -1;
            break;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n >> k;
        total = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            total += arr[i];
            visit[i] = false;
            pos[i] = i;
        }
        sort(arr, arr + n);
        cout << "#" << t << " ";
        solve();
    }
}