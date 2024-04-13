#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

void dfs(const string& airport, map<string, vector<string>>& tickets_map, stack<string>& st) {
    while (!tickets_map[airport].empty()) {
        string next_airport = tickets_map[airport].back();
        tickets_map[airport].pop_back();
        dfs(next_airport, tickets_map, st);
    }
    st.push(airport);
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    stack<string> st;
    map<string, vector<string>> tickets_map;
    
    for (auto& ticket : tickets) {
        tickets_map[ticket[0]].push_back(ticket[1]);
    }
    for (auto& [key, value] : tickets_map) {
        sort(value.rbegin(), value.rend());
    }

    dfs("ICN", tickets_map, st); 

    while (!st.empty()) {
        answer.push_back(st.top());
        st.pop();
    }

    return answer;
}
