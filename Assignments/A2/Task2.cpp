#include <iostream>
#include <vector>
using namespace std;

class Weapon {
protected:
    vector<string> weaponsList;

public:
    Weapon() {
        weaponsList = {"Sword", "Guns", "Blade", "Dagger", "Axe"};
    }

    void use() {
        cout << "Choose your Weapon!" << endl;
        int i;
        for (i = 0; i < weaponsList.size(); ++i) {
            cout << i + 1 << ". " << weaponsList[i] << endl;
        }
        cout << "Pick your weapon( 1-5 ): "<< endl;
        cin >> i;
        cout << weaponsList[i-1] << " selected!" << endl;
    }
};

class Player {
protected:
    int playerID;
    int health;
    string playerName;

public:
    Player(int id, string name) : playerID(id), playerName(name), health(100) {}
};

class Enemy : public Player {
protected:
    int damage;

public:
    Enemy(int id, string name, int damage) : Player(id, name), damage(damage) {
        if (damage < 1 || damage > 10){
            cout<<"Damage reduced to 1 as it exceeds the limit!"<<endl;
            this->damage=1;
        }
    }

    void healthDec(int damage){
        this->health -= damage;
        cout << "Enemy's health: " << health << endl;
    }

    void attack(Weapon &weapon);
};

class Character : public Player {
protected:
    int level, points;
    string experience;

public:
    Character(int id, string name, int lvl, int pts, string exp) : Player(id, name), level(lvl), points(pts), experience(exp) {}

    void levelUp() {
        if (points >= 10) {
            if (experience == "Beginner") {
                experience = "Intermediate";
                cout<<"Level successfully upgraded to Intermediate!"<<endl;
            } else if (experience == "Intermediate") {
                experience = "Advanced";
                cout<<"Level successfully upgraded to Advanced!"<<endl;
            } else if (experience == "Advanced") {
                experience = "Expert";
                cout<<"Level successfully upgraded to Expert!"<<endl;
            } else {
                cout<<"Level can not be upgraded!"<<endl;
            }
        }
    }

    void playGame(Enemy &enemy);
    
    void decreaseHealth(int damage) {
        this->health -= damage;
        cout << "Updated health: " << health << endl;
    }
};

void Enemy::attack(Weapon &weapon) {
    cout<<"---------------ENEMY'S TURN---------------"<<endl;
    weapon.use();
    cout << "Enemy attacked player! Player's health is now: " << damage << endl;
}

void Character::playGame(Enemy &enemy) {
    cout<<"---------------USER'S TURN---------------"<<endl;
    Weapon weapon;
    weapon.use();
    cout << "Enemy attacked by player with the damage of 5!" << endl;
    enemy.healthDec(5);
    points += 10;
    levelUp();
}

int main() {
    cout<<"Name: Hafsa Rashid"<<endl<<"Student ID: 23K-0064"<<endl;
    Character c1(1, "Hafsa", 0, 0, "Beginner");
    Enemy e1(2, "Enemy ", 5);
    
    Weapon weapon;
    c1.playGame(e1);
    e1.attack(weapon);

    return 0;
}
