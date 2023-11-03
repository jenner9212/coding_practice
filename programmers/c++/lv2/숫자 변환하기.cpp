#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visited[1000001];

int bfs(int x, int y, int n){
    queue<int> q;
    q.push(x);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur == y) return visited[cur];
        
        int rt[] = {cur+n, cur*2, cur*3};
        for(int i = 0; i < 3; i++){
            int nx = rt[i];
            
            if(nx > y || visited[nx] != 0) continue;
            
            visited[nx] = visited[cur] + 1;
            q.push(nx);
        }
    }
    return -1;
}

int solution(int x, int y, int n) {
    int answer = 0;  
    
    answer = bfs(x, y, n);
    
    return answer;
}