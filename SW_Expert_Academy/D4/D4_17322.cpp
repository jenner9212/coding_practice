#include<iostream>

using namespace std;

const long long mod = 1e9 + 7;
long long x, y, map[666667] = { 1, };

long long mP(long long a, long long b) {
	long long ans = 1, base = a;
	while (b > 0) {
		if (b & 1) ans = ans * base % mod;
		base = base * base % mod;
		b >>= 1;
	}
	return ans;
}

long long solve() {
	cin >> x >> y;
	if ((x + y) % 3) return 0;
	long long sn = (x + y) / 3;
	if (x < sn || 2 * sn < x) return 0;

	return map[sn] * mP(map[y - sn] * map[2 * sn - y] % mod, mod - 2) % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;

	for (int i = 1; i <= 666666; i++) {
		map[i] = (map[i - 1] * i) % mod;
	}
	for (int t = 1; t <= T; t++) {	
		cout << "#" << t << " " << solve() << "\n";
	}
}