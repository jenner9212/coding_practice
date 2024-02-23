#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(auto t : targets){
        int cnt = 0;
        
        for(int i = 0; i < t.size(); i++){
            int minn = 101;
            
            for(int k = 0; k < keymap.size(); k++){
                auto it = keymap[k].find(t[i]);
                if(it == string::npos) continue;
                
                if(minn > it) minn = it;
            }
            if(minn == 101){
                cnt = -1;
                break;
            }
            cnt += minn + 1;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}