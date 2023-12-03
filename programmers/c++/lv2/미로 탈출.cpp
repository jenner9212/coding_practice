#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int visited[101][101];

int solution(vector<string> maps) {
    int answer = -1;
    pair<int,int> start;
    bool L = false;
    
    for(int i = 0; i < maps.size(); i++){
        for(int k = 0; k < maps[i].size(); k++){
            if(maps[i][k] == 'S'){
                start = {i, k};
                break;
            }
        }
    }
    
    queue<pair<int,int>> q;
    q.push({start.first, start.second});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        if(L && maps[x][y] == 'E'){
            answer = visited[x][y];
            break;
        }
        
        if(maps[x][y] == 'L' && !L){
            L = true;
            int cur = visited[x][y];
            
            q = queue<pair<int,int>>();
            fill_n(visited[0], 101*101, 0);
            
            visited[x][y] = cur;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[0].size()) continue;
            
            if(visited[nx][ny] == 0 && maps[nx][ny] != 'X'){
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }
    
    return answer;
}