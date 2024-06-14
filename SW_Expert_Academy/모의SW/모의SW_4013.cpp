#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int> magnet[5];

void rotate(int num, int r) {
	vector<int> tmp(8);

	for (int i = 0; i < 8; i++) {
		tmp[(i + r + 8) % 8] = magnet[num][i];
	}
	for (int i = 0; i < 8; i++) {
		magnet[num][i] = tmp[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int K;
		cin >> K;

		for (int i = 1; i < 5; i++) {
			magnet[i].clear();
		}
		for (int i = 1; i < 5; i++) {
			for (int k = 0; k < 8; k++) {
				int x;
				cin >> x;
				magnet[i].push_back(x);
			}
		}

		for (int i = 0; i < K; i++) {
			int mag_num, r;
			int spin[5] = { 0, };
			cin >> mag_num >> r;

			spin[mag_num] = r;
			for (int j = mag_num, D = -r; j + 1 < 5; j++, D = -D) {
				if ((magnet[j][2] ^ magnet[j + 1][6]) > 0) spin[j + 1] = D;
				else break;
			}

			for (int j = mag_num, D = -r; j - 1 > 0; j--, D = -D) {
				if ((magnet[j - 1][2] ^ magnet[j][6]) > 0) spin[j - 1] = D;
				else break;
			}

			for (int j = 1; j < 5; j++) {
				if (spin[j] != 0) rotate(j, spin[j]);
			}
		}

		int answer = 0;
		for (int i = 1; i < 5; i++) {
			if (magnet[i][0] == 1) {
				answer += pow(2, i - 1);
			}
		}
		cout << "#" << t << " " << answer << "\n";
	}
}