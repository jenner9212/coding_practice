#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n){
    vector<int> answer;
    int num = 2;

    while(n > 1){
        if(n % num == 0){
            answer.push_back(num);
            n /= num;
        }
        else{
            n++;
        }
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}