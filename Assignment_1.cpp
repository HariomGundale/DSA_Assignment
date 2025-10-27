#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    double score;
};

void insertionSort(vector<Student>& a) {
    for (int i = 1; i < (int)a.size(); ++i) {
        Student key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j].score < key.score) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Student> students;

    for (int i = 0; i < n; ++i) {
        Student s;
        cout << "\nEnter name of student " << (i + 1) << ": ";
        getline(cin, s.name);
        cout << "Enter score of " << s.name << ": ";
        cin >> s.score;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        students.push_back(s);
    }
    insertionSort(students);
    int rank = 1;
    double prevScore = -1;

    for (int i = 0; i < n; ++i) {
        if (i > 0 && students[i].score != prevScore)
            rank = i + 1;

        cout << "Rank " << rank << ": " 
             << students[i].name 
             << " — Score: " << students[i].score << endl;

        prevScore = students[i].score;
    }
    return 0;
}
