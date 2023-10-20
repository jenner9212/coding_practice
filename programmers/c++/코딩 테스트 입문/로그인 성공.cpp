#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    vector<string> id;
    vector<string> pw;
    
    for(int i = 0; i < db.size(); i++){
        id.push_back(db[i][0]);
        pw.push_back(db[i][1]);
    }
    
    auto it1 = find(id.begin(), id.end(), id_pw[0]);
    
    if(it1 == id.end()){
        answer = "fail";
    }
    else if(pw[it1 - id.begin()] == id_pw[1]){
        answer = "login";
    }
    else{
        answer = "wrong pw";
    }
    
    return answer;
}