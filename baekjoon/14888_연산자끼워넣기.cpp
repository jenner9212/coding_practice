#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> nums;
int maxn = -1000000000, minn = 1000000000;

int calc(int a, int b, char op){
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else if(op == '*') return a * b;
    else{
        if(a < 0) return -((-a) / b);
        else return a / b;
    }

    return 0;
}

void bt(int idx, int cur_val, int plus, int minus, int mult, int div){
    if(idx == N){
        maxn = max(maxn, cur_val);
        minn = min(minn, cur_val);
        return;
    }

    if(plus > 0){
        bt(idx + 1, calc(cur_val, nums[idx], '+'), plus - 1, minus, mult, div);
    }
    if(minus > 0){
        bt(idx + 1, calc(cur_val, nums[idx], '-'), plus, minus - 1, mult, div);
    }
    if(mult > 0){
        bt(idx + 1, calc(cur_val, nums[idx], '*'), plus, minus, mult - 1, div);
    }
    if(div > 0){
        bt(idx + 1, calc(cur_val, nums[idx], '/'), plus, minus, mult, div - 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    nums.resize(N);

    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }
    
    int plus, minus, mult, div;
    cin >> plus >> minus >> mult >> div;

    bt(1, nums[0], plus, minus, mult, div);

    cout << maxn << "\n" << minn;
}