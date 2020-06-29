//
// Created by 王子龙 on 2019/12/2.
//

#ifndef VIII_2_CCOLLEGESTUDENT_H
#define VIII_2_CCOLLEGESTUDENT_H

#include "MyString.h"
#include <iostream>

using namespace std;

class CCollegeStudent {
private:
    MyString name;
    MyString major;
    double score;
    double number;
public:
    CCollegeStudent() {};
    CCollegeStudent(const int number, const MyString &name,
                    const MyString &major, const double score)
            : number(number), name(name), major(major), score(score) {};
    int get_number() const { return number; }

    int set_number(const int number) {
        this->number = number;
        return number;
    }

    MyString get_name() const { return name; }

    MyString &get_name() { return name; }

    MyString &set_name(const char *s) {
        name.set_string(s);
        return name;
    }

    MyString &set_name(const MyString &name) {
        this->name = name;
        return this->name;
    }

    MyString get_major() const { return major; }

    MyString &get_major() { return major; }

    MyString &set_major(const char *s) {
        major.set_string(s);
        return major;
    }

    MyString &set_major(const MyString &major) {
        this->major = major;
        return this->major;
    }

    double get_score() const { return score; }

    double set_score(const double score) {
        this->score = score;
        return score;
    }

    double modifyScore(const double score) {
        this->score = score;
        return score;
    }

    friend ostream &operator<<(ostream &o, const CCollegeStudent &s);

    CCollegeStudent &read_text(istream &in) {
        in >> number;
        in.get();
        name.read_text(in);
        major.read_text(in);
        in >> score;
        in.get();
        return *this;
    }
    CCollegeStudent &write_text(ostream &o) {
        o << number;
        name.write_text(o);
        major.write_text(o);
        o << score;
        return *this;
    }
    CCollegeStudent &read_binary(istream &in) {
        in.read((char*) &number, sizeof(int));
        name = name.read_binary(in);
        major = major.read_binary(in);
        in.read((char*) &score, sizeof(double));
        return *this;
    }
    CCollegeStudent &write_binary(ostream &o) {
        o.write((char*) &number, sizeof(int));
        name.write_binary(o);
        major.write_binary(o);
        o.write((char*) &score, sizeof(double));
        return *this;
    }

    virtual void display() = 0;
};

class Undergraduate : CCollegeStudent {

};

class Postgraduate : CCollegeStudent {

};

#endif //VIII_2_CCOLLEGESTUDENT_H
