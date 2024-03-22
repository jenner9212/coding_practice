#include <string>
#include <vector>

using namespace std;

bool checktf(char c, vector<string> b){
    if(b[0][0] == c && b[1][0] == c && b[2][0] == c) return true;
    if(b[0][1] == c && b[1][1] == c && b[2][1] == c) return true;
    if(b[0][2] == c && b[1][2] == c && b[2][2] == c) return true;
    if(b[0][0] == c && b[0][1] == c && b[0][2] == c) return true;
    if(b[1][0] == c && b[1][1] == c && b[1][2] == c) return true;
    if(b[2][0] == c && b[2][1] == c && b[2][2] == c) return true;
    if(b[0][0] == c && b[1][1] == c && b[2][2] == c) return true;
    if(b[0][2] == c && b[1][1] == c && b[2][0] == c) return true;
    
    return false;
}

int solution(vector<string> board) {
    int answer = 1;
    int o = 0;
    int x = 0;
    
    for(int i = 0; i < 3; i++){
        for(int k = 0; k < 3; k++){
            if(board[i][k] == 'O') o++;
            if(board[i][k] == 'X') x++;
        }
    }
    
    if(o < x || o - x > 1) return 0;
    if(checktf('O', board) && checktf('X', board)) return 0;
    if(checktf('O', board) && !checktf('X', board) && o - x < 1) return 0;
    if(checktf('X', board) && !checktf('O', board) && o != x) return 0;
    
    return answer;
}