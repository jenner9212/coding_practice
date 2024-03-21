#include <string>
#include <vector>

using namespace std;

int answer = 99999999;
int ml;
vector<string> ms;

void dfs(int index, int m, int cnt, vector<int> p){
    if(index == 0){
        if(ml - m > 5){
            cnt += 5;
            m += 5;
        }
        else{
            cnt += ml - m;
            m += ml - m;
        }
    }
    else if(index == 1){
        if(ml - m > 5){
            for(int i = m; i < m + 5; i++){
                if(ms[i] == "diamond"){
                    cnt += 5;
                }
                else cnt += 1;
            }
            m += 5;
        }
        else{
            for(int i = m; i < ml; i++){
                if(ms[i] == "diamond"){
                    cnt += 5;
                }
                else cnt += 1;
            }
            m += ml - m;
        }
    }
    else{
        if(ml - m > 5){
            for(int i = m; i < m + 5; i++){
                if(ms[i] == "diamond"){
                    cnt += 25;
                }
                else if(ms[i] == "iron"){
                    cnt += 5;
                }
                else cnt += 1;
            }
            m += 5;
        }
        else{
            for(int i = m; i < ml; i++){
                if(ms[i] == "diamond"){
                    cnt += 25;
                }
                else if(ms[i] == "iron"){
                    cnt += 5;
                }
                else cnt += 1;
            }
            m += ml - m;
        }
    }
    
    if(ml == m){
        if(answer > cnt) answer = cnt;
        return;
    }
    
    if(p[0] == 0 && p[1] == 0 && p[2] == 0){
        if(answer > cnt) answer = cnt;
        return;
    }
    
    for(int i = 0; i < 3; i++){
        if(p[i] == 0) continue;
        p[i]--;
        dfs(i, m, cnt, p);
        p[i]++;
    }
    
}

int solution(vector<int> picks, vector<string> minerals) {
    ml = minerals.size();
    ms = minerals;
    
    if(picks[0] == 0 && picks[1] == 0 && picks[2] == 0){
        answer = 0;
    }
    
    else{
        for(int i = 0; i < 3; i++){
            if(picks[i] == 0) continue;
            picks[i]--;
            dfs(i, 0, 0, picks);
            picks[i]++;
        }
    }
    
    return answer;
}