#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(true){
        if(n < a) break;
        
        int l = n % a;
        
        n = (n / a) * b;
        answer += n;
        n += l;
    }
    
    return answer;
}