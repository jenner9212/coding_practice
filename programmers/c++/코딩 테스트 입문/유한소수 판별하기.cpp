#include <string>
#include <vector>

using namespace std;

int func(int a, int b){
    if(a % b == 0) return b;
    return func(b, a % b);
}

int solution(int a, int b) {
    int answer = 1;
    
    b /= func(b, a);
    
    while(true){
        if(b % 2 == 0) b /= 2;
        else if(b % 5 == 0) b /= 5;
        else break;
    }
    
    if(b != 1) answer = 2;
    
    return answer;
}