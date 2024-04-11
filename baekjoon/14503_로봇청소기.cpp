#include <iostream>
#include <vector>

using namespace std;

int N, M, d;
int answer = 0;
int graph[51][51];
int visited[51][51];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(pair<int,int> start){
    if(visited[start.first][start.second] == 0){
        visited[start.first][start.second] = 1;
        answer++;
    }

    for(int i = 0; i < 4; i++){
        int next_d = (d + 3 - i) % 4;
        int nx = start.first + dx[next_d];
        int ny = start.second + dy[next_d];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M || graph[nx][ny] == 1) continue;

        if(graph[nx][ny] == 0 && visited[nx][ny] == 0){
            d = next_d;
            dfs({nx, ny});
        }
    }

    int next_d = (d + 2) % 4;
    int nx = start.first + dx[next_d];
    int ny = start.second + dy[next_d];

    if(graph[nx][ny] != 0){
        cout << answer;
        exit(0);
    }
    dfs({nx, ny});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    pair<int,int> start;
    cin >> start.first >> start.second >> d;
    
    for(int i = 0; i < N; i++){
        for(int k = 0; k < M; k++){
            cin >> graph[i][k];
        }
    }

    dfs(start);
}