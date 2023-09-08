#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string arr[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",
				".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                "...","-","..-","...-",".--","-..-","-.--","--.."};
map<string, char> mp;

string solution(string letter) {
    string answer = "";
    string str = "";
    stringstream ss(letter);
    char c = 'a';
    
    for(int i = 0; i <26; i++){
        mp[arr[i]] = c + i;
    }
    
    while(ss >> str){
        answer.push_back(mp[str]);
    }
    
    return answer;
}