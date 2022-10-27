// Circular linked list
#include <iostream>
using namespace std;

template <class T>
struct node {
    T info;
    node *next;
};

template <class T>
class List {
    node<T> *head, *tail;

public:
    List() {
        head = tail = nullptr;
    }

    void insertBeginning(T x) {
        node<T> *ptr = new node<T>;
        ptr->info = x;
        if (!head) {
            ptr->next = ptr;
            head = tail = ptr;
        } else {
            ptr->next = head;
            head = ptr;
            tail->next = ptr;
        }
    }

    void insertEnd(T x) {
        node<T> *ptr = new node<T>;
        ptr->info = x;
        if (!head) { // Empty list
            ptr->next = ptr;
            head = tail = ptr;
        } else {
            ptr->next = head;
            tail->next = ptr;
            tail = ptr;
        }
    }

    void insertAfter(T x, T after) {
        if (!head) {
            cout << "Invalid insertion: Empty list\n";
            return;
        }
        node<T> *i = head;
        while (i->info != after) {
            i = i->next;
            if (i == head) {
                cout << "Invalid insertion: Element " << after << " not found\n";
                return;
            }
        }
        node<T> *ptr = new node<T>;
        ptr->info = x;
        ptr->next = i->next;
        i->next = ptr;
    }

    void insertBefore(T x, T before) {
        if (!head)
            cout << "Invalid insertion: Empty list\n";
        else if (head->info == before)
            insertBeginning(x);
        else {
            node<T> *i, *prev;
            i = head;
            while (i->info != before) {
                prev = i;
                i = i->next;
                if (i == head) {
                    cout << "Invalid insertion: Element " << before << "  not found\n";
                    return;
                }
            }
            node<T> *ptr = new node<T>;
            ptr->info = x;
            ptr->next = i;
            prev->next = ptr;
        }
    }

    void deleteBeginning() {
        if (!head) {
            cout << "Invalid deletion: Empty list\n";
        } else if (head->next == head) {
            cout << "Deleted item = " << head->info << endl;
            delete head;
            head = tail = nullptr;
        } else {
            node<T> *ptr = head;
            cout << "Deleted item = " << ptr->info << endl;
            head = head->next;
            tail->next = head;
            delete ptr;
        }
    }

    void deleteEnd() {
        if (!head) {
            cout << "Invalid deletion: Empty list\n";
        } else if (head->next == head) {
            cout << "Deleted item = " << head->info << endl;
            delete head;
            head = tail = nullptr;
        } else {
            node<T> *prev, *ptr = head;
            while (ptr->next != head) {
                prev = ptr;
                ptr = ptr->next;
            }
            cout << "Deleted item = " << ptr->info << endl;
            prev->next = head;
            tail = prev;
            delete ptr;
        }
    }

    void deleteAfter(T after) {
        if (!head) {
            cout << "Invalid deletion: Empty list\n";
            return;
        }
        node<T> *i = head;
        while (i->info != after) {
            i = i->next;
            if (i == head) {
                cout << "Invalid deletion: Element " << after << " not found\n";
                return;
            }
        }
        node<T> *ptr = i->next;
        cout << "Deleted item = " << ptr->info << endl;
        i->next = ptr->next;
        delete ptr;
    }

    void display() {
        cout << "\nDisplaying items in a circular linked list: ";
        if (!head) {
            cout << "Empty list\n";
            return;
        }
        node<T> *i = head;
        while (1) {
            cout << i->info << ' ';
            i = i->next;
            if (i == head)
                break;
        }
        cout << "\n\n";
    }
};

int main() {
    List<int> list;
    list.insertBeginning(10);
    list.insertBeginning(20);
    list.insertEnd(40);
    list.insertAfter(30, 20);
    list.insertBefore(50, 40);
    list.display();
    list.deleteBeginning();
    list.deleteEnd();
    list.deleteAfter(30);
    list.display();
}
