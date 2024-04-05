#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(int i=0; i<balls.size(); i++){
        int total = 999999999;
        
        if(startX != balls[i][0] || startY <= balls[i][1]){
            total = min(total, (int)(pow(startX - balls[i][0], 2) + pow(startY + balls[i][1], 2)));
        }
        if(startX >= balls[i][0] || startY != balls[i][1]){
            total = min(total, (int)(pow(startX - 2*m+balls[i][0], 2) + pow(startY - balls[i][1], 2)));
        }
        if(startX != balls[i][0] || startY >= balls[i][1]){
            total = min(total, (int)(pow(startX - balls[i][0], 2) + pow(startY - 2*n+balls[i][1], 2)));
        }
        if(startX <= balls[i][0] || startY != balls[i][1]){
            total = min(total, (int)(pow(startX + balls[i][0], 2) + pow(startY - balls[i][1], 2)));
        }
        
        answer.push_back(total);
    }
    
    return answer;
}