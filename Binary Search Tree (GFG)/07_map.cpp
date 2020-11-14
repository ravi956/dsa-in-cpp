// map also uses RED-BLACK TREE (which is a self balancing binary search tree)
#include <iostream>
#include <map>
using namespace std;

int main()
{
    // Normal map

    map<int, int> m;
    m.insert({10, 200});
    m[5] = 300;
    m.insert({20, 100});

    for (auto x : m)
        cout << x.first << " " << x.second << " ";
    cout << endl;

    // Duplicate keys are ignored even if the value associated with the key is different

    m.insert({15, 500});
    m.insert({15, 800}); // ignored
    for (auto x : m)
        cout << x.first << " " << x.second << " ";
    cout << endl;

    // Difference bw insert() and square [] operator

    m.clear();
    m.insert({10, 200});
    cout << m.size() << endl;
    cout << m[20] << endl;    // 20 as a key was not present but on accessing by using [] operator
    cout << m.size() << endl; // //it will insert a key value pair {20,default_value} , here def_vl = 0
    // [] is also used to modify the value of the pair

    // Use of m.at() function
    // it is also used to modify the value of the pair
    // but unlike [] , it will throw out of range exception if the key is not present in map
    // instead of creating a pair

    m.at(10) = 400;
    cout << m[10] << endl;

    // Use of iterators -> begin() , end() and clear()

    m.clear(); // clear the map
    m.insert({15, 100});
    m.insert({20, 400});
    m.insert({10, 300});

    // auto can be replaced by map<int,int> :: iterator
    for (auto it = m.begin(); it != m.end(); it++)
        cout << (*it).first << " " << (*it).second << " ";
    cout << endl;

    /*
    find(), count(), lower_bound(), upper_bound(), erase()
    all take key as arguments not value 
    and behave same as in the case of set
    */

    return 0;
}