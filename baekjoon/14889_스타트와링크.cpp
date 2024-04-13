#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int N;
vector<vector<int>> S;
int min_dif = numeric_limits<int>::max();

void bt(vector<int>& team, int cnt, int start){
    if(cnt == N / 2){
        vector<bool> team_a(N, false);
        vector<int> team_o;

        for(auto m : team){
            team_a[m] = true;
        }

        for(int i = 0; i < N; i++){
            if(!team_a[i]){
                team_o.push_back(i);
            }
        }

        int a_t = 0, o_t = 0;
        for(int i = 0; i < N / 2; i++){
            for(int k = i + 1; k < N / 2; k++){
                a_t += S[team[i]][team[k]] + S[team[k]][team[i]];
                o_t += S[team_o[i]][team_o[k]] + S[team_o[k]][team_o[i]];
            }
        }

        min_dif = min(min_dif, abs(a_t - o_t));
    }

    for(int i = start; i < N; i++){
        team.push_back(i);
        bt(team, cnt + 1, i + 1);
        team.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    S.resize(N, vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int k = 0; k < N; k++){
            cin >> S[i][k];
        }
    }

    vector<int> team;
    bt(team, 0, 0);

    cout << min_dif;
}