#include <iostream>

using namespace std;

// Наследование - позволяет создавать классы на основе уже существующих
// (дочерние на основе родительских)
// Класс наследник будет обладать теми же полями, что и класс родитель

// ПРЕДСТАВЛЕНИЕ В ПАМЯТИ:
// Внутри объекта класса-наследника хранится экземпляр родительского класса
// (набор полей, который соответсвует родительскому классу)

// При создании объекта производного класса сначала вызывается конструктор
// родительского класса (иногда этот конструктор нужно вызывать самостоятельно)

// При удалении дочернего объекта, сначала вызывается деструктор дочернего,
// затем родительского

// При копировании из наследника в родителя (вызывается конструктор копирования
// родителся, который в качестве параметра принимает ссылку на объект типа
// родителя) происходит "срезка", то есть копируются только поля, которые есть в
// родителе

// Модификатор protected - наследники имеют доступ, внешний код нет !!!

class Person {
  public:
    explicit Person(string name, int age) : name(name), age(age) {}

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

class Parent {
  public:
    Parent(int x, int y) : x(x), y(y) {}

    int& get_x() { return x; }
    int& get_y() { return y; }

  private:
    int x;
    int y;
};

class Child : public Parent {
  public:
    Child(int x, int y, int z) : Parent(x, y), z(z) {}

    int& get_z() { return z; }

  private:
    int z;
};

void foo1() {
    Student s("Alex", 21, "MIT");

    Person dad = s;
    // В обратную сторону такие приведения не работают !!!
    Person& l = s;    // Student & -> Person &
    Person* ptr = &s; // Student * -> Person *

    Person first("F", 1);
    first = (Person&)s;
    cout << first.get_age() << endl;
}

void foo2() {
    Child obj(12, 4, 3);
    Parent &ptr = obj;
    cout << ptr.get_x() << endl;
}

int main() {
    foo2();
    return 0;
}
