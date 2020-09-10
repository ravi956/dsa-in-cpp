#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &arr, int last) //Hypothesis
{
    if (arr.size() == 0 || arr[arr.size() - 1] <= last) //Base Case
    {
        arr.push_back(last);
        return;
    }
    int temp = arr[arr.size() - 1];
    arr.pop_back();      //Induction
    insert(arr, last);   //Hypothesis
    arr.push_back(temp); //Induction
}

void sort(vector<int> &arr) //Hypothesis that it will sort all elements of array
{
    if (arr.size() == 1) //Base case -> array of one element is sorted in itself
        return;
    int last = arr[arr.size() - 1];
    arr.pop_back();
    sort(arr);         //this will sort all elements in the array excluding the last one which is popped out and stored in the last
    insert(arr, last); //Induction this is also a recursive func which will insert the last element at its position in the sorted array
}

int main()
{
    int n;
    cout << "***************Program to sort array/vector using Recursion******************\n";
    cout << "Enter no. of element in the array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr); //Recursive function to sort array
    cout << "Elements after Sorting are : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}