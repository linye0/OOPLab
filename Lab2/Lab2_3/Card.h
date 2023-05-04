#ifndef CARD_H
#define CARD_H

#include <String>
#include <iostream>

using namespace std;

class Card
{
public:
    Card(int suitMark_ = 0, int rankMark_ = 0, int backImg_ = 0, int width_ = 0, int height_ = 0, int pos_[] = NULL):
        suitMark(suitMark_), rankMark(rankMark_), ID(suitMark_ * 13 + rankMark_), backImg(backImg_), width(width_), height(height_), pos(pos_){}
    Card(const Card& obj):
        suitMark(obj.suitMark), rankMark(obj.rankMark), ID(obj.ID), backImg(obj.backImg), width(obj.width), height(obj.height), pos(obj.pos){}
    void info() {
        cout << "suit: " << suit[suitMark] << endl;
        cout << "rank: " << rank[rankMark] << endl;
        cout << "ID: " << ID << endl;
        cout << "backImg: " << backImg << endl;
        cout << "width: " << width << endl;
        cout << "height: " << height << endl;
        cout << "pos: " << pos.x << " " << pos.y << endl;
    }
    void setPos(int x, int y) {
        (this->pos).x = x;
        (this->pos).y = y;
    }
    void setPos(int pos[]) {
        (this->pos).x = pos[0];
        (this->pos).y = pos[1];
    }
    void oppoPos() {
        cout << "x: " << pos.x + width << endl;
        cout << "y: " << pos.y + height << endl;
    }
    void setBackImg(int img) {
        backImg = img;
    }
    void readBackImg() {
        cout << "backImg: " << backImg << endl;
    }
    bool checkSameSuit(Card& anotherCard) {
        return suitMark == anotherCard.suitMark;
    }
    bool checkSameRank(Card& anotherCard) {
        return rankMark == anotherCard.rankMark;
    }
    bool checkSameID(Card& anotherCard) {
        return ID == anotherCard.ID;
    }
    bool checkID(int ID_) {
        return ID == ID_;
    }
    bool checkSuit(int suit_) {
        return suitMark == suit_;
    }
    bool checkRank(int rank_) {
        return rankMark == rank_;
    }
private:
   static string suit[];
   static string rank[];
   int suitMark;
   int rankMark;
   int ID;
   int backImg;
   int width;
   int height;
   class Pos
   {
   public:
       float x;
       float y;
       Pos(const Pos& obj) {
           x = obj.x;
           y = obj.y;
       }
       Pos(int pos[]) {
           if (pos == NULL) {
               x = 0;
               y = 0;

           }else{
               this->x = pos[0];
               this->y = pos[1];
           }
       }
       Pos(float x, float y) {
           this->x = x;
           this->y = y;
       }
   }pos;
};

#endif // CARD_H
