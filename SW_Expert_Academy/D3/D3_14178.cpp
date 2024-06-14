#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, D;
		cin >> N >> D;

		int answer;
		D = D * 2 + 1;
		if (N % D != 0) answer = N / D + 1;
		else answer = N / D;

		cout << "#" << t << " " << answer << "\n";
	}
}