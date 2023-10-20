#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> s = {"aya", "ye", "woo", "ma"};
    
    for(auto b: babbling){
        bool tf = false;
        
        for(int i = 0; i < b.size(); i++){
            if(b.substr(i, 3) == s[0]) i += 2;
            else if(b.substr(i, 2) == s[1]) i += 1;
            else if(b.substr(i, 3) == s[2]) i += 2;
            else if(b.substr(i, 2) == s[3]) i += 1;
            else{
                tf = true;
                break;
            }
        }
        if(!tf) answer++;
    }
    
    return answer;
}