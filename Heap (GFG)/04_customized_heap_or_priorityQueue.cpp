#include <iostream>
#include <queue>
using namespace std;

struct Person
{
    int age;
    float ht;
    Person(int a, float h)
    {
        age = a;
        ht = h;
    }
};

struct myCmp
{
    bool operator()(Person const &p1, Person const &p2)
    {
        return p1.ht < p2.ht;
    }
};

int main()
{
    priority_queue<Person, vector<Person>, myCmp> pq;

    Person p1(10, 5);
    Person p2(15, 4);
    Person p3(8, 10);

    pq.push(p1);
    pq.push(p2);
    pq.push(p3);

    while (pq.empty() == false)
    {
        cout << pq.top().age << " " << pq.top().ht;
        cout << endl;
        pq.pop();
    }
    return 0;
}