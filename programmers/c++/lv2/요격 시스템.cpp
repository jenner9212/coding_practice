#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int index = 0;
    
    sort(targets.begin(), targets.end(), cmp);
    
    for(auto t: targets){
        if(index <= t[0]){
            index = t[1];
            answer++;
        }
    }
    
    return answer;
}