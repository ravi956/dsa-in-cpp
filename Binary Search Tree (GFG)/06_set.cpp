// set uses RED-BLACK TREE (which is a self balancing binary search tree)
#include <iostream>
#include <set>
using namespace std;

int main()
{
    // Normal set (increasing order)

    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);

    for (int x : s)
        cout << x << " ";
    cout << endl;

    // Using greater<int> for maintaining set in (decreasing order)

    set<int, greater<int>> sg;
    sg.insert(10);
    sg.insert(5);
    sg.insert(20);

    for (int x : sg)
        cout << x << " ";
    cout << endl;

    // Use of iterators -> begin() and end()

    // auto can be replaced by set<int> :: iterator
    for (auto it = sg.begin(); it != sg.end(); it++)
        cout << (*it) << " ";
    cout << endl;

    // Use of reverse iterators -> rbegin() and rend()

    for (auto it = sg.rbegin(); it != sg.rend(); it++)
        cout << (*it) << " ";
    cout << endl;

    // Set ignores the duplicate values

    sg.insert(15);
    sg.insert(15); // ignored
    sg.insert(15); // ignored
    for (int x : sg)
        cout << x << " ";
    cout << endl;

    // find() is used to search an element in the set
    // it returns the iterator to the element if found
    // otherwise returns an iterator to end() iterator

    auto it = sg.find(10);
    if (it == s.end())
        cout << "Not Found\n";
    else
        cout << "Found\n";

    // clear() deletes all the elements from the set

    s.clear();
    cout << s.size() << endl;

    // count() gives count of the element but it is 1 for all present elements
    // and if element is not present in the set it returns 0
    // this can be used instead of find() to check if element is present or not

    if (sg.count(10))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    // erase() deletes the element [passing element to be deleted]

    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(7);
    s.erase(5);
    for (int x : s)
        cout << x << " ";
    cout << endl;

    // erase() deletes the element [passing iterator to the element to be deleted]

    auto itr = s.find(10);
    s.erase(itr);
    for (int x : s)
        cout << x << " ";
    cout << endl;

    // erase() deleting a range of elements[passing of the starting iterator and an ending itrator (excluding)]

    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(7);    // set s -> [5,7,10,20]
    it = s.find(7); // it is declared before
    s.erase(it, s.end());

    for (int x : s)
        cout << x << " ";
    cout << endl;

    // lower_bound() or upper_bound() as a member function
    // returns iterator to the lower_bound() or upper_bound()
    // if lower_bound() or upper_bound() does not exist returns end() iterator

    // lower_bound() -> returns iterator to the element if present or iterator to just greater if not present
    // upper_bound() -> returns iterator to the element just greater if present or not
    // if element is greater than the greatest then returns s.end() iterator

    s.insert(10);
    s.insert(5);
    s.insert(20);
    it = s.lower_bound(6);
    if (it != s.end())
        cout << (*it) << endl;
    else
        cout << "Given element is greater than the largest\n";

    return 0;
}