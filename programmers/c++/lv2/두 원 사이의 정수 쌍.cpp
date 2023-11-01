#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(int i = 1; i <= r2; i++){
        long long maxY = floor(sqrt(pow(r2, 2) - pow(i, 2)));
        long long minY = i >= r1 ? 0: ceil(sqrt(pow(r1, 2) - pow(i, 2)));
        
        answer += (maxY - minY + 1);
    }
    
    answer *= 4;
    
    return answer;
}