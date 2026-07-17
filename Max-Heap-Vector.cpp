#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
public:
    vector<int> heap;

    // Heapify Up
    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (heap[parent] < heap[index])
            {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else
                break;
        }
    }

    // Insert
    void insert(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Heapify Down
    void heapifyDown(int index)
    {
        while (true)
        {
            int largest = index;

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < heap.size() && heap[left] > heap[largest])
                largest = left;

            if (right < heap.size() && heap[right] > heap[largest])
                largest = right;

            if (largest == index)
                break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

    // Delete Root
    void deleteRoot()
    {
        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    // Build Heap
    void buildHeap(const vector<int>& arr)
    {
        heap = arr;

        for (int i = heap.size() / 2 - 1; i >= 0; i--)
            heapifyDown(i);
    }

    // Peek (Maximum Element)
    int peek()
    {
        if (heap.empty())
            return -1;

        return heap[0];
    }

    // Replace Root
    void replaceRoot(int val)
    {
        if (heap.empty())
        {
            heap.push_back(val);
            return;
        }

        heap[0] = val;
        heapifyDown(0);
    }

    // Replace Any Index
    void replace(int index, int val)
    {
        if (index < 0 || index >= heap.size())
            return;

        int old = heap[index];
        heap[index] = val;

        if (val > old)
            heapifyUp(index);
        else
            heapifyDown(index);
    }

    // Print Heap
    void print()
    {
        for (int x : heap)
            cout << x << " ";

        cout << endl;
    }
};

int main()
{
    MaxHeap h;

    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(20);
    h.insert(60);
    h.insert(90);

    cout << "After Insert:\n";
    h.print();

    cout << "\nPeek: " << h.peek() << endl;

    h.deleteRoot();

    cout << "\nAfter Delete Root:\n";
    h.print();

    h.replaceRoot(40);

    cout << "\nAfter Replace Root with 40:\n";
    h.print();

    h.replace(2, 100);

    cout << "\nAfter Replace index 2 with 100:\n";
    h.print();

    vector<int> arr = {10, 50, 20, 5, 70, 60, 80};

    h.buildHeap(arr);

    cout << "\nAfter Build Heap:\n";
    h.print();

    return 0;
}