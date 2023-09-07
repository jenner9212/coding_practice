#include <iostream>
#include <vector>

using namespace std;

long long factorial(int x, int y){
    long long ans = 1;
    for(int i = 1; i <= y; i++){
        ans = (ans * x) / i;
        x--;
    }
    return ans;
}

int solution(int balls, int share) {
    long long answer = 0;
    answer = factorial(balls, share);
    return answer;
}