#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    int x = a[0] + a[1];
    int y = b[0] + b[1];
    return x > y;
}

int solution(vector<vector<int>> scores){
    int answer = 1;
    int w_score = scores[0][0] + scores[0][1];
    
    sort(scores.begin()+1, scores.end(), cmp);
    
    for(int i = 1; i < scores.size(); i++)
    {
        if(scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1]) return -1;
        
        int o_score = scores[i][0] + scores[i][1];
        
        if(w_score < o_score) answer++;
        else break;
    }
    
    int w_rank = answer;
    for(int c = 2; c < w_rank; c++){
        for(int p = 1; p < c; p++){        
            if(scores[c][0] < scores[p][0] && scores[c][1] < scores[p][1]){
                answer--;
                break;
            }
        }
    }
    return answer;
}