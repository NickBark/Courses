#include <iostream>
#include <string>

using namespace std;

struct Person {
    Person(string const& name, int age) : name_(name), age_(age) {}
    virtual ~Person() {}
    virtual string get_name() const { return name_; }
    virtual string occupation() const = 0;

  private:
    string name_;
    int age_;
};

struct Teacher : Person {
    Teacher(string const& name, int age, string const& course)
        : Person(name, age), course_(course) {
        cout << get_name() << endl;
    }

    virtual string occupation() const override { return "teacher"; }
    virtual string course() const { return course_; }

  private:
    string course_;
};

struct Professor : Teacher {
    Professor(string const& name, int age, string const& course,
              string const& thesis)
        : Teacher(name, age, course), thesis_(thesis) {}
    virtual string thesis() const {return thesis_;}
    virtual string get_name() const override {return "Prof. " + Person::get_name();}
    virtual string occupation() const override { return "teacher"; }

  private:
    string thesis_;
};

int main() {
    Professor p("Stroustrup", 63, "C++", "The C++ language");
    return 0;
}