#include <iostream>
#include <algorithm>
using namespace std;

//It does the minimum number of memory writes ,if EEPROM is being used we can use this to minimize memory writes
//Unstable and inplace sorting algo.
void cycleSort(int arr[], int n)
{
    for (int cs = 0; cs < n - 1; cs++)
    {
        int item = arr[cs];
        int pos = cs;
        for (int i = cs + 1; i < n; i++)
        {
            if (arr[i] < item)
                pos++;
        }

        //If item is already in correct position
        if (pos == cs)
            continue;
        //To ignore all duplicate items
        while (arr[pos] == item)
            pos++;
        //Putting the item to right pos
        if (pos != cs)
            swap(item, arr[pos]);
        while (pos != cs)
        {
            pos = cs;
            for (int i = cs + 1; i < n; i++)
            {
                if (arr[i] < item)
                    pos++;
            }

            //ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;
            //Putting the item to right pos
            if (item != arr[pos])
                swap(item, arr[pos]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cycleSort(arr, n);
    for (int num : arr)
        cout << num << " ";
    return 0;
}
