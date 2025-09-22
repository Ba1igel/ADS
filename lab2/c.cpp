#include <iostream>
#include <deque>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int main() {
    int m;
    cin >> m;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);

        if(head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    Node* cur = head;
    bool a = true;
    while(cur != nullptr) {
        if(a) {
            cout << cur->data << " ";
        }
        a = !a;
        cur = cur->next;
    }

}