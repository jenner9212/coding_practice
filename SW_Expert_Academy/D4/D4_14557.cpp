#include<iostream>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string N;
		cin >> N;

		int cnt = 0;
		for (int i = 0; i < N.size(); i++) {
			if (N[i] == '1') cnt++;
		}
		cout << "#" << t;

		if (cnt % 2 == 0) cout << " no\n";
		else cout << " yes\n";
	}

	return 0;
}