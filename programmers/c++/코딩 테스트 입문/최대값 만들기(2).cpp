#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0, n = numbers.size();
    
    sort(numbers.begin(), numbers.end());
    
    answer = max((numbers[n-1] * numbers[n-2]), numbers[0] * numbers[1]);
    
    return answer;
}