#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto n : numbers){
        long long bit = 1;
        
        while((n & bit) > 0){
            bit = bit << 1;
        }
        answer.push_back(n + bit - (bit >> 1));
    }
    
    return answer;
}