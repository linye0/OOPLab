#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <vector>
#include <unordered_map>

class Hero {
public:
    Hero() : charm(0), reputation(0), attack(0), defense(0), mana(0), treasures(0) {}

    std::unordered_map<std::string, int> get_ability_values() const {
        return {{"charm", charm}, {"reputation", reputation}, {"attack", attack}, {"defense", defense}, {"mana", mana}};
    }

    void carry_treasure(int treasure_num) {
        if (treasures.size() == 5) {
            std::cout << "宝物数量已满，不能再添加！" << std::endl;
        } else {
            treasures.push_back(treasure_num);
            update_ability_values(treasure_num, true);
        }
    }

    void discard_treasure(int pos) {
        if (pos >= treasures.size()) {
            std::cout << "该位置没有宝物，无法丢弃！" << std::endl;
        } else {
            int treasure_num = treasures[pos];
            treasures.erase(treasures.begin() + pos);
            update_ability_values(treasure_num, false);
        }
    }

    void display() const {
        std::cout << "英雄当前能力值：" << std::endl;
        std::unordered_map<std::string, int> ability_values = get_ability_values();
        for (auto it = ability_values.begin(); it != ability_values.end(); it++) {
            std::cout << it->first << ": " << it->second << std::endl;
        }
        std::cout << "携带的宝物编号：" << std::endl;
        for (auto treasure : treasures) {
            std::cout << treasure << " ";
        }
        std::cout << std::endl;
    }

private:
    int charm;
    int reputation;
    int attack;
    int defense;
    int mana;
    std::vector<int> treasures;

    void update_ability_values(int treasure_num, bool is_add) {
        if (treasure_num == 1) {
            charm += (is_add ? 2 : -2);
        } else if (treasure_num == 2) {
            reputation += (is_add ? 3 : -3);
        } else if (treasure_num == 3) {
            attack += (is_add ? 1 : -1);
        } else if (treasure_num == 4) {
            mana += (is_add ? 1 : -1);
        } else if (treasure_num == 5) {
            defense += (is_add ? 2 : -2);
        } else if (treasure_num == 6) {
            attack += (is_add ? 5 : -5);
        }
    }
};


#endif // HERO_H
