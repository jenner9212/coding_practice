#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp1(pair<int, double> a, pair<int, double> b) {
	return a.second > b.second;
}

bool cmp2(pair<string, pair<int, double>> a, pair<string, pair<int, double>> b) {
	return a.second.first < b.second.first;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<pair<int, double>> v;
		vector <pair<string, pair<int, double>>> va;
		string sc[] = {"A+", "A0", "A-", "B+" ,"B0" ,"B-" ,"C+" ,"C0", "C-", "D0"};

		int N, K;
		cin >> N >> K;

		for (int i = 0; i < N; i++) {
			int m, l, h;
			cin >> m >> l >> h;

			double score = m * 0.35 + l * 0.45 + h * 0.2;
			v.push_back({ i + 1, score });
		}

		sort(v.begin(), v.end(), cmp1);

		int cut = N / 10, index = 0;
		for (int i = 0; i < 10; i++) {
			int cnt = 0;
			while (cnt < cut) {
				va.push_back({ sc[i], {v[index].first, v[index].second} });
				index++;
				cnt++;
			}
		}

		sort(va.begin(), va.end(), cmp2);

		printf("#%d %s\n", test_case, va[K-1].first.c_str());
	}
	return 0;
}