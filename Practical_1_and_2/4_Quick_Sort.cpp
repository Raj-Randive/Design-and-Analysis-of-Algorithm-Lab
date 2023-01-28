#include <iostream>
using namespace std;

void swap(int *p, int *q);
int partition(int arr[], int l, int h);
void quicksort(int arr[], int l, int h);

int main(){
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

    quicksort(arr, 0, (n - 1));

    cout << "\nBefore Sorting: ";
    for (int x : arr){
        cout << x << " ";
    }

    return 0;
}

int partition(int arr[], int l, int h){
    int pivot = arr[h];
    int i, j;
    i = (l - 1);
    for (j = l; j <= (h - 1); j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quicksort(int arr[], int l, int h){
    if (l < h)
    {
        int pivot;
        pivot = partition(arr, l, h);
        quicksort(arr, l, (pivot - 1));
        quicksort(arr, (pivot + 1), h);
    }
}

void swap(int *p, int *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
