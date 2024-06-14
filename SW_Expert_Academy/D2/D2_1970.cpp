#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int x;
		cin >> x;

		cout << "#" << t << "\n";
		vector<int> v(8, 0);
		if (x / 50000 > 0) {
			v[0] = x / 50000;
			x %= 50000;
		}
		if (x / 10000 > 0) {
			v[1] = x / 10000;
			x %= 10000;
		}
		if (x / 5000 > 0) {
			v[2] = x / 5000;
			x %= 5000;
		}
		if (x / 1000 > 0) {
			v[3] = x / 1000;
			x %= 1000;
		}
		if (x / 500 > 0) {
			v[4] = x / 500;
			x %= 500;
		}
		if (x / 100 > 0) {
			v[5] = x / 100;
			x %= 100;
		}
		if (x / 50 > 0) {
			v[6] = x / 50;
			x %= 50;
		}
		if (x / 10 > 0) {
			v[7] = x / 10;
			x %= 10;
		}

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
	}
}