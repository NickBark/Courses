#include <iostream>

using namespace std;

// Перегрузка - определение метода с тем же именем, но с другой сигнатурой
// Переопределение - определение метода с тем же именем и сигнатурой, как и в
// базовом классе

// Виртуальные методы - если не указать virtual, то конкретный адрес метода,
// который будет вызван через указатель на базовый класс будет подставлен на
// этапе компиляции
// - ИНАЧЕ - адрес будет зависить от того значения, которое сейчас хранится в
// указателе ptr => адрес будет выбираться на этапе выполнения

// Чистыве виртаульные методы (абстрактные) - виртуальные методы, у которых
// отсутствует реализация

// Если у класса объявлен абстрактный метод, то такой класс становится
// абстрактным !!! => нельзя создать экземпляр такого класса, но можно
// наследоваться от такого класса !!!

// Виртуальный деструктор -> lesson_4_3_2.cpp

class Person {
  public:
    Person(string name) : name_(name) {}
    virtual string name() const { return name_; }
    virtual string occupation() const = 0;
    
  private:
    string name_;
};

class Student : public Person {
  public:
    Student(string name) : Person(name) {}
    virtual string occupation() const override { return "student"; }
    string name() const override { return "!!! " + Person::name(); }
};

class Professor : public Person {
  public:
    Professor(string name) : Person(name) {}
    string name() const override { return "Professor " + Person::name(); }
    virtual string occupation() const override { return "professor"; }
};

int main() {
    Student ppp("Koly");
    Person* p = &ppp;
    cout << p->name() << p->occupation() << endl;
    return 0;
}
