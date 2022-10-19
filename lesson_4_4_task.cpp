#include <iostream>

using namespace std;

struct Expression {
    Expression(string const& name, int age) : name_(name), age_(age) {}
    virtual ~Expression() {}
    virtual string get_name() const { return name_; }
    virtual string occupation() const = 0;

  private:
    string name_;
    int age_;
};

struct Teacher : Expression {
    Teacher(string const& name, int age, string const& course)
        : Expression(name, age), course_(course) {
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
    virtual string thesis() const { return thesis_; }
    virtual string get_name() const override {
        return "Prof. " + Expression::get_name();
    }
    virtual string occupation() const override { return "teacher"; }

  private:
    string thesis_;
};

bool check_equals(Expression const* left, Expression const* right) {
    size_t* vptr1 = *(size_t**)left;
    size_t* vptr2 = *(size_t**)right;

    if (vptr1 == vptr2) {
        cout << "true" << endl;
        return true;
    }
    cout << "false" << endl;
    return false;
}

int main() {
    Expression* p1 = new Teacher("Alex", 32, "ppp");
    Expression* p2 = new Teacher("Alex", 33, "ppp");

    check_equals(p1, p2);

    delete p1;
    delete p2;
    return 0;
}