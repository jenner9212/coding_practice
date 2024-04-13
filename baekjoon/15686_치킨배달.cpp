#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
int map[51][51];
int minl = numeric_limits<int>::max();
int answer = minl;
vector<pair<int,int>> house;

void calc(vector<pair<int,int>> chicken){
    vector<int> house_l(house.size(), minl);

    for(int i = 0; i < chicken.size(); i++){
        for(int k = 0; k < house.size(); k++){
            int absl = abs(chicken[i].first - house[k].first) + abs(chicken[i].second - house[k].second);
            house_l[k] = min(house_l[k], absl);
        }
    }

    int cnt = 0;
    for(int i = 0; i < house_l.size(); i++){
        cnt += house_l[i];
    }
    answer = min(answer, cnt);
}

void bt(vector<pair<int,int>> chicken, vector<pair<int,int>>& sel_chick, int idx){
    if(sel_chick.size() == M){
        calc(sel_chick);
        return;
    }

    for(int i = idx; i < chicken.size(); i++){
        sel_chick.push_back(chicken[i]);
        bt(chicken, sel_chick, i+1);
        sel_chick.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    vector<pair<int,int>> chicken, sel_chick;

    for(int i = 1; i <= N; i++){
        for(int k = 1; k <= N; k++){
            cin >> map[i][k];
            if(map[i][k] == 1) house.push_back({i, k});
            if(map[i][k] == 2) chicken.push_back({i, k});
        }
    }

    if(chicken.size() <= M){
        calc(chicken);
    }
    else{
        bt(chicken, sel_chick, 0);
    }

    cout << answer;
}