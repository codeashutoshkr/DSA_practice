#include<iostream>
#include<map>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

struct Player{
    int health;
    map<string, int>spells;
};

// function to display remainning spells to the user
void showSpells(const map<string, int>& spells){
    cout<<"\nAvailable Spells\n";
    for(const auto& s : spells){
        cout<<"- "<<s.first<<" (Power: " <<s.second<<" )\n";
    } 
}

// function to get user's spell choice
string getUserSpell(map<string, int>& userSpells){
    string choice;
    while(true){
        cout<<"\nChoose Your Spell\n";
        getline(cin, choice);
        if(userSpells.count(choice)){
            break;
        }
        else{
            cout<<"Invalid or Already used Spell. Try Again!\n";
        }
    }
    return choice;
}
// function to let monster choose randomly
string getMonsterSpell(map<string, int>& monsterSpells){
    srand(time(0));
    int index = rand() % monsterSpells.size();
    auto it = monsterSpells.begin();
    advance(it, index);
    return it -> first;
}

//function to  compare health and update health
void battleRound( Player& user, Player& monster, const string& userSpells,const string& monsterSpells){
    int userPower = user.spells[userSpells];
    int monsterPower = monster.spells[monsterSpells];
    cout<<"\nYour Cast: "<<userSpells<<"( Power: "<<userPower<<")";
    cout<<"\nMonster Cast: "<<monsterSpells<<"( Power: "<<monsterPower<<")\n";
    if(userPower > monsterPower){
        int damage = abs(userPower - monsterPower);
        monster.health -= damage;
        cout<<"You dealt "<<damage<<" damage to the Monster!\n";
    }
    else if(userPower < monsterPower){
        int damage = abs(monsterPower - userPower);
        user.health -= damage;
        cout << "Monster dealt " << damage << " damage to you!\n";
    }
    else {
            cout << "It's a tie! No damage.\n";
        }
        cout<<"Your Health: "<<user.health<<" | Monster Health: "<<monster.health<<"\n";
}

int main(){
    srand(time(0));
//initialize spells
    // User spells
 map<string, int> UserSpells = {
    {"Fireball", 11},
    {"Lightning", 20},
    {"Freeze", 37},
    {"Wind Slash", 40},
    {"Meteor", 55}
};

// Monster spells
map<string, int> monsterSpells = {
    {"Acid Spray", 13},
    {"Shadow Strike", 25},
    {"Curse", 33},
    {"Poison Mist", 45},
    {"Hellfire", 47}
};
    Player user = {100, UserSpells};
    Player monster = {100, monsterSpells};
    cout<<"\n-> Welcome To THE FIGHT CLUD\n";
    cout<<"-> The first rule of the FIGHT CLUD: You Don't Talk About FIGHT CLUD!\n";
    cout<<"-> Remember You can use one spell only once.\n";
    cout<<"-> Rules: You win if you defeat the monster or you lose if monster health is grater than you or equal to your health. Good Luck!\n";

    while(!user.spells.empty() && user.health > 0 && monster.health > 0){
        showSpells(user.spells);
        string userSpell = getUserSpell(user.spells);
        string monsterSpell = getMonsterSpell(monster.spells);
        battleRound(user, monster, userSpell, monsterSpell);
        // Remove used spells
        user.spells.erase(userSpell);
      //  monster.spells.erase(monsterSpell);

    }
    //Final Result
    cout<<"\nFinal Result:\n";

    if (user.health <= 0) {
        cout << "You lost! Monster wins.\n";
    } else if (monster.health <= 0) {
        cout << "Hurrah! You win! Monster is defeated.\n";
    } else if (user.health > monster.health) {
        cout << "Champ! You win by higher health!\n";
    } else if (monster.health > user.health) {
        cout << "Great Game! Monster wins by higher health.\n";
    } else {
        cout << "It's a tie! Monster wins by rule. Remember Victors Don't Give Up!\n";
    }

    return 0;
}