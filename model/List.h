#pragma once
#include <functional>

template<class T>
class List {
    class Node {
        Node* prev = nullptr;
        Node* next = nullptr;
        T data;
    public:
        explicit Node(T&& el) : data(std::move(el)) {};                                           //безопасное перемещние объектов
        explicit Node(const T & el) : data(el) {};

        friend class List<T>;
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    size_t len = 0;

public:

    List() = default;

    class Iterator {
        Node* it;
    public:
        explicit Iterator(Node* it) : it(it) {}                                         //предотвращает неявное преобразование типов при инициализации

        Iterator& operator++() {
            it = it->next;
            return *this;
        }
        T & operator*() {
            return it->data;
        }
        T* operator->() {
            return &it->data;
        }
        bool operator==(const Iterator & it) {
            return this->it == it.it;
        }

        bool operator!=(const Iterator & it) {
            return this->it != it.it;
        }
    };

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    ~List() {
        Node* jt = nullptr;
        for (auto it = head; it != nullptr; it = it->next) {
            delete jt;
            jt = it;
        }
        delete jt;
    }

    void orderedInsert(const T & value, std::function<bool(const T &, const T &)> comp = std::greater<T>()) {
        if (head == nullptr) {                      // объект, который используется для выполнения сравнений
            add(value);
            return;
        }
        if (comp(head->data, value)) {
            Node* tmp = head;
            head = new Node(value);
            head->next = tmp;
            tmp->prev = head;
            ++len;
            return;
        }
        for (auto it = head; it->next != nullptr; it = it->next) {
            if (comp(it->next->data, value)) {
                Node* el = new Node(value);
                Node* tmp = it->next;
                it->next = el;
                el->prev = it;
                el->next = tmp;
                tmp->prev = el;
                ++len;
                return;
            }
        }
        add(value);
    }

    void add(const T & el) {
        if (head == nullptr) {
            head = tail = new Node(el);
            ++len;
            return;
        }
        tail->next = new Node(el);
        tail->next->prev = tail;
        tail = tail->next;
        ++len;
    }

    void add(T && el) {
        if (head == nullptr) {
            head = tail = new Node(std::move(el));
            ++len;
            return;
        }
        tail->next = new Node(std::move(el));
        tail->next->prev = tail;
        tail = tail->next;
        ++len;
    }

    void empty() {
        return head == nullptr;
    }

    size_t size() const {
        return len;
    }

    List(List&&other) noexcept {
        head = other.head;
        tail = other.tail;
        len = other.len;

        other.head = nullptr;
        other.tail = nullptr;
        other.len = 0;
    }

};
