// Priority Queue (by default) act as maxHeap
// Priority Queue is implemented using heap data structure
// We can modify the declaration of priority queue to make a minHeap
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // For creating maxHeap
    priority_queue<int> pq;
    // For creating minHeap
    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq.push(10);
    pq_min.push(10);
    pq.push(15);
    pq_min.push(15);
    pq.push(5);
    pq_min.push(5);

    cout << pq.size() << endl;
    cout << pq.top() << endl;
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    cout << pq_min.size() << endl;
    cout << pq_min.top() << endl;
    while (pq_min.empty() == false)
    {
        cout << pq_min.top() << " ";
        pq_min.pop();
    }
    return 0;
}