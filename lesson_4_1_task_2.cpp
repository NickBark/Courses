#include <iostream>

struct Foo {
  public:
    void say() const { std::cout << "Foo says: " << msg << "\n"; }

  protected:
    Foo(const char* msg) : msg(msg) {}

  private:
    const char* msg;
};

void foo_says(const Foo& foo) { foo.say(); }

// Вам нужно определить функцию get_foo, как описано в задании,
// чтобы компилировался и работал как ожидается следующий код:
//
// foo_says(get_foo("Hello!"));

struct Ppp : Foo {
    Ppp(const char* msg) : Foo(msg) {}
};

Ppp get_foo(const char* msg) { return Ppp(msg); }

int main() {
    foo_says(get_foo("Hello!"));
    return 0;
}
