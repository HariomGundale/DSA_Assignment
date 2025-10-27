#include <bits/stdc++.h>
using namespace std;

// partition and sort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// quick sort
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> quantities;
    int n;

    cout << "Enter number of inventory items: ";
    cin >> n;

    cout << "Enter stock quantities:\n";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        quantities.push_back(temp);
    }

    quickSort(quantities, 0, n - 1);

    cout << "\nSorted stock quantities (Ascending):\n";
    for (int i = 0; i < quantities.size(); i++)
    {
        cout << quantities[i] << " ";
    }
    cout << endl;

    return 0;
}
