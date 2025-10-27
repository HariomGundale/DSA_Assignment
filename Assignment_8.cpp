#include <bits/stdc++.h>
using namespace std;

class Qqueue
{
public:
    int ID;
    string customerName;
    Qqueue *next;

    Qqueue(string name, int id)
    {
        customerName = name;
        ID = id;
        next = NULL;
    }
};

class TicketingSystem
{
    Qqueue *front;
    Qqueue *rear;

public:
    TicketingSystem()
    {
        front = rear = NULL;
    }

    void enqueue(string name, int id)
    {
        Qqueue *newNode = new Qqueue(name, id);

        if (front == NULL)
        {
            front = rear = newNode;
            rear->next = front;
            return;
        }

        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    // Urgent Enqueue
    void urgentEnqueue(string name, int id)
    {
        Qqueue *newNode = new Qqueue(name, id);

        if (front == NULL)
        {
            front = rear = newNode;
            rear->next = front;
            return;
        }

        newNode->next = front;
        front = newNode;
        rear->next = front;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "No tickets to resolve. ; Queue is empty \n";
            return;
        }

        Qqueue *temp = front;

        if (front == rear)
        {
            cout << "Resolving ticket: " << temp->ID << " " << temp->customerName << endl;
            delete temp;
            front = rear = NULL;
            return;
        }

        cout << "Resolving ticket: " << temp->ID << " " << temp->customerName << endl;

        front = front->next;
        rear->next = front;                 
        delete temp;
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty\n";
            return;
        }

        Qqueue *temp = front;
        cout << "\n Tickets in Queue:\n";
        do
        {
            cout << "Ticket ID: " << temp->ID << " || Customer Name: " << temp->customerName << endl;
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main()
{
    int GlobalID = 1;
    TicketingSystem ts;

    while (true)
    {
        int choice;
        cout << "\n1. Add ticket"
             << "\n2. Add urgent ticket"
             << "\n3. Resolve ticket"
             << "\n4. Display tickets"
             << "\n5. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            ts.enqueue(name, GlobalID++);
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            ts.urgentEnqueue(name, GlobalID++);
            break;
        }
        case 3:
            ts.dequeue();
            break;
        case 4:
            ts.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Enter valid choice!\n";
        }
    }
}