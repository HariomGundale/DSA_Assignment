#include <iostream>
using namespace std;

class node {
public:
    string data;
    node* next;

    node() {
        data = "0";
        next = NULL;
    }
};

class LL {
private:
    node* head;

public:
    LL() {
        head = NULL;
    }

    void insertAtEnd(string d) {
        node* nn = new node;
        nn->data = d;
        nn->next = NULL;
        if (head == NULL) {
            head = nn;
        } else {
            node* t = head;
            while (t->next)
                t = t->next;
            t->next = nn;
        }
    }

    void insertAtHead(string d) {
        node* nn = new node;
        nn->data = d;
        nn->next = head;
        head = nn;
    }

    void insertAtPos(int position, string d) {
        node* nn = new node;
        nn->data = d;
        nn->next = NULL;
        if (position == 1) {
            insertAtHead(d);
            return;
        }

        node* t = head;
        for (int i = 1; i < position - 1 && t != NULL; i++) {
            t = t->next;
        }
        if (t) {
            nn->next = t->next;
            t->next = nn;
        }
    }

    void deletefromfront() {
        if (head == NULL) {
            cout << "Linked List is empty.";
        } else {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deletefromend() {
        if (head == NULL) {
            cout << "Linked List is empty.";
        } else {
            node* temp = head;
            node* k = head;
            while (temp->next != NULL) {
                k = temp;
                temp = temp->next;
            }
            k->next = NULL;
            delete temp;
        }
    }

    void deleteatpos(int d) {
        int count = 1;
        node* temp = head;
        node* k = head;
        while (count != d) {
            k = temp;
            temp = temp->next;
            count++;
        }
        k->next = temp->next;
        delete temp;
    }

    void navigate(int d) {
        if (head == NULL) {
            cout << "Linked list is empty";
        } else {
            int count = 1;
            node* temp = head;
            node* k = head;
            node* t = temp->next;
            while (count != d) {
                k = temp;
                temp = temp->next;
                t = t->next;
                count++;
            }
            if (temp == head) {
                cout << "Playlist start from Current" << endl;
                cout << "Current:" << temp->data << "\t"
                     << "Next:" << t->data << endl;
            } else if (temp->next == NULL) {
                cout << "Current:" << temp->data << "\t"
                     << "Previous:" << k->data << "\t" << endl;
                cout << "Current Song is end of playlist.";
            } else {
                cout << "Current:" << temp->data << "\t"
                     << "Previous:" << k->data << "\t"
                     << "Next:" << t->data << endl;
            }
        }
    }

    void printList() {
        node* t = head;
        while (t) {
            cout << t->data << endl;
            t = t->next;
        }
    }
};

int main() {
    LL myList;
    int c, d;
    string song;

    while (c != 9) {
        cout << "1) Insert a song at end in playlist.\n"
             << "2) Insert a song at first in playlist.\n"
             << "3) Insert a song at specific position in playlist.\n"
             << "4) Delete a song from end in playlist.\n"
             << "5) Delete a song from first in playlist.\n"
             << "6) Delete any song from Playlist.\n"
             << "7) Navigate a song\n"
             << "8) Show the playlist\n"
             << "9) Exit\n";

        cout << "Enter the Choice: ";
        cin >> c;

        switch (c) {
            case 1:
                cout << "Enter the name of song: ";
                cin >> song;
                myList.insertAtEnd(song);
                break;

            case 2:
                cout << "Enter the name of song: ";
                cin >> song;
                myList.insertAtHead(song);
                break;

            case 3:
                cout << "Enter the name of song: ";
                cin >> song;
                cout << "Enter the position to be insert in playlist: ";
                cin >> d;
                myList.insertAtPos(d, song);
                break;

            case 4:
                myList.deletefromend();
                break;

            case 5:
                myList.deletefromfront();
                break;

            case 6:
                cout << "Enter the no of song: ";
                cin >> d;
                myList.deleteatpos(d);
                break;

            case 7:
                cout << "Enter the no of song: ";
                cin >> d;
                myList.navigate(d);
                break;

            case 8:
                myList.printList();
                break;

            case 9:
                cout << "Exiting the Playlist!" << endl;
                break;

            default:
                cout << "Enter a valid choice";
                break;
        }
    }

    return 0;
}
