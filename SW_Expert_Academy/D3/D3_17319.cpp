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
		int N;
		cin >> N;
		string str;
		cin >> str;
		
		bool tf = true;
		if (N % 2 == 1) tf = false;
		else {
			string left = "";
			string right = "";
			for (int i = 0; i < N; i++) {
				if (i < N / 2) left += str[i];
				else right += str[i];
			}

			if (left.size() == right.size()) {
				for (int i = 0; i < left.size(); i++) {
					if (left[i] != right[i]) {
						tf = false;
						break;
					}
				}
			}
			else tf = false;
		}

		if(tf) cout << "#" << t << " Yes\n";
		else cout << "#" << t << " No\n";
	}
}