#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long fact(int n){
    long long num = 1;
    for(int i = 1; i <= n; i++){
        num *= i;
    }
    return num;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    
    for(int i = 1; i <= n; i++){
        v.push_back(i);
    }
    
    while(n > 0){
        long long index = fact(n - 1);
        int i = (k - 1) / index; 
        answer.push_back(v[i]);
        v.erase(v.begin() + i);
        
        k -= i * index;
        n--; 
    }
    
    return answer;
}