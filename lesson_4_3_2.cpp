#include <iostream>

using namespace std;

// Виртуальный деструктор
// Если не объявить деструктор виртуальным, то при обращении к дочернему объекту
// через указатель на базовый класс вызовется деструктор базового класса

class Person {
  public:
    explicit Person(string name, int age) : name(name), age(age) {}
    virtual ~Person() {}

    string get_name() const { return name; }
    int& get_age() { return age; }

  protected:
    string name;
    int age;
};

class Student : public Person {
  public:
    Student(string name, int age, string uni) : Person(name, age), uni(uni) {}

    string get_university() const { return uni; }

  private:
    string uni;
};

int main() {
    Person* p = new Student("Alex", 21, "MIT");

    delete p;

    return 0;
}
