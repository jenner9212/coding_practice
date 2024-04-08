#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

int solution(vector<int> a)
{
    int answer = 0;
    unordered_map<int, int> um;
    
    for (int i = 0; i < a.size(); i++){
        um[a[i]]++;
    }
    
    for (auto u : um){
        if (u.second * 2 <= answer) continue;
        
        int len = 0;
        
        for (int i = 0; i < a.size() - 1; i++){
            if (a[i] == a[i + 1]) continue;
            if (a[i] != u.first && a[i + 1] != u.first) continue;
            
            len += 2;
            i++;
        }
        
        answer = max(answer, len);
    }
    
    return answer;
}