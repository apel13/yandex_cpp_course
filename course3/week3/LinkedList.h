//
// Created by apel on 19.01.2021.
//

#ifndef YANDEX_CPP_COURSE_LINKEDLIST_H
#define YANDEX_CPP_COURSE_LINKEDLIST_H

template <typename T>
class LinkedList {
public:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    ~LinkedList() {
        while (head != nullptr) {
            Node* prev = head;
            head = head->next;
            delete prev;
        }
    }

    void PushFront(const T& value) {
        head = new Node{value, head};
    }

    void InsertAfter(Node* node, const T& value) {
        if (!node)
            return PushFront(value);
        node->next = new Node{value, node->next};
    }
    void RemoveAfter(Node* node) {
        if (!node) return PopFront();
        if (!node->next) return;
        Node* next = node->next->next;
        delete node->next;
        node->next = next;
    }

    void PopFront() {
        if (!head) return;
        Node* new_head = head->next;
        delete head;
        head = new_head;
    }

    Node* GetHead() { return head; }
    const Node* GetHead() const { return head; }

private:
    Node* head = nullptr;
};

#endif //YANDEX_CPP_COURSE_LINKEDLIST_H
