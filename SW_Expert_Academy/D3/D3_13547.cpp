#include<iostream>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string s;
		cin >> s;

		int win = 0, lose = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'o') win++;
			else lose++;
		}
		
		int leftover = 15 - win - lose;
		cout << "#" << t;

		if (win + leftover > lose) cout << " YES\n";
		else cout << " NO\n";
	}
}