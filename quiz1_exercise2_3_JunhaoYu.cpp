#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

template <typename T>
class MaxHeap
{
    vector<T> heap;
    void SiftUp(int i)
    {
        while (i > 0 && heap[i] > heap[(i - 1) / 2])
        {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
    void SiftDown(int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < heap.size() && heap[left] > heap[largest])
        {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            SiftDown(largest);
        }
    }

public:
    void Add(T val)
    {
        heap.push_back(val);
        SiftUp(heap.size() - 1);
    }
    void Remove()
    {
        if (heap.empty())
        {
            return;
        }
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        SiftDown(0);
    }
    void Print()
    {
        copy(heap.begin(), heap.end(), ostream_iterator<T>(cout, " "));
        cout << endl;
    }
};

int main()
{
    MaxHeap<int> heap;
    heap.Add(3);
    heap.Add(1);
    heap.Add(4);
    heap.Add(1);
    heap.Add(5);
    heap.Add(9);
    heap.Add(2);
    heap.Add(6);
    heap.Add(5);
    heap.Add(3);
    heap.Add(5);
    heap.Print();
    heap.Remove();
    heap.Print();
    heap.Remove();
    heap.Print();
    return 0;
}
