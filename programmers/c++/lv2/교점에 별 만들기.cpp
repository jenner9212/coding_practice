#include <string>
#include <vector>
#include <algorithm>

#define mm 999999999999999
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<pair<long long, long long>> v;
    long long minx = mm, maxx = -mm, miny = mm, maxy = -mm;
    
    for(int i = 0; i < line.size() - 1; i++){
        for(int k = i + 1; k < line.size(); k++){
            long long ad_bc = (long long)line[i][0] * line[k][1] - (long long)line[i][1] * line[k][0];
            if(ad_bc == 0) continue;
            
            long long x = (long long)(line[i][1] * line[k][2] - (long long)line[i][2] * line[k][1]);
            long long y = (long long)(line[i][2] * line[k][0] - (long long)line[i][0] * line[k][2]);
            
            if(x % ad_bc || y % ad_bc) continue;
            
            x /= ad_bc;
            y /= ad_bc;
            v.push_back({x, y});
            
            minx = min(x, minx);
            maxx = max(x, maxx);
            miny = min(y, miny);
            maxy = max(y, maxy);
        }
    }
    
    string str(maxx - minx + 1, '.');
    vector<string> answer(maxy - miny + 1, str);
    
    for(auto i : v){
        answer[abs(i.second - maxy)][abs(i.first - minx)] = '*';
    }
    
    return answer;
}