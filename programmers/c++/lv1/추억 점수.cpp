#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    for(auto p1 : photo){
        int score = 0;
        for(auto p2 : p1){
            auto iter = find(name.begin(), name.end(), p2);
            if(iter == name.end()) continue;
            else{
                score += yearning[iter - name.begin()];
            }
        }
        answer.push_back(score);
    }
    
    return answer;
}