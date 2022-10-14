#include <iostream>

using namespace std;

// Перегрузка при наследовании
// ->

// Когда мы определяем в производном классе методы с таким же названием, как в
// базовом классе, то методы из производного класса перекрывают методы из
// базового класса

struct File {
    void write(char const* str);
};

struct FormattedFile : public File {
    void write(int i);
    void write(double d);
    using File::write; // что бы использовать методы write из базового класса
};
// ->

struct Vector2D {
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}
    Vector2D mult(double d) const { return Vector2D(x * d, y * d); }
    double mult(Vector2D const& p) const { return x * p.x + y * p.y; }

    double x, y;
};

void foo1() {
    Vector2D p(1, 2);
    Vector2D q = p.mult(10);
    double r = p.mult(q);
    Vector2D vector(1, 2);
    Vector2D vector2 = vector.mult(10);
    cout << vector2.x << "\n" << vector2.y << endl;

    double result = vector2.mult(vector2);

    cout << result << endl;
}

void foo2() {
    FormattedFile f;
    f.write(4);
    f.write("Hello");
}

int main() {
    foo2();
    return 0;
}
