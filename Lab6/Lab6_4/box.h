#ifndef BOX_H
#define BOX_H

#include <iostream>

using namespace std;

/*
class Fruit;

class Box{
public:
    Box() : curNum(0), reducedNumInADay(0) {}
    void add(Fruit* fruit) {
        if (curNum < 7) {
            fruits[curNum] = fruit;
            curNum++;
        }
    }
    int reducedAll() {
        for (int i = 0; i < curNum; i++) {
            reducedNumInADay += fruits[i]->reduceWeight();
        }
        return reducedNumInADay;
    }
    int totalWeight() {
        int total = 0;
        for (int i = 0; i < curNum; i++) {
            total += fruits[curNum]->getWeight();
        }
        return total;
    }
    int totalApple() {
        int total = 0;
        for (int i = 0; i < curNum; i++) {
            if (dynamic_cast<Apple*>(fruits[i]) != nullptr) {
                total += 1;
            }
        }
        return total;
    }
    int totalOrange() {
        int total = 0;
        for (int i = 0; i < curNum; i++) {
            if (dynamic_cast<Orange*>(fruits[i]) != nullptr) {
                total += 1;
            }
        }
        return total;
    }
private:
    int reducedNumInADay;
    int curNum;
    Fruit* fruits[8];
};

class Fruit{
public:
    Fruit(int weight, int reducedWeight) : originWeight(weight), weight(weight), reducedWeight(reducedWeight) {}
    virtual int reduceWeight() = 0;
    int getWeight() {
        return weight;
    }
protected:
    int originWeight;
    int weight;
    int reducedWeight;
};

class Apple : public Fruit {
    Apple(int weight, int reducedWeight) : Fruit(weight, reducedWeight) {}
    virtual int reducedWeight() {
            int res = 0;
            if (weight > (3 * originWeight) / 5) {
                weight -= 4;
                res += 4;
            }
            return res;
        }
};

class Orange : public Fruit{
    Orange(int weight, int reducedWeight) : Fruit(weight, reducedWeight) {}
    virtual int reducedWeight() {
        int res = 0;
        if (weight > (3 * originWeight) / 5) {
                weight -= 3;
                res += 3;
        }
        return res;
        }
};
*/

// 水果类
class Fruit {
protected:
    int originalWeight;  // 原始重量
    int currentWeight;   // 当前重量

public:
    Fruit(int weight) : originalWeight(weight), currentWeight(weight) {}

    int getOriginalWeight() {
        return originalWeight;
    }
    // 获取当前重量
    int getCurrentWeight() const {
        return currentWeight;
    }

    // 减轻重量
    virtual void reduceWeight() = 0;
};

// 苹果类
class Apple : public Fruit {
public:
    Apple(int weight) : Fruit(weight) {}

    // 减轻重量
    void reduceWeight() override {
        if (currentWeight > 3 * originalWeight / 5) {
            originalWeight = currentWeight;
            currentWeight -= 4;
        }
    }
};

// 桔子类
class Orange : public Fruit {
public:
    Orange(int weight) : Fruit(weight) {}

    // 减轻重量
    void reduceWeight() override {
        if (currentWeight > 3 * originalWeight / 5) {
            originalWeight = currentWeight;
            currentWeight -= 3;
        }
    }
};

// 盒子类
class Box {
private:
    Fruit* fruits[8];  // 水果指针数组
    int fruitCount;    // 水果数量

public:
    Box() : fruitCount(0) {}

    // 放入水果
    void addFruit(Fruit* fruit) {
        if (fruitCount < 8) {
            fruits[fruitCount] = fruit;
            fruitCount++;
        }
    }

    // 输出苹果数量
    int getAppleCount() const {
        int count = 0;
        for (int i = 0; i < fruitCount; i++) {
            if (dynamic_cast<Apple*>(fruits[i]) != nullptr) {
                count++;
            }
        }
        return count;
    }

    // 输出桔子数量
    int getOrangeCount() const {
        int count = 0;
        for (int i = 0; i < fruitCount; i++) {
            if (dynamic_cast<Orange*>(fruits[i]) != nullptr) {
                count++;
            }
        }
        return count;
    }

    // 输出一天来水果减轻的总重量
    int getTotalWeightReduced() const {
        int totalWeight = 0;
        for (int i = 0; i < fruitCount; i++) {
            fruits[i]->reduceWeight();
            totalWeight += fruits[i]->getCurrentWeight() - fruits[i]->getOriginalWeight();
        }
        return totalWeight;
    }

    // 输出当前水果的总重量
    int getCurrentTotalWeight() const {
        int totalWeight = 0;
        for (int i = 0; i < fruitCount; i++) {
            totalWeight += fruits[i]->getCurrentWeight();
        }
        return totalWeight;
    }
};
#endif // BOX_H
