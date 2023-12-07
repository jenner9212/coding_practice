#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isOne(vector<int> n) {
    return find(n.begin(), n.end(), 1) != n.end();
}

int case1(vector<vector<int>> v, int n){
    int cnt = 0;
    
    for(int i = 0; i < v.size(); i++){
        if(v[i][0] == n){
            cnt++;
            for(int k = 0; k < v[0].size(); k++){
                if(v[i][k] == 0) v[i][k] = 1;
                else v[i][k] = 0;
            }
        }
    }
    
    for(int i = 0; i < v[0].size(); i++){
        if(v[0][i] == 1){
            cnt++;
            for(int k = 0; k < v.size(); k++){
                if(v[k][i] == 0) v[k][i] = 1;
                else v[k][i] = 0;
            }
        }
    }
    
    auto it = find_if(v.begin(), v.end(), isOne);
    
    if(it == v.end()){
        return cnt;
    }
    else{
        return -1;
    }
}

int case2(vector<vector<int>> v, int n){
    int cnt = 0;
    
    for(int i = 0; i < v[0].size(); i++){
        if(v[0][i] == n){
            cnt++;
            for(int k = 0; k < v.size(); k++){
                if(v[k][i] == 0) v[k][i] = 1;
                else v[k][i] = 0;
            }
        }
    }
    
    
    for(int i = 0; i < v.size(); i++){
        if(v[i][0] == 1){
            cnt++;
            for(int k = 0; k < v[0].size(); k++){
                if(v[i][k] == 0) v[i][k] = 1;
                else v[i][k] = 0;
            }
        }
    }
    
    auto it = find_if(v.begin(), v.end(), isOne);
    
    if(it == v.end()){
        return cnt;
    }
    else{
        return -1;
    }
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = 0;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    vector<vector<int>> v(beginning.size(), vector<int>(beginning[0].size()));
    
    for(int i = 0; i < beginning.size(); i++){
        for(int k = 0; k < beginning[0].size(); k++){
            if(beginning[i][k] == target[i][k]) v[i][k] = 0;
            
            else v[i][k] = 1;
        }
    }
    
    cnt1 = case1(v, 0);
    cnt2 = case2(v, 0);
    cnt3 = case1(v, 1);
    cnt4 = case2(v, 1);
    
    answer = min({cnt1, cnt2, cnt3, cnt4});
    
    return answer;
}