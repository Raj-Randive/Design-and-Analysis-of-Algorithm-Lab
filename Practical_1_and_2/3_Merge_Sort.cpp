#include<iostream>
using namespace std;

void mergeTwoArrays(int arr[], int l, int mid, int r);
void mergeSort(int arr[], int l, int r);
void printArray(int arr[], int size);

int main(){

    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr1[n];

    for (int i = 0; i < n; i++){
        cout << "Enter the " << i << " element of the array : ";
        cin >> arr1[i];
    }

    cout << "\nBefore Sorting: ";
    printArray(arr1, n);

    mergeSort(arr1, 0, n-1);
    cout << "\nAfter Sorting : ";
    printArray(arr1, n);

    return 0;
}

// **************************************************************

void mergeSort(int arr[], int l, int r){
    if(l >= r){
        return;
    }
    if (l < r){
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        mergeTwoArrays(arr, l, mid, r);
    }
}

void mergeTwoArrays(int arr[], int l, int mid, int r){

    int arrOneSize = mid - l + 1;
    int arrTwoSize = r-mid;

    int * leftArr = new int[arrOneSize];
    int * rightArr = new int[arrTwoSize];

    for (int i = 0; i < arrOneSize; i++){
        leftArr[i] = arr[l+i];
    }

    for (int j = 0; j < arrTwoSize; j++){
        rightArr[j] = arr[mid+1+j];
    }

    int arrOneIndex = 0;
    int arrTwoIndex = 0;
    int mergedArrIndex = l;

    while((arrOneIndex < arrOneSize) && (arrTwoIndex < arrTwoSize) ){
        if (leftArr[arrOneIndex] <= rightArr[arrTwoIndex] )
        {
            arr[mergedArrIndex] = leftArr[arrOneIndex];
            arrOneIndex++;
        }
        else{
            arr[mergedArrIndex] = rightArr[arrTwoIndex];
            arrTwoIndex++;
        }

        mergedArrIndex++;
    }

    while (arrOneIndex < arrOneSize)
    {
        arr[mergedArrIndex] = leftArr[arrOneIndex];
        arrOneIndex++;
        mergedArrIndex++;
    }

    while (arrTwoIndex < arrTwoSize)
    {
        arr[mergedArrIndex] = rightArr[arrTwoIndex];
        arrTwoIndex++;
        mergedArrIndex++;
    }

    delete [] leftArr;
    delete [] rightArr;
}

void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}