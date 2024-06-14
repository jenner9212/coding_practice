#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		bool tf = false;
		int num;
		cin >> num;
		
		for (int i = 1; i <= 9; i++) {
			for (int k = i; k <= 9; k++) {
				if (num == i * k) tf = true;
			}
		}

		cout << "#" << test_case << " ";

		if (tf) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}