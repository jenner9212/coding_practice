#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool visited[200];

void dfs(vector<int> v[], int start){
    visited[start] = true;
    for(int i = 0; i < v[start].size(); i++){
        int x = v[start][i];
        if(!visited[x]){
            dfs(v, x);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<int> v[n];

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            if(k == i) continue;
            if(computers[i][k] == 1){
                v[i].push_back(k);
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(v, i);
            answer++;
        }
    }

    return answer;
}