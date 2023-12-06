#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(auto x : s){
        for(int i = 0; i < index; i++){
            if(x+1 > 'z') x -= 26;
            
            x++;
            if(skip.find(x) != string::npos){
                i--;
            }
        }
        answer += x;
    }
    
    
    return answer;
}