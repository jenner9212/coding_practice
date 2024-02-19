#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string str1;
    int mins = 999999, maxs = -999999;
    
    while(ss >> str1){
        int n = stoi(str1);
        
        if(n >= maxs) maxs = n;
        if(n <= mins) mins = n;
    }
    
    answer += to_string(mins);
    answer += ' ';
    answer += to_string(maxs);
    
    return answer;
}