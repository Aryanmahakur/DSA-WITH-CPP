#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
    vector<int> heap;

    // Heapify Up
    void heapifyUp(int i)
    {
        while (i > 0)
        {
            int parent = (i - 1) / 2;

            if (heap[parent] <= heap[i])
                break;

            swap(heap[parent], heap[i]);

            i = parent;
        }
    }
    void buildHeap()
    {
        int n = heap.size();

        // Start from last non-leaf node
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            heapifyDown(i);
        }
    }
    // Heapify Down
    void heapifyDown(int i)
    {
        int n = heap.size();

        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i)
                break;

            swap(heap[i], heap[smallest]);

            i = smallest;
        }
    }

public:
    // INSERTION
    void insert(int value)
    {
        heap.push_back(value);

        // Start from newly inserted element
        heapifyUp(heap.size() - 1);
    }

    // DELETE MINIMUM (ROOT)
    void deleteMin()
    {

        if (heap.empty())
        {
            cout << "Heap is empty\n";
            return;
        }

        // Replace root with last element
        heap[0] = heap.back();

        // Remove last element
        heap.pop_back();

        // Restore heap property
        if (!heap.empty())
            heapifyDown(0);
    }

    // PRINT
    void print()
    {
        for (int x : heap)
            cout << x << " ";

        cout << endl;
    }
};

int main()
{

    MinHeap h;

    // Insertion
    h.insert(30);
    h.insert(20);
    h.insert(10);
    h.insert(40);
    h.insert(5);

    cout << "After insertion: ";
    h.print();

    // Deletion
    h.deleteMin();

    cout << "After deletion: ";
    h.print();

    return 0;
}