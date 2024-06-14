#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;

        vector<string> W;
        string s;

        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            cin >> s;

            if (s != string(s.rbegin(), s.rend()))
                W.push_back(s);
        }

        int SIZE = W.size();
        if (SIZE < N) cnt += 1;

        for (int i = 0; i < SIZE; ++i) {
            s = W.back();
            W.pop_back();
            if (find(W.begin(), W.end(), string(s.rbegin(), s.rend())) != W.end()) {
                cnt += 2;
            }
        }

        cout << '#' << t << ' ' << cnt * M << '\n';
    }
    return 0;
}