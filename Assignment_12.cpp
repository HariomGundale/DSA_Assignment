#include <iostream>
#include <string>
using namespace std;

#define SIZE 10  

class Employee {
    int empID;
    string name;

public:
    Employee() {
        empID = -1;  
        name = "";
    }

    void setEmployee(int id, const string& n) {
        empID = id;
        name = n;
    }

    int getID() const {
        return empID;
    }

    string getName() const {
        return name;
    }

    bool isEmpty() const {
        return empID == -1;
    }
};

class HashTable {
    Employee table[SIZE];
    bool occupied[SIZE];  

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            occupied[i] = false;
    }

    int hash(int key) {
        return key % SIZE;
    }

    void insert(int empID, const string& name) {
        int index = hash(empID);
        int startIndex = index;

        while (occupied[index]) {
            index = (index + 1) % SIZE;
            if (index == startIndex) {
                cout << " Hash table full! Cannot insert employee " << empID << endl;
                return;
            }
        }

        table[index].setEmployee(empID, name);
        occupied[index] = true;
        cout << " Employee inserted at index " << index << endl;
    }

    void search(int empID) {
        int index = hash(empID);
        int startIndex = index;

        while (occupied[index]) {
            if (table[index].getID() == empID) {
                cout << " Employee Found at index " << index << endl;
                cout << "   ID: " << table[index].getID()
                     << ", Name: " << table[index].getName() << endl;
                return;
            }

            index = (index + 1) % SIZE;
            if (index == startIndex)
                break;
        }
        cout << " Employee with ID " << empID << " not found.\n";
    }

    void display() {
        cout << "\n Employee Database:\n";
        for (int i = 0; i < SIZE; i++) {
            if (occupied[i])
                cout << i << " -> ID: " << table[i].getID()
                     << ", Name: " << table[i].getName() << endl;
            else
                cout << i << " -> Empty\n";
        }
    }
};

int main() {
    HashTable ht;
    int choice, id;
    string name;

    while (true) {
        cout << "\n===== EMPLOYEE HASH TABLE MENU =====\n";
        cout << "1. Insert Employee\n";
        cout << "2. Search Employee\n";
        cout << "3. Display Employee Database\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            cout << "Enter Employee Name: ";
            cin >> name;
            ht.insert(id, name);
            break;

        case 2:
            cout << "Enter Employee ID to search: ";
            cin >> id;
            ht.search(id);
            break;

        case 3:
            ht.display();
            break;

        case 4:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
