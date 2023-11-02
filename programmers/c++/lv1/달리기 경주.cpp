#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> mp;

    for(int i = 0; i < players.size(); i++){
        mp[players[i]] = i;
    }

    for(auto c : callings){
        int index = mp[c];

        mp[players[index-1]] += 1;
        mp[players[index]] -= 1;

        auto tmp = players[index-1];
        players[index-1] = players[index];
        players[index] = tmp;
    }
    
    answer = players;
    
    return answer;
}