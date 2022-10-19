#include <iostream>

using namespace std;

struct Person {
    Person(string name) : name_(name) {}
    virtual ~Person() {}
    virtual string name() const { return name_; };

    string name_;
};

struct Teacher : Person {
    Teacher(string const& name) : Person(name) {
        cout << Teacher::name() << endl;
    }
};

struct Professor : Teacher {
    Professor(string const& name) : Teacher(name) {}
    virtual string name() const override { return "Prof. " + name_; }
};

int main() {
    Professor p("Stroustrup");
    cout << Teacher("Alex").name() << endl;
    cout << p.name() << endl;
    return 0;
}