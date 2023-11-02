#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long find_m(vector<long long> v){
    vector<long long> dp(v.size());
    
    dp[0] = v[0];
    for(int i = 1; i < dp.size(); i++){
        dp[i] = max(dp[i-1] + v[i], v[i]);
    }
    
    return *max_element(dp.begin(), dp.end());
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<long long> v1;
    vector<long long> v2;
    
    for(int i = 0; i < sequence.size(); i++){
        if(i % 2 == 0){
            v1.push_back(-sequence[i]);
            v2.push_back(sequence[i]);
        }
        else{
            v1.push_back(sequence[i]);
            v2.push_back(-sequence[i]);
        }
    }
    
    answer = max(find_m(v1), find_m(v2));
    
    return answer;
}