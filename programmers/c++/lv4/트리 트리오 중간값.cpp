#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[250001];
int visited[250001];
vector<int> dist[250001];

int maxN;

void dfs(int n, int cnt){
    if(maxN <= cnt){
        maxN = cnt;
        dist[maxN].push_back(n);
    }
    
    visited[n] = 1;
    
    for(int i = 0; i < graph[n].size(); i++){
        int nextN = graph[n][i];
        if(visited[nextN] != 1){
            dfs(nextN, cnt+1);
        }
    }
    visited[n] = 0;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    int nextNode;
    
    for(auto e: edges){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    dfs(1, 0);
    
    for(int i = 0; i < 2; i++){
        nextNode = dist[maxN][0];
        maxN = 0;
        fill(dist, dist + 250001, vector<int>());
        
        dfs(nextNode, 0);
        
        if(dist[maxN].size() > 1){
            return maxN;
        }
    }
    
    answer = maxN - 1;
    
    return answer;
}