// // //// QUESTION //// //
// Implement Max Heap

// You need to implement the Max Heap with the following given methods.

// insert (x) -> insert value x to the max heap
// getMax -> Output the maximum value from the max heap
// exctractMax -> Remove the maximum element from the heap
// heapSize -> return the current size of the heap
// isEmpty -> returns if heap is empty or not
// changeKey (ind, val) -> update the value at given index to val (index will be given 0-based indexing)
// initializeHeap -> Initialize the heap

// Note: When extracting max, if both left and right children are equal, you must swap with the LEFT child.

// Example 1

// Input : operation = [ "initializeHeap", "insert", "insert", "insert", "getMax", "heapSize", "isEmpty", "exctractMax", "changeKey" , "getMax" ]

// nums = [ [4], [1], [10], [0, 16] ]

// Output : [ null, null, null, null, 10, 3, 0, null, null, 16 ]

// Explanation :

// In 1st operation we initialize the heap to empty heap.

// In 2nd, 3rd, 4th operation we insert 4, 1, 10 to the heap respectively. The heap after 4th operation will be -> [10, 4, 1].

// In 5th operation we output the maximum element from the heap i.e. 10.

// In 6th operation we output the size of the current heap i.e. 3.

// In 7th operation we output whether the heap is empty or not i.e. false (0).

// In 8th operation we remove the maximum element from heap. So the ne heap becomes -> [4, 1].

// In 9th operation we change the 0th index element to 16. So new heap becomes -> [16, 1]. After heapify -> [16, 1].

// In 10th operation we output the maximum element of the heap i.e. 16.

// Example 2

// Input : operation = [ "initializeHeap", "insert", "insert", "exctractMax", "getMax", "insert", "heapSize", "isEmpty", "exctractMax", "changeKey" , "getMax" ]

// nums = [ [4], [1], [4], [0, 2] ]

// Output : [ null, null, null, null, 1, null, 2, 0, null, null, 2 ]

// Explanation :

// In 1st operation we initialize the heap to empty heap.

// In 2nd, 3rd operation we insert 4, 1 to the heap respectively. The heap after 4th operation will be -> [4, 1].

// In 4th operation we remove the maximum element from heap. So the ne heap becomes -> [1].

// In 5th operation we output the maximum element of the heap i.e. 1.

// In 6th operation we operation we insert 4 to the heap. The heap after 6th operation will be -> [4, 1].

// In 7th operation we output the size of the current heap i.e. 2.

// In 8th operation we output whether the heap is empty or not i.e. false (0).

// In 9th operation we remove the maximum element from heap. So the ne heap becomes -> [1].

// In 10th operation we change the 0th index element to 2. So new heap becomes -> [2].

// In 11th operation we output the maximum element of the heap i.e. 2.

// Constraints

// 1 <= n <= 105
// -105 <= nums[i] <= class Solution {\

#include <bits/stdc++.h>
using namespace std;

vector<int> heap;

void heapifyUp(int idx)
{

  while (idx > 0)
  {

    int parent = (idx - 1) / 2;

    if (heap[parent] < heap[idx])
    {
      swap(heap[parent], heap[idx]);
      idx = parent;
    }
    else
    {
      break;
    }
  }
}

void heapifyDown(int idx)
{

  int n = heap.size();

  while (true)
  {

    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    int largest = idx;

    // LEFT child gets preference when equal
    if (left < n && heap[left] > heap[largest])
      largest = left;

    if (right < n && heap[right] > heap[largest])
      largest = right;

    if (largest == idx)
      break;

    swap(heap[idx], heap[largest]);
    idx = largest;
  }
}

public:
void initializeHeap()
{
  heap.clear();
}

void insert(int key)
{

  heap.push_back(key);

  heapifyUp(heap.size() - 1);
}

void changeKey(int index, int new_val)
{

  int oldVal = heap[index];

  heap[index] = new_val;

  if (new_val > oldVal)
    heapifyUp(index);
  else
    heapifyDown(index);
}

void extractMax()
{

  if (heap.empty())
    return;

  swap(heap[0], heap.back());

  heap.pop_back();

  if (!heap.empty())
    heapifyDown(0);
}

bool isEmpty()
{

  return heap.empty();
}

int getMax()
{

  return heap[0];
}

int heapSize()
{

  return heap.size();
}
}
;