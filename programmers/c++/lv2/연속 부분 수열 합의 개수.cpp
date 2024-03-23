#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> v;
    int n = elements.size();
    
    for(int lg = 1; lg <= n; lg++){
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int k = i; k < i + lg; k++){
                if(k >= n) sum += elements[k - n];
                else sum += elements[k];
            }
            v.push_back(sum);
        }
    }
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    answer = v.size();
    
    return answer;
}