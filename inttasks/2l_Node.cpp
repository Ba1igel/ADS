#include <iostream>

using namespace std;

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr; // тоже самое что и нулл
    }
};

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);   // создаём новый узел со значением x

        if (head == nullptr) {         // если список пустой (первый элемент)
            head = newNode;            // делаем новый узел головой
            tail = newNode;            // и хвостом (пока он единственный)
        }
        else {
            newNode->next = head;      // новый узел указывает на старую голову
            head = newNode;            // теперь новый узел становится головой
        }

        Node* cur = head; // ну короче в сиааут мы не можем хеад->data
                            // крч не читает стринг инты а так сможет

        bool a = true;
        while(cur != nullptr) {
            if(a) {
                cout << cur->data << " ";
            }

            cur = cur->next; // переходим на след 
        }

    }
}

