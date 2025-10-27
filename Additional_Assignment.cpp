#include <iostream>
#include <deque>
#include <string>
using namespace std;

class BrowserHistory {
private:
    deque<string> history;   
    int current;             
    int capacity;            

public:
    BrowserHistory(int cap) {
        capacity = cap;
        current = -1; 
    }

    
    void visit(const string& url) {
        
        while ((int)history.size() > current + 1)
            history.pop_back();

        
        history.push_back(url);
        current++;

        
        if ((int)history.size() > capacity) {
            history.pop_front();
            current--;
        }

        cout << "Visited: " << history[current] << endl;
    }

    
    void back(int steps) {
        if (current == -1) {
            cout << "No pages visited yet!" << endl;
            return;
        }

        current = max(0, current - steps);
        cout << "Current page after going back: " << history[current] << endl;
    }

    void forward(int steps) {
        if (current == -1) {
            cout << "No pages visited yet!" << endl;
            return;
        }

        current = min((int)history.size() - 1, current + steps);
        cout << "Current page after going forward: " << history[current] << endl;
    }

    void display() {
        if (history.empty()) {
            cout << "History is empty!\n";
            return;
        }

        cout << "\nBrowser History (Oldest -> Newest):\n";
        for (int i = 0; i < (int)history.size(); i++) {
            if (i == current)
                cout << " -> [Current] " << history[i] << endl;
            else
                cout << "   " << history[i] << endl;
        }
    }
};

int main() {
    int capacity, choice, steps;
    string url;

    cout << "Enter maximum browser history capacity: ";
    cin >> capacity;

    BrowserHistory browser(capacity);

    while (true) {
        cout << "\n===== BROWSER HISTORY MENU =====\n";
        cout << "1. Visit new page\n";
        cout << "2. Go back\n";
        cout << "3. Go forward\n";
        cout << "4. Display history\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter URL to visit: ";
            cin >> url;
            browser.visit(url);
            break;

        case 2:
            cout << "Enter number of steps to go back: ";
            cin >> steps;
            browser.back(steps);
            break;

        case 3:
            cout << "Enter number of steps to go forward: ";
            cin >> steps;
            browser.forward(steps);
            break;

        case 4:
            browser.display();
            break;

        case 5:
            cout << "Exiting program...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
