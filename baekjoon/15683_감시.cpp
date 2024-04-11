#include <iostream>
#include <vector>

using namespace std;

int N, M;
int answer = 82;
vector<vector<int>> graph(8, vector<int>(8, 0));
vector<pair<int,int>> cctv;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void search(int x, int y, int d){
    d %= 4;

    while(true){
        x += dx[d];
        y += dy[d];

        if(x < 0 || x >= N || y < 0 || y >= M) break;
        if(graph[x][y] == 6) break;
        if(graph[x][y] != 0) continue;

        graph[x][y] = -1;
    }
}

void dfs(int idx){
    if(idx == cctv.size()){
        int cnt = 0;
        for(int i = 0; i < N; i++){
            for(int k = 0; k < M; k++){
                if(graph[i][k] == 0) cnt++;
            }
        }
        answer = min(answer, cnt);
        return;
    }

    int x = cctv[idx].first;
    int y = cctv[idx].second;
    vector<vector<int>> sg(8, vector<int>(8, 0));

    for(int i = 0; i < 4; i++){
        for(int k = 0; k < N; k++){
            for(int j = 0; j < M; j++){
                sg[k][j] = graph[k][j];
            }
        }
        if(graph[x][y] == 1){
            search(x, y, i);
        }
        else if(graph[x][y] == 2){
            search(x, y, i);
            search(x, y, i + 2);
        }
        else if(graph[x][y] == 3){
            search(x, y, i);
            search(x, y, i + 1);
        }
        else if(graph[x][y] == 4){
            search(x, y, i);
            search(x, y, i + 1);
            search(x, y, i + 2);
        }
        else if(graph[x][y] == 5){
            search(x, y, i);
            search(x, y, i + 1);
            search(x, y, i + 2);
            search(x, y, i + 3);
        }

        dfs(idx + 1);

        for(int k = 0; k < N; k++){
            for(int j = 0; j < M; j++){
                graph[k][j] = sg[k][j];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int k = 0; k < M; k++){
            cin >> graph[i][k];
            if(graph[i][k] != 0 && graph[i][k] != 6) cctv.push_back({i, k});
        }
    }

    dfs(0);

    cout << answer;
}