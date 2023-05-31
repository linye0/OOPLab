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

// ˮ����
class Fruit {
protected:
    int originalWeight;  // ԭʼ����
    int currentWeight;   // ��ǰ����

public:
    Fruit(int weight) : originalWeight(weight), currentWeight(weight) {}

    int getOriginalWeight() {
        return originalWeight;
    }
    // ��ȡ��ǰ����
    int getCurrentWeight() const {
        return currentWeight;
    }

    // ��������
    virtual void reduceWeight() = 0;
};

// ƻ����
class Apple : public Fruit {
public:
    Apple(int weight) : Fruit(weight) {}

    // ��������
    void reduceWeight() override {
        if (currentWeight > 3 * originalWeight / 5) {
            originalWeight = currentWeight;
            currentWeight -= 4;
        }
    }
};

// ������
class Orange : public Fruit {
public:
    Orange(int weight) : Fruit(weight) {}

    // ��������
    void reduceWeight() override {
        if (currentWeight > 3 * originalWeight / 5) {
            originalWeight = currentWeight;
            currentWeight -= 3;
        }
    }
};

// ������
class Box {
private:
    Fruit* fruits[8];  // ˮ��ָ������
    int fruitCount;    // ˮ������

public:
    Box() : fruitCount(0) {}

    // ����ˮ��
    void addFruit(Fruit* fruit) {
        if (fruitCount < 8) {
            fruits[fruitCount] = fruit;
            fruitCount++;
        }
    }

    // ���ƻ������
    int getAppleCount() const {
        int count = 0;
        for (int i = 0; i < fruitCount; i++) {
            if (dynamic_cast<Apple*>(fruits[i]) != nullptr) {
                count++;
            }
        }
        return count;
    }

    // �����������
    int getOrangeCount() const {
        int count = 0;
        for (int i = 0; i < fruitCount; i++) {
            if (dynamic_cast<Orange*>(fruits[i]) != nullptr) {
                count++;
            }
        }
        return count;
    }

    // ���һ����ˮ�������������
    int getTotalWeightReduced() const {
        int totalWeight = 0;
        for (int i = 0; i < fruitCount; i++) {
            fruits[i]->reduceWeight();
            totalWeight += fruits[i]->getCurrentWeight() - fruits[i]->getOriginalWeight();
        }
        return totalWeight;
    }

    // �����ǰˮ����������
    int getCurrentTotalWeight() const {
        int totalWeight = 0;
        for (int i = 0; i < fruitCount; i++) {
            totalWeight += fruits[i]->getCurrentWeight();
        }
        return totalWeight;
    }
};
#endif // BOX_H
