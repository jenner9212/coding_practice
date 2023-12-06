#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int cur_health = health;
    int max_time = attacks[attacks.size() - 1][0];
    
    int bandage_time = bandage[0];
    int sec_heal = bandage[1];
    int add_heal = bandage[2];
    
    int atk_index = 0;
    int cur_time = 0;
    
    for(int i = 0; i <= max_time; i++){
        if(attacks[atk_index][0] == i){
            cur_health -= attacks[atk_index][1];

            if(cur_health <= 0){
                return -1;
            }
            
            cur_time = 0;
            atk_index++;
        }
        
        else{
            if(cur_health < health){
                cur_time++;
                cur_health += sec_heal;
                
                if(cur_time == bandage_time){
                    cur_time = 0;
                    cur_health += add_heal;   
                }
                
                if(cur_health > health) cur_health = health;                
            }
        }
        
    }
    
    return cur_health;
}