#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k){
    int answer = 0;
    answer = numbers[(--k * 2) % numbers.size()];
    return answer;
}