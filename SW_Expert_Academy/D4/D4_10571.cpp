#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, M;
		cin >> N >> M;

		vector<vector<int>> h(N, vector<int>(M, 100));
		vector<int> mrow(N, 0); vector<int> mcol(M, 0);
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < M; k++) {
				cin >> h[i][k];
				mrow[i] = max(mrow[i], h[i][k]);
				mcol[k] = max(mcol[k], h[i][k]);
			}
		}

		bool tf = true;
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < M; k++) {
				if (h[i][k] != mrow[i] && h[i][k] != mcol[k]) {
					tf = false;
					break;
				}
			}
			if (!tf) break;
		}

		if(tf) cout << "#" << t << " " << "YES\n";
		else cout << "#" << t << " " << "NO\n";
		/*vector<vector<int>> graph(N, vector<int>(M, 100));
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < M; k++) {
				cin >> graph[i][k];
			}
		}

		vector<vector<int>> compare(N, vector<int>(M, 100));
		for (int i = 0; i < N; i++) {
			int x1 = graph[i][0];
			int x2 = graph[i][M - 1];
			int x = min(x1, x2);
				for (int k = 0; k < M; k++) {
					if (compare[i][k] > x) compare[i][k] = x;
				}
		}
		for (int i = 0; i < M; i++) {
			int y1 = graph[0][i];
			int y2 = graph[N - 1][i];
			int y = min(y1, y2);
			for (int k = 0; k < N; k++) {
				if (compare[k][i] > y) compare[k][i] = y;
			}
		}
		if (graph == compare) cout << "#" << t << " " << "YES\n";
		else cout << "#" << t << " " << "NO\n";*/
	}

	return 0;
}