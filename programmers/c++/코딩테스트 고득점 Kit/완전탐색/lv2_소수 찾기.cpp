#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int n){
    if(n < 2) return false;

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> v;
    vector<int> n;

    for(int i = 0; i < numbers.size(); i++){
        v.push_back(numbers[i]);
    }
    sort(v.begin(), v.end());

    do{
        string temp = "";

        for(int i = 0; i < v.size(); i++){
            temp += v[i];
            n.push_back(stoi(temp));
        }
    }while(next_permutation(v.begin(), v.end()));

    sort(n.begin(), n.end());
    n.erase(unique(n.begin(), n.end()), n.end());

    for(int i = 0; i < n.size(); i++){
        if(isPrime(n[i])){
            answer++;
        }
    }

    return answer;
}