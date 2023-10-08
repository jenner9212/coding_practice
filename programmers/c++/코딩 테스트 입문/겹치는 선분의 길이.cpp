#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    int line[200] = {};

    for(auto l : lines){
        for(int i = l[0]; i < l[1]; i++){
            line[i+100]++;
        }
    }

    for(int i = 0; i < 200; i++){
        if(line[i] >= 2) answer++;
    }

    return answer;
}
