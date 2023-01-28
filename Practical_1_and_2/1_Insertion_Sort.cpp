#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++){
        cout << "Enter the " << i << " element of the array : ";
        cin >> arr[i];
    }

    cout << "\nBefore Sorting: ";
    for (int x : arr){
        cout << x << " ";
    }

    // ********************************************************************

    int j, key, comparisons=0, shiftings=0;

    for (int i = 0; i < n; i++){
        key = arr[i];
        j = i - 1;

        comparisons++;
        while (j >= 0 && arr[j] > key){
            comparisons++;
            shiftings++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    cout << "\n\nNumber of comparisons done: " << comparisons <<endl;
    cout << "Number of shiftings done: " << shiftings <<endl;

    cout << "\n\nAfter sorting : " ;
    for (int x : arr){
        cout << x << " ";
    }

    return 0;
}