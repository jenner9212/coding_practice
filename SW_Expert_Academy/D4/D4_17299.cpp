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
		string num;
		cin >> num;

		int maxn = stoi(num);
		string a = "", b = "";
		
		for (int i = 0; i < num.size() - 1; i++) {
			a += num[i];
			for (int k = i + 1; k < num.size(); k++) {
				b += num[k];
			}

			if (stoi(a) + stoi(b) < maxn) maxn = stoi(a) + stoi(b);
			b = "";
		}

		cout << "#" << t << " " << maxn << "\n";
	}
}