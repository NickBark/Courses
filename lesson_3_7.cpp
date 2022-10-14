#include <algorithm>
#include <iostream>

// Конструктор копирования принимает в качестве аргумента ссылку на экземпляр
// своего класса

// Если не определять конструктор копирования и оператор присваивания, то они
// сгенерируются компилятором

class Ppp {
  public:
    explicit Ppp(size_t size) : size(size), data(new int[size]) {}

    // оператор присваивания
    Ppp& operator=(Ppp const& a) {
        if (this != &a)
            Ppp(a).swap(*this);
        return *this;
    }

    // оператор присваивания
    // Ppp& operator=(Ppp const& a) {
    //     if (this != &a) {
    //         delete[] data;
    //         size = a.size;
    //         data = new int[size];
    //         for (size_t i = 0; i < size; i++) {
    //             data[i] = a.data[i];
    //         }
    //     }
    //     return *this;
    // }

    // конструктор копирования
    Ppp(Ppp const& a) : size(a.size), data(new int[size]) {
        for (size_t i = 0; i < size; i++) {
            data[i] = a.data[i];
        }
    }

    ~Ppp() { delete[] data; }

    void swap(Ppp& a);
    void swap_alg(Ppp& a);

    void change_size(size_t size_) {
        delete[] this->data;
        size = size_;
        data = new int[size];
    }

    size_t get_size() const { return size; }

  private:
    size_t size;
    int* data;
};

void Ppp::swap(Ppp& a) {
    size_t const tmp_size = a.size;
    a.size = this->size;
    this->size = tmp_size;

    int* const tmp_data = a.data;
    a.data = this->data;
    this->data = tmp_data;
}

void Ppp::swap_alg(Ppp& a) {
    std::swap(this->size, a.size);
    std::swap(this->data, a.data);
}

struct IntArray {
    explicit IntArray(size_t size) : size_(size), data_(new int[size_]) {}
    ~IntArray() { delete[] data_; }

    // Оператор присваивания
    IntArray& operator=(IntArray const& a) {
        if (this != &a) {
            delete[] data_;
            size_ = a.size_;
            data_ = new int[size_];
            for (size_t i = 0; i < size_; i++) {
                data_[i] = a.data_[i];
            }
        }
        // возвращаемое значение - указатель на экземпляр класса (которому
        // присваивается)
        return *this;
    }

    // Конструктор копирования
    IntArray(IntArray const& a) : size_(a.size_), data_(new int[a.size_]) {
        for (size_t i = 0; i < size_; i++) {
            data_[i] = a.data_[i];
        }
    }

    size_t get_size() const { return size_; }

  private:
    size_t size_;
    int* data_;
};

int main() {
    Ppp a1(10);
    Ppp a2(19);
    Ppp a3 = a1;
    a2 = a1;
    std::cout << a2.get_size() << std::endl;

    return 0;
}
