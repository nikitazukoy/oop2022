#pragma once
#include <iostream>
#include <string>

template<class T>
class DialogController {
    MatrixController<T> matrixController;
    Vector<T> vector;

public:
    void distributeProcess() {
        while (1) {//again:     //сменить на while(True) Continue;
            help();
            size_t i;
            std::cin >> i;
            if (!std::cin) {
                std::cin.clear();
                std::string buf;
                getline(std::cin, buf);        //считывает символы из входного потока и помещает их в строку
                std::cout << "Incorrect command" << std::endl << std::endl;
                break;
            }

            if (i == 1) {
                addMatrixElement();
            } else if (i == 2) {
                makeVector();
            } else if (i == 3) {
                printVector();
            } else if (i == 4) {
                printMatrix();
            } else if (i == 5) {
                return;
            } else {
                std::cin.clear();
                std::string buf;
                getline(std::cin, buf);
                std::cout << "Incorrect command" << std::endl << std::endl;
            }
           continue;
        }
    }
    void addMatrixElement() {
        size_t i;
        std::cin >> i;
        if (!std::cin) {
            std::cin.clear();
            std::string buf;
            getline(std::cin, buf);
            std::cout << "Unknown parameter pack" << std::endl << std::endl;
            return;
        }

        size_t j;
        std::cin >> j;
        if (!std::cin) {
            std::cin.clear();
            std::string buf;
            getline(std::cin, buf);
            std::cout << "Unknown parameter pack" << std::endl << std::endl;
            return;
        }

        T el;
        std::cin >> el;
        if (!std::cin) {
            std::cin.clear();
            std::string buf;
            std::getline(std::cin, buf);
            std::cout << "Unknown parameter pack" << std::endl << std::endl;
            return;
        }

        matrixController.addMatrixElement(i, j, el);
    }
    void makeVector() {
        vector = matrixController.makeVector();
    }
    void printVector() {
        for (int i = 0; i < vector.getLen(); ++i) {
            std::cout << vector[i] << " ";
        }
        std::cout << std::endl;
    }
    void printMatrix() {
        matrixController.printMatrix();
    }


    void help() {
        std::cout << "[1] add matrix element" << std::endl;
        std::cout << "    i j el" << std::endl;
        std::cout << "[2] make vector" << std::endl;
        std::cout << "[3] print vector" << std::endl;
        std::cout << "[4] print matrix" << std::endl;
        std::cout << "[5] exit" << std::endl;
    }
};