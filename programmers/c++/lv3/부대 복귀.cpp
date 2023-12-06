#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int dist[100001];

void bfs(int start, int dest){
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        if(x == dest) break;
        
        for(int i = 0; i < graph[x].size(); i++){
            int y = graph[x][i];
            
            if(visited[y] != 1){
                visited[y] = 1;
                q.push(y);
                dist[y] = dist[x] + 1;
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    for(auto r : roads){
        graph[r[0]].push_back(r[1]);
        graph[r[1]].push_back(r[0]);
    }
    
    for(auto s : sources){
        if(s == destination) answer.push_back(0);
        else{
            bfs(s, destination);
            if(dist[destination] == 0) answer.push_back(-1);
            else answer.push_back(dist[destination]);
        }
        
        fill(visited, visited + 100001, 0);
        fill(dist, dist + 100001, 0);
    }
    
    return answer;
}