#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, X;
		cin >> N >> X;
		
		vector<vector<int>> graph(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < N; k++) {
				int x;
				cin >> x;
				graph[i][k] = x;
			}
		}

		int answer = 0;
		// left -> right
		for (int i = 0; i < N; i++) {
			bool tf = true;
			for (int k = 0; k < N - 1; k++) {
				if (!tf) break;
				if (abs(graph[i][k] - graph[i][k + 1]) > 1) break;
				
				if (graph[i][k] == graph[i][k + 1]) continue;

				if (graph[i][k] > graph[i][k + 1] && abs(graph[i][k] - graph[i][k + 1] == 1)) {
					if (k + 1 + X - 1 < N) {
						for (int j = k + 1; j < k + 1 + X - 1; j++) {
							if (graph[i][j] != graph[i][j + 1]) {
								tf = false;
								break;
							}
						}
						k = k + X - 1;
					}
					else {
						tf = false;
						break;
					}
				}
				if (graph[i][k] < graph[i][k + 1] && abs(graph[i][k] - graph[i][k + 1] == 1)) {
					if (k - X + 1 >= 0) {
						for (int j = k - X + 1; j < k; j++) {
							if (graph[i][j] != graph[i][j + 1]) {
								tf = false;
								break;
							}
						}
					}
					else {
						tf = false;
						break;
					}
				}
			}
			if (tf) answer++;
		}
		// up -> down
		for (int i = 0; i < N; i++) {
			bool tf = true;
			for (int k = 0; k < N - 1; k++) {
				if (!tf) break;
				if (abs(graph[k][i] - graph[k + 1][i]) > 1) break;
				
				if (graph[k][i] == graph[k + 1][i]) continue;

				if (graph[k][i] > graph[k + 1][i] && abs(graph[k][i] - graph[k + 1][i] == 1)) {
					if (k + 1 + X - 1 < N) {
						for (int j = k + 1; j < k + 1 + X - 1; j++) {
							if (graph[j][i] != graph[j + 1][i]) {
								tf = false;
								break;
							}
						}
						k = k + X - 1;
					}
					else {
						tf = false;
						break;
					}
				}
				if (graph[k][i] < graph[k + 1][i] && abs(graph[k][i] - graph[k + 1][i] == 1)) {
					if (k - X + 1 >= 0) {
						for (int j = k - X + 1; j < k; j++) {
							if (graph[j][i] != graph[j + 1][i]) {
								tf = false;
								break;
							}
						}
					}
					else {
						tf = false;
						break;
					}
				}
			}
			if (tf) answer++;
		}

		cout << "#" << t << " " << answer << "\n";
	}
}