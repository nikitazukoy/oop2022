#pragma once
#include "List.h"

template<class T>
class Matrix {
public:
    class Dot {
    public:
        int i;
        int j;
        T data;
        Dot(int i, int j, const T & data) : i(i), j(j), data(data) {}
        Dot(int i, int j, T&& data) : i(i), j(j), data(std::move(data)) {}
    };

private:
    class Line {
    public:
        int i;
        List<Dot> line;

        explicit Line(int i) : i(i) {}

    };


    List<Line> matrix;


    class Iterator {
        List<Line>::Iterator iterator;
    public:
        explicit Iterator(const List<Line>::Iterator & it) : iterator(it) {}

        Iterator& operator++() {
            ++iterator;
            return *this;
        }
        List<Dot> & operator*() {
            return iterator->line;
        }
        List<Dot>* operator->() {
            return &iterator->line;
        }
        bool operator==(const Iterator & it) {
            return this->iterator == it.iterator;
        }

        bool operator!=(const Iterator & it) {
            return this->iterator != it.iterator;
        }
    };


public:
    Matrix() = default;


    Iterator begin() {
        return Iterator(matrix.begin());
    }
    Iterator end() {
        return Iterator(matrix.end());
    }


    size_t size() {
        return matrix.size();
    }


    void add(size_t i, size_t j, const T & data) {
        for (auto it = matrix.begin(); it != matrix.end(); ++it) {
            if (it->i == i) {
                it->line.orderedInsert(Dot(i, j, data), [](const Dot & dot1, const Dot & dot2) {
                    return dot1.j > dot2.j;
                });
                return;
            }
            if (it->i > i) {
                List<Dot> line;
                line.add(Dot(i, j, data));
                return;
            }
        }
        Line line(i);
        line.line.add(Dot(i, j, data));

        matrix.add(std::move(line));
    }


};