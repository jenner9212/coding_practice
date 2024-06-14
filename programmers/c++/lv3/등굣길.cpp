#include <string>
#include <vector>

using namespace std;

int map[101][101];
int mod = 1e9 + 7;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i = 0; i < puddles.size(); i++){
        map[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    map[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= m; k++){
            if(map[i][k] == -1) continue;
            int x = 0;
            int y = 0;
            
            if(map[i - 1][k] != -1) x = map[i - 1][k];
            if(map[i][k - 1] != -1) y = map[i][k - 1];
            map[i][k] += (x + y) % mod;
        }
    }
    answer = map[n][m];
    
    return answer;
}