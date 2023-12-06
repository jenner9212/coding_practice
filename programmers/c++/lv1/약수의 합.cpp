#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;

    if(n == 0) return 0;
    if(n == 1) return 1;

    for(int i = 1; i < n/2; i++){
        if(n % i == 0){
            int x = n / i;
            v.push_back(x);
            v.push_back(i);
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 0; i < v.size(); i++){
        answer += v[i];
    }

    return answer;
}