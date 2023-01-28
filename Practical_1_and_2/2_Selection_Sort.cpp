#include<iostream>
using namespace std;

void swap(int *a, int *b);

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

    // ********************************************************************

    int comparisons=0, swappings=0;
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < n; j++)
        {
            comparisons++;
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            } 
        }
        if (minIndex != i){
                swappings++;
                swap(&arr[minIndex], &arr[i]);
        }  
    }
    
    cout << "\n\nNumber of comparisons done: " << comparisons <<endl;
    cout << "Number of swappings done: " << swappings <<endl;
    
    cout << "\nAfter sorting : " ;
    for (int x : arr){
        cout << x << " ";
    }

    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}