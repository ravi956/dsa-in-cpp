#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Example for maxHeap
    int arr[] = {10, 5, 15};
    priority_queue<int> pq(arr, arr + 3);
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // Example for minHeap (if you don't want to use that complex syntax of creating minHeap by priority_queue)
    for (int i = 0; i < 3; i++)
        arr[i] = -arr[i];
    priority_queue<int> pq_min(arr, arr + 3);
    while (pq_min.empty() == false)
    {
        cout << -pq_min.top() << " ";
        pq_min.pop();
    }

    return 0;
}