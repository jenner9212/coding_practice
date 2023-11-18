#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) {
		int a, b, c;
		cin >> a >> b >> c;

		double x = (c - 2 * b + a) / 2.0;

		cout << fixed << setprecision(1);
		cout << "#" << t << " " << x << endl;
	}

	return 0;
}