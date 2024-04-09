#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool tf(string a, string b){
    if(a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i] && b[i] != '*') return false;
    }
    
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    set<string> sid;
    sort(user_id.begin(), user_id.end());
    
    do{
        vector<string> v;
        string str = "";
        
        for(int i = 0; i < banned_id.size(); i++){
            if(tf(user_id[i], banned_id[i])){
                v.push_back(user_id[i]);
            }
        }
        
        if(v.size() == banned_id.size()){
            sort(v.begin(), v.end());
            for(int i = 0; i < v.size(); i++){
                str += v[i];
            }
            sid.insert(str);
        }
        
    }while(next_permutation(user_id.begin(), user_id.end()));
    
    answer = sid.size();
    
    return answer;
}