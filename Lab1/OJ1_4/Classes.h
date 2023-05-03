#ifndef CLASSES_H
#define CLASSES_H
using namespace std;
#include <vector>
#include <string>

class Pen{
public:
    void write(){
        cout << "Write!" << endl;
    }
};

class FountainPen : public Pen{
public:
    void write() {
        if (ink <= 0) {
            cout << "Ink Shortage!" << endl;
            return;
        }
        cout << "Write!" << endl;
        ink--;
    }
    void setInk(int setInk) {
        ink = setInk;
    }
    void showInk() {
        cout << "Ink:" << ink << endl;
    }
private:
    int ink = 100;
};

class File{
public:
    File(string sname) {
        name = sname;
    }
    File(char* sname) {
        name = string(sname);
    }
    void showName() {
        cout << name << endl;
    }
private:
    string name;
};

class Directory{
public:
    void addFile(File file) {
        files.push_back(file);
    }
    void showFile() {
        for (int i = 0; i < files.size(); i++) {
            files[i].showName();
        }
        cout << endl;
    }
private:
    vector<File> files;
};

class Planet{
public:
    Planet(int h = 0) {
        height = h;
    }
    Planet(Planet& other){
        height = other.height;
    }
    void rise(int h = 0) {
        height += h;
    }
    void fall(int h = 0) {
        height -= h;
    }
    void show() {
        cout << height << endl;
    }
private:
    int height = 0;
};

class Sky{
public:
    Sky(Planet isun, Planet imoon): sun(isun), moon(imoon) {
    }
    void sunRise(int h = 0) {
        sun.rise(h);
        moon.fall(h);
    }
    void moonRise(int h = 0) {
        moon.rise(h);
        sun.fall(h);
    }
    void show(){
        sun.show();
        moon.show();
    }
private:
    Planet sun;
    Planet moon;
};

#endif // CLASSES_H
