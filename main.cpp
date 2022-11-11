#include <iostream>
#include "Dialog.h"
#include "Matrix.h"
#include "Vector.h"
#include "MatrixController.h"
#include "DialogController.h"

//Matrix<int> m;
//m.add(1, 2, 1);
//m.add(1, 1, -12);
//m.add(3, 2, 3);
//m.add(3, 1, 0);
//m.add(4, 2, 4);
//m.add(4, 1, 3);
//m.add(4, 7, 12);
//m.add(5, 2, 5);
template<class T>
T func(size_t index, Matrix<T> & m) {
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

template<class T>
Vector<T> makeVector(Matrix<T> & m) {
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


        v[j] = c / func<T>(j, m);
        ++j;
    }
    return v;
}



int main() {
//   Matrix<int> m;
//   m.add(1, 2, 1);
//   m.add(1, 1, -12);
//  m.add(3, 2, 3);
//   m.add(3, 1, 0);
//  m.add(4, 2, 4);
//   m.add(4, 1, 3);
//   m.add(4, 7, 12);
//   m.add(5, 2, 5);

//  for(auto & it : m) {
//       for(auto & jt : it) {
//            std::cout << jt.i << " " << jt.j << ": " << jt.data << "; ";
//       }
//        std::cout << std::endl;
//    }

//
//    Vector<int> v = makeVector(m);
//
//    for (int i = 0; i < v.getLen(); ++i) {
//        std::cout << v[i] << " ";
//    }
//    std::cout << std::endl;
    DialogController<double> dialogController;
    dialogController.distributeProcess();

    return 0;
}
