#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;

    for(int i = -500; i <= 500; i++){
        int cnt = 0;
        for(int k = i; k < i+num; k++){
            cnt += k;
        }
        if(cnt == total){
            for(int k = i; k < i+num; k++){
                answer.push_back(k);
            }
            break;
        }
    }

    return answer;
}