#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    if(n % 2 == 0){
        for(int i = 1; i < n / 2 - 2; i++){
            int num = i;
            for(int k = i + 1; k < n / 2; k++){
                num += k;
                if(num == n){
                    answer++;
                    break;
                }
                if(num > n) break;
            }
        }
        answer++;
    }
    else if(n == 1){
        answer = 1;
    }
    else{
        for(int i = 1; i < n / 2; i++){
            int num = i;
            for(int k = i + 1; k < n / 2; k++){
                num += k;
                if(num == n){
                    answer++;
                    break;
                }
                if(num > n) break;
            }
        }
        answer += 2;
    }
    
    return answer;
}