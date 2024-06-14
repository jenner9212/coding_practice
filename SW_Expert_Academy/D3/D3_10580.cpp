#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		vector<pair<int, int>> v;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;

			v.push_back({ x,y });
		}

		sort(v.begin(), v.end());

		int cnt = 0;
		for (int i = 0; i < N - 1; i++) {
			for (int k = i + 1; k < N; k++) {
				if (v[k].second <= v[i].second) cnt++;
			}
		}

		cout << "#" << t << " " << cnt << "\n";
	}

	return 0;
}