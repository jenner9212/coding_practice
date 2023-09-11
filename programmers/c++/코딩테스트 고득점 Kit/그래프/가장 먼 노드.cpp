#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int start = 1;
vector<pair<int,int>> graph[20001];
int d[20001];

void dijkstra(){
    priority_queue<pair<int,int>> pq;
    pq.push({start, 0});
    d[start] = 0;
    
    while(!pq.empty()){
        int curNode = pq.top().first;
        int curDist = -pq.top().second;
        pq.pop();
        
        if(curDist > d[curNode]) continue;
        
        for(auto edge : graph[curNode]){
            int nNode = edge.first;
            int cost = edge.second;
            int nCost = cost + curDist;
            
            if(nCost < d[nNode]){
                d[nNode] = nCost;
                pq.push({nNode, -nCost});
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    fill_n(d, n+1, 999999);
    
    for(auto e: edge){
        graph[e[0]].push_back({e[1], 1});
        graph[e[1]].push_back({e[0], 1});
    }
    
    dijkstra();
    
    int max_d = *max_element(d+1, d+n+1);
    
    for(int i = 1; i <= n; i++){
        if(max_d == d[i]) answer++;
    }
    
    return answer;
}