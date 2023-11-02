#include <iostream>

using namespace std;

int n, m, cnt = 0;
int grid[4][4];
bool visited[4][4];
pair<int,int> dest[16];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(pair<int,int> start, int index){
    if(start == dest[index]){
        if(index == m - 1){
            cnt++;
            return;
        }
        else index++;
    }

    int x = start.first;
    int y = start.second;
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(visited[nx][ny] == true) continue;
        if(grid[nx][ny] == 1) continue;

        dfs({nx, ny}, index);
    }
    visited[x][y] = false;
    return;
}

int main()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            cin >> grid[i][k];
        }
    }

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        dest[i] = {x-1, y-1};
    }

    dfs(dest[0], 1);

    cout << cnt;

    return 0;
}