#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;

	map<string, int> week = { {"MON", 6}, {"TUE", 5}, {"WED", 4}, {"THU", 3}, {"FRI", 2}, {"SAT", 1}, {"SUN", 7} };

	for (int t = 1; t <= T; t++) {
		string day;
		cin >> day;

		cout << "#" << t << " " << week[day] << "\n";
	}
}