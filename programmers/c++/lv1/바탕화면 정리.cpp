#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    pair<int,int> minp = {51,51};
    pair<int,int> maxp = {-1,-1};

    for(int i = 0; i < wallpaper.size(); i++){
        for(int k = 0; k < wallpaper[0].size(); k++){
            if(wallpaper[i][k] == '#'){
                minp.first = min(minp.first, i);
                minp.second = min(minp.second, k);
                maxp.first = max(maxp.first, i+1);
                maxp.second = max(maxp.second, k+1);
            }
        }
    }

    answer = {minp.first, minp.second, maxp.first, maxp.second};

    return answer;
}