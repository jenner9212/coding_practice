#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

    // == accumulate
    for(auto a : arr){
        answer += a;
    }

    answer /= arr.size();

    return answer;
}