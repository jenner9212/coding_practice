#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    unordered_map<string, int> um;
    vector<vector<int>> graph(friends.size(), vector<int>(friends.size(), 0));
    vector<int> score(friends.size(), 0);
    
    for(int i = 0; i < friends.size(); i++){
        um.insert({friends[i], i});
    }
    
    for(int i = 0; i < gifts.size(); i++){
        stringstream ss(gifts[i]);
        string a, b;
        ss >> a >> b;
        
        graph[um[a]][um[b]]+=1;
        graph[um[b]][um[a]]-=1;
        score[um[a]]+=1;
        score[um[b]]-=1;
    }
    
    for (int i = 0; i < friends.size(); i++){
        int cnt = 0;
        
        for (int j = 0; j < friends.size(); j++)
        {
            if (graph[i][j] > 0){
                cnt+=1;
            }
            else if (graph[i][j] == 0){
                if (score[i] > score[j]){
                    cnt += 1;
                }
            }
        }
        if (cnt > answer){
            answer = cnt;
        }
    }
    
    return answer;
}