// C++ program to demonstrate implementation of our
// own hash table with chaining for collision detection

#include <bits/stdc++.h>
using namespace std;

struct MyHash
{
    int BUCKET;
    list<int> *table;
    MyHash(int b)
    {
        BUCKET = b;
        table = new list<int>[BUCKET];
    }
    void insert(int key)
    {
        int i = key % BUCKET;
        table[i].push_back(key);
    }
    void remove(int key)
    {
        int i = key % BUCKET;
        table[i].remove(key);
    }
    bool search(int key)
    {
        int i = key % BUCKET;
        for (auto x : table[i])
            if (x == key)
                return true;
        return false;
    }
};

int main()
{
    MyHash h(7);
    h.insert(70);
    h.insert(71);
    h.insert(5);
    h.insert(72);
    h.insert(56);
    cout << h.search(56) << endl;
    h.remove(56);
    cout << h.search(56);
}