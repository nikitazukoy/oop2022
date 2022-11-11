#pragma once

template<class T>
class Vector {
    T* arr = nullptr;
    int len = 0;

public:
    Vector() = default;                            //Конструктор по умолчанию

    explicit Vector(int len) : len(len) {         //Ключевое слово превращает конструктор преобразования
        arr = new T[len];                         // в конструктор без преобразования.
    }                                             //В результате код менее подвержен ошибкам.

    int getLen() { return len; };

    T & operator[](int index) {
        return arr[index];
    }

    ~Vector() {                                    //деструктор
        delete[] arr;
    }

    Vector & operator=(Vector && other) noexcept {  // Применяется к функциям, которые гарантированно
        arr = other.arr;                            //не могут генерировать исключения.
        len = other.len;
        other.arr = nullptr;
        other.len = 0;

        return *this;
    };
    Vector(Vector && other) noexcept {
        arr = other.arr;
        len = other.len;
        other.arr = nullptr;
        other.len = 0;
    };
};

