#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Fungsi untuk menambahkan elemen ke linked list
    void insertNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Fungsi untuk mencetak linked list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

    // Fungsi untuk menghapus elemen dari linked list
    void deleteNode(int data) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == data) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Elemen " << data << " tidak ditemukan dalam linked list.\n" << std::endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
    }
};

int main() {
    LinkedList linkedList;

    linkedList.insertNode(10);
    linkedList.insertNode(20);
    linkedList.insertNode(30);
    linkedList.insertNode(40);

    std::cout << "Linked List awal: ";
    linkedList.printList();

    linkedList.deleteNode(20);
    std::cout << "Linked List setelah menghapus 20: \n";
    linkedList.printList();

    linkedList.deleteNode(50);
    return 0;
}