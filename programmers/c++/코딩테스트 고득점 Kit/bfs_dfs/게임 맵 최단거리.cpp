#include <vector>
#include <queue>

using namespace std;

int n, m;
int visited[101][101];
int dist[101][101];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(vector<vector<int>> maps, vector<int> start){
    queue<pair<int,int>> q;
    
    q.push({start[0], start[1]});
    dist[start[0]][start[1]] = 1;
    visited[start[0]][start[1]] = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if(visited[nx][ny] == 1)
                continue;
            if(maps[nx][ny] == 0)
               continue; 
            
            visited[nx][ny] = 1;
            q.push({nx,ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    vector<int> start = {0,0};
    n = maps.size();
    m = maps[0].size();
    
    bfs(maps, start);
    
    if(dist[n-1][m-1] == 0) answer = -1;
    else answer = dist[n-1][m-1];
    
    return answer;
}