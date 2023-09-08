#include <iostream>
#include <string>
using namespace std;

int palindrome(string s, int left, int right){
    while(left >= 0 && right <= s.size()){
        if(s[left] != s[right]) break;
        left--;
        right++;
    }
    return right - left - 1;
}

int solution(string s)
{
    int answer=0;

    for(int i = 0; i < s.size(); i++){ // 0부터 시작하는 이유: 1자리 문자도 팰린드롬으로 한다.
        int even = palindrome(s, i - 1, i);
        int odd = palindrome(s, i, i);
        int max_n = max(even, odd);
        answer = max(answer, max_n);
    }

    return answer;
}