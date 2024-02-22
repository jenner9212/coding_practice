#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int a : s){
        if(a >= 97 && a <= 122){
            if(a + n > 122){
                a += n - 26;
                answer += a;
            }
            else{
                a += n;
                answer += a;
            }
        }
        else if(a >= 65 && a <= 90){
            if(a + n > 90){
                a += n - 26;
                answer += a;
            }
            else{
                a += n;
                answer += a;
            }
        }
        else{
            answer += ' ';
        }
    }
    
    return answer;
}