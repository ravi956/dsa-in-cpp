//implementation of open addressing method of hashing using Linear Probing

#include <bits/stdc++.h>
using namespace std;

class MyHash
{
public:
    int *arr;
    int size, cap;
    MyHash(int n)
    {
        size = 0;
        cap = n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = -1;
    }
    int hash(int key)
    {
        return key % cap;
    }
    bool insert(int key)
    {
        if (size == cap)
            return false;
        int i = hash(key);
        while (arr[i] != -1 && arr[i] != -2 && arr[i] != key)
            i = (i + 1) % cap;
        if (arr[i] == key)
            return false;
        else
        {
            arr[i] = key;
            size++;
            return true;
        }
    }
    bool search(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
                return true;
            i = (i + 1) % cap;
            if (i == h)
                return false;
        }
        return false;
    }
    bool erase(int key)
    {
        if (size == 0)
            return false;
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                arr[i] = -2;
                return true;
            }
            i = (i + 1) % cap;
            if (i == h)
                return false;
        }
        return false;
    }
    void print()
    {
        for (int i = 0; i < cap; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};

int main()
{
    MyHash mh(7);
    mh.insert(7);
    mh.insert(8);
    mh.insert(15);
    if (mh.search(7) == true)
        cout << "Yes\n";
    else
        cout << "No\n";
    if (mh.search(10) == true)
        cout << "Yes\n";
    else
        cout << "No\n";
    mh.print();
    mh.erase(9);
    mh.erase(8);
    mh.print();
    return 0;
}