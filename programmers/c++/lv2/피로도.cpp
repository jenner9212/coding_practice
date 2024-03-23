#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmd(vector<int> a, vector<int> b){
    return a[0] > b[0];
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sort(dungeons.begin(), dungeons.end());
    do{
        int cnt = 0;
        int ck = k;
        
        for(int i = 0; i < dungeons.size(); i++){
            if(dungeons[i][0] <= ck){
                cnt++;
                ck -= dungeons[i][1];
            }
        }
        if(cnt > answer) answer = cnt;
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}