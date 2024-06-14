#include <iostream>

using namespace std;

int main()
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int answer = 0;
		
		for (int i = 0; i < 10; i++) {
			int x;
			cin >> x;

			if (x % 2 == 1) answer += x;
		}

		printf("#%d %d\n", test_case, answer);
	}
}