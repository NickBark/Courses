#include <algorithm>
#include <iostream>

struct IntArray {
    // explicit - запрещает неявное преобразование от числа к массиву
    explicit IntArray(size_t size) : size_(size), data_(new int[size_]) {}

    IntArray(IntArray& a) : size_(a.size_), data_(new int[size_]) {
        for (size_t i = 0; i < size_; i++) {
            data_[i] = a.data_[i];
        }
    }

    ~IntArray() { delete[] data_; }

    IntArray& operator=(IntArray& a) {
        if (this != &a) {
            IntArray(a).swap(*this);
        }
        return *this;
    }

    void swap(IntArray& other) {
        std::swap(this->size_, other.size_);
        std::swap(this->data_, other.data_);
    }

    size_t get_size() const { return size_; }
    int get(size_t i) const { return data_[i]; }
    int& get(size_t i) { return data_[i]; }

    void resize(size_t nsize) {
        IntArray tmp(nsize);
        size_t n = nsize > size_ ? size_ : nsize;
        for (size_t i = 0; i < n; i++)
            tmp.data_[i] = data_[i];
        swap(tmp);
    }

  private:
    size_t size_;
    int* data_;
};

int main() {
    IntArray a1(20);
    std::cout << a1.get(5) << std::endl;
    a1.get(5) = 12;
    std::cout << a1.get(5) << std::endl;

    return 0;
}