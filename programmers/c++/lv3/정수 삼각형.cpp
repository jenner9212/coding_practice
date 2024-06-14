#include <string>
#include <vector>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i < triangle.size(); i++){
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for(int k = 1; k <= i; k++){
            dp[i][k] = max(dp[i - 1][k - 1], dp[i - 1][k]) + triangle[i][k];
        }
    }
    
    for(int i = 0; i < triangle.size(); i++){
        answer = max(answer, dp[triangle.size() - 1][i]);
    }
    
    return answer;
}