#include <iostream>

using namespace std;

// Для реализации динамического полиморфизма в C++ применяются таблицы
// виртуальных методов

// Такие таблицы создаются для каждого полиморфного класса (для классов у
// которых есть виртуальные методы)
// !!! Именно для классов, а не для объектов

// В каждом объекте указатель на таблицу виртуальных методов

// !!! Виртуальные методы, вызванные в конструкторе или деструкторе
// соответствующего объекта ведут себя, как НЕвиртуальные

// указатель на таблицу виртуальных методов инициализируется в конструкторе

// g++ -fdump-lang-class lesson_4_4_3.cpp

class Person {
  public:
    Person(string name) : name_(name) {}
    virtual ~Person() {}
    string name() const { return name_; }
    virtual string occupation() const = 0;
    virtual string name() const { return this->name_; }

  private:
    string name_;
};

class Student : public Person {
  public:
    Student(string name, int group = 1) : Person(name_), group_(group) {}
    virtual string occupation() const override { return "student"; }
    virtual int group() const { return group_; }

  private:
    string name_;
    int group_;
};

class Teacher : public Person {
  public:
    Teacher(string const& name) : Person(name_) { cout << Person::name() << endl; }
    virtual string occupation() const override { return "teacher"; }
    virtual void course() {}

  private:
    string name_;
};

class Professor : public Teacher {
  public:
    Professor(string name_) : Teacher(name_) {}
    virtual string occupation() const override { return "professor"; }
    virtual string name() const override { return "Prof." + name_; }
    virtual void thesis() {}

  private:
    string name_;
};

void foo(Person* ppp) { cout << ppp->occupation() << endl; }

int main() {
    Person* st = new Student("Alex", 12);

    foo(st);

    delete st;

    return 0;
}
