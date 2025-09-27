#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class stack {
    public:
    Node *top;
    stack() {
        top = nullptr;
        
    }

    void push(int val) {
        Node* newNode = new Node(val);
        if (!top) {
            top = newNode;
        } else { 
            newNode->next = top;
            top = newNode;
        }

    }

    void pop() {
        if(!top) return;
        Node* temp = top;
        top->next = top;
        delete temp;
    }
};

class deque {
    public:
    Node* front;
    Node* back;
    deque() {
        front = nullptr;
        back = nullptr;
    }
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (!front) {
            front = back = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }
    void push_back(int val) {
        Node* newNode = new Node(val);
        if(!back) {
            back = newNode;
        }
        else {
            newNode->prev = back;
            back->prev = newNode;
            back = newNode;
        }
    }

    void pop_back(int val) {
        Node* temp = back;
        if(!back){
            return;
        }
        back = back->prev;
        if(back){
            back->next = nullptr;
        }
        else{
            front = nullptr;
        }
        delete temp;
    }
    void pop_front(int val) {
        Node* newNode = new Node(val);
        Node* temp = front;
        if(front) {
            front->next = front;
            temp = nullptr;
        }
    }
}