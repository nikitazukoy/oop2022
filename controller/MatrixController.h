#pragma once
#include "Matrix.h"
#include "Vector.h"

template<class T>
class MatrixController {
    Matrix<T> m;

public:
    Matrix<T> getMatrix() {
        return m;
    }

    void addMatrixElement(size_t i, size_t j, const T & el) {
        m.add(i, j, el);
    }


    void printMatrix() {
        for(auto & it : m) {
            for(auto & jt : it) {
                std::cout << jt.i << " " << jt.j << ": " << jt.data << "; ";
            }
            std::cout << std::endl;
        }
    }

private:
    T func(size_t index) {
        auto list = m.begin();
        int i = 0;
        for (; list != m.end(); ++list) {
            if (index == i) {
                break;
            }
            ++i;
        }
        if (list == m.end()) return T();

        if ((*list->begin()).data == T()) {
            for (auto & jt : m) {
                for (auto & kt : jt) {
                    if (kt.data != T()) {
                        return kt.data;
                    }
                }
            }
            return T();
        }

        T max = list->begin()->data;
        for(auto jt : *list) {
            if (jt.data > max) {
                max = jt.data;
            }
        }
        return max;
    }

public:
    Vector<T> makeVector() {
        Vector<T> v(m.size());
        size_t j = 0;
        for(auto & it : m) {
            T c = T();
            int i = 0;
            for(auto & jt : it) {
                c += jt.data;
                ++i;
            }
            c = c / i;


            v[j] = c / func(j);
            ++j;
        }
        return v;
    }
};