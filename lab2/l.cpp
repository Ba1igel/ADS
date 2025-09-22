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

int maxsum(Node* head) {
    if (!head) return 0;

    int max_sum = head->data; // крч самый первый sum у нас хэд а потом считаем
    int cur_sum = head->data; // текущий сум это тоже хэд

    Node* cur = head->next;
    while(cur) {
        cur_sum = max(cur->data, cur_sum + cur->data);  /*cure->data наш текущие елемент,
         cur_sum(предыдущий сум) + cur->data(наш текущий елемент) 
         - если сумма предыдущего и текущего больше чем просто текущий то мы берем сумму, */

        max_sum = max(max_sum, cur_sum);  /* max_sum(макс сумма которя у нас когда либо была,
                                        (cur_sum) текущий сум) и оно выберает у нас максимум */
        cur = cur->next; // переходим на след ел

        
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    int count = 0;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);
        if(head == nullptr) {
            newNode = newNode;
            head = newNode;
        }
        else {
            newNode->next = head;
            tail = newNode;
        }
        count += newNode->data;

    }
    cout << maxsum << endl;
    

    return 0;
}