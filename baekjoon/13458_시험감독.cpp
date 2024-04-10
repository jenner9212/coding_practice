#include <iostream>
#include <vector>

using namespace std;

int N;
long long B, C;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    cin >> B >> C;

    long long answer = 0;
    for (int i = 0; i < N; ++i) {
        answer++; 
        A[i] -= B; 
        
        if (A[i] > 0) {
            answer += A[i] / C; 
            if (A[i] % C != 0) { 
                answer++;
            }
        }
    }

    cout << answer << '\n';
}