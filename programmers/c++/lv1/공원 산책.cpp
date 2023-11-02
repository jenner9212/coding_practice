#include <string>
#include <vector>

using namespace std;

int H, W;
int grid[50][50];

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    W = park[0].size();
    H = park.size();
    pair<int,int> start;
    
    for(int i = 0; i < H; i++){
        for(int k = 0; k < W; k++){
            if(park[i][k] == 'S'){
                start = {i, k};
            }
            if(park[i][k] == 'O'){
                grid[i][k] = 0;
            }
            else if(park[i][k] == 'X'){
                grid[i][k] = 1;
            }
        }
    }
    
    for(auto r : routes){
        bool pa = true;
        char dir = r[0];
        int n = r[2] - '0';
        
        int x = start.first, y = start.second;
        int nx, ny;
        
        if(dir == 'N'){
            for(int i = 1; i <= n; i++){
                if(grid[x-i][y] == 1){
                    pa = false;
                    break;
                }
            }
            if(pa == true){
                nx = x - n;
                ny = y;
            }
            else{
                nx = x;
                ny = y;
            }
            
        }
        else if(dir == 'S'){
            for(int i = 1; i <= n; i++){
                if(grid[x+i][y] == 1){
                    pa = false;
                    break;
                }
            }
            if(pa == true){
                nx = x + n;
                ny = y;
            }
            else{
                nx = x;
                ny = y;
            }
        }
        else if(dir == 'W'){
            for(int i = 1; i <= n; i++){
                if(grid[x][y-i] == 1){
                    pa = false;
                    break;
                }
            }
            if(pa == true){
                nx = x;
                ny = y - n;
            }
            else{
                nx = x;
                ny = y;
            }
        }
        else{
            for(int i = 1; i <= n; i++){
                if(grid[x][y+i] == 1){
                    pa = false;
                    break;
                }
            }
            if(pa == true){
                nx = x;
                ny = y + n;
            }
            else{
                nx = x;
                ny = y;
            }
        }
        
        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        
        start = {nx, ny};
    }
    
    answer = {start.first, start.second};
    
    return answer;
}