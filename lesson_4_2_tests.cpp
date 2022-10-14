#include <cstring>
#include <iostream>

using namespace std;

struct Base {
    char* at(char* ch) { return ch; }
    char* str;
};

struct String : public Base{
    String(size_t size) : size(size), str(new char[size]) {}
    explicit String(char const* str)
        : size(strlen(str)), str(new char[size + 1]) {
        for (size_t i = 0; i != size; i++) {
            this->str[i] = str[i];
        }
        this->str[size] = '\0';
    }
    ~String() { delete[] str; }
    /* ... */
    char& at(size_t idx) { return str[idx]; }
    char at(size_t idx) const { return str[idx]; }
    using Base::at;
    /* ... */
    size_t size;
    char* str;
};

int main() {
    String greet("Hello");
    char ch1 = greet.at(1);
    cout << "Hello, World !!!" <<endl;
    String const const_greet("Hello, const !");
    char const& ch2 = const_greet.at(0);

    for (size_t i = 0; i < const_greet.size; i++) {
        cout << const_greet.at(i);
    }
    cout << endl;
    return 0;
}
