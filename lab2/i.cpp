#include <iostream>
#include <string>

using namespace std;

struct Node {
    string book;
    Node* prev;
    Node* next;
    Node(string val) : book(val), prev(nullptr), next(nullptr) {}
};

class Doubl_list {

    private:
    Node* head;
    Node* tail;

    public:
    Doubl_list() : head(nullptr), tail(nullptr) {}

    void add_front(const string& name) {
        Node* newNode = new Node(name);
        if (!head) {
            head = tail = newNode;
        } 
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;

        }
        cout << "ok" << endl;
    }

    void add_back(const string& name) {
        Node* newNode = new Node(name);
        if(!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "ok" << endl;
    }

    void erase_front() {
        if(!head) {
            cout << "error" << endl;
            return ;
        }
        cout << head->book << endl;
        Node* temp = head;
        head = head->next;
        if(head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    void erase_back() {
        if(!tail) {
            cout << "error" << endl;
            return ;
        }
        cout << tail->book << endl;
        Node*temp = tail;
        tail = tail->prev;
        if(tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    void front() {
        if(head) cout << head->book << endl;
        else cout << "error" << endl;
    }

    void back() {
        if(tail) cout << tail->book << endl;
        else cout << "error" << endl;
    }


    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "ok" << endl;
    }

};

int main() {
    Doubl_list dl;
    string comm;

    while (cin >> comm) {
        if (comm == "add_front") {
            string name;
            cin >> name;
            dl.add_front(name);

        }
        else if(comm == "add_back") {
            string name;
            cin >> name;
            dl.add_back(name);
        }

        else if(comm == "erase_front") {
            dl.erase_front();
        }
        else if(comm == "erase_back") {
            dl.erase_back();
        }
        else if(comm == "front") {
            dl.front();
        }
        else if(comm == "back") {
            dl.back();
        }
        else if(comm == "clear") {
            dl.clear();
        }
        else if(comm == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}