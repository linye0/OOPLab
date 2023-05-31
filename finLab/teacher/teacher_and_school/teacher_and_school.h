#ifndef TEACHER_AND_SCHOOL_H
#define TEACHER_AND_SCHOOL_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class School {
public:
    School(int impact) : impact(impact) {}
    Teacher* addTeacher(Teacher* teacher) {
        teachers.push_back(teacher);
        return teacher;
    }
    int getNumTeachers() const {
        return teachers.size();
    }
    float getImpact() const {
        return impact;
    }
    float changeImpact(float change) {
        impact += change;
        return impact;
    }
protected:
    vector<Teacher*> teachers;
    float impact;
};

class Teacher{
protected:
    int workload;
    string name;
    School* school;
public:
    Teacher(string name, School* school) : name(name), school(school) {}
    Teahcer(string name, School& school) : name(name), school(&school) {}
    int getWorkload() const {
        return workload;
    }
    string getName() const {
        return name;
    }
    School* getSchool() const {
        return school;
    }
    virtual void publishPaper(Paper* paper) = 0;
};

enum class PaperClass{
    EI,
    SCI
};

class Paper{
protected:
    string title;
    PaperClass paperType;

public:
    Paper(string title, PaperClass paperType) : title(title), paperType(paperType) {}
    virtual int calImpact() = 0;
    PaperClass getType() const {
        return paperType;
    }
};

class EI_Paper : public Paper{
public:
    EI_Paper(string title) : Paper(title, paperClass::EI) {}
    virtual int calImpact() {
        return 1;
    }
};

class SCI_Paper : public Paper{
private:
    float IF;
public:
    EI_Paper(string title, float IF) : Paper(title, paperClass::EI), IF(IF) {}
    virtual float calImpact() {
        return 2.0 + IF * 2.0;
    }
};

#endif // TEACHER_AND_SCHOOL_H
