#include <bits/stdc++.h>
using namespace std;
void mergingTwoArray(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int length1 = mid - s + 1;
    int length2 = e - mid;

    // creating a dynamic array
    int *left = new int[length1];
    int *right = new int[length2];

    int mainArrayIndex = s;
    // putting element of main array in left side
    for (int i = 0; i < length1; i++)
    {
        left[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    // putting element of main array in right side
    for (int i = 0; i < length2; i++)
    {
        right[i] = arr[mainArrayIndex++];
    }

    // now merge the two left n right sorted array
    int index1 = 0;
    int index2 = 0;

    while (index1 < length1 && index2 < length2)
    {
        if (left[index1] < right[index2])
        {

            arr[mainArrayIndex] = left[index1];
            mainArrayIndex++;
            index1++;
        }
        else
        {
            arr[mainArrayIndex] = right[index2];
            mainArrayIndex++;
            index2++;
        }
    }
    while (index1 < length1)
    {
        arr[mainArrayIndex] = left[index1];
    }
    while (index2 < length2)
    {
        arr[mainArrayIndex] = right[index2];
    }
}
void mergeSort(int *arr, int s, int e)
{
    // baseCase as baseCase is mandatory in recursion
    // cout << "adwde";
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    // now we will sort the left part of array
    mergeSort(arr, s, mid);

    // now we will sort the right part of array
    mergeSort(arr, mid + 1, e);

    // now we will merge two sorted array
    mergingTwoArray(arr, s, e);
}
int main()
{
    int arr[5] = {54, 23, 76, 12, 96};
    int size = 5;
    mergeSort(arr, 0, size - 1); // passing parameters
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}