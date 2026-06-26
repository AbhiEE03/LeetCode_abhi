// ////QUESTION//// //
/*
Implement Queue using Arrays

Implement a First-In-First-Out (FIFO) queue using an array.
The implemented queue should support the following operations: push, peek, pop, and isEmpty.


Implement the ArrayQueue class:

void push(int x): Adds element x to the end of the queue.

int pop(): Removes and returns the front element of the queue.

int peek(): Returns the front element of the queue without removing it.

boolean isEmpty(): Returns true if the queue is empty, false otherwise.


Example 1

Input:

["ArrayQueue", "push", "push", "peek", "pop", "isEmpty"]

[[], [5], [10], [], [], []]

Output: [null, null, null, 5, 5, false]

Explanation:

ArrayQueue queue = new ArrayQueue();

queue.push(5);

queue.push(10);

queue.peek(); // returns 5

queue.pop(); // returns 5

queue.isEmpty(); // returns false

Example 2

Input:

["ArrayQueue", "isEmpty"]

[[]]

Output:[null, true]

Explanation:

ArrayQueue queue = new ArrayQueue();

queue.isEmpty(); // returns true

Now your turn!

Input:

["ArrayQueue", "push", "pop", "isEmpty"]

[[], [1], [], []]

Output:

Constraints

1 <= numbers of calls made <= 100
1 <= x <= 100
*/

#include <bits/stdc++.h>
using namespace std;

class ArrayQueue
{
public:
  vector<int> arr;
  int frontIdx;

  ArrayQueue()
  {
    frontIdx = 0;
  }

  void push(int x)
  {
    arr.push_back(x);
  }

  int pop()
  {
    return arr[frontIdx++];
  }

  int peek()
  {
    return arr[frontIdx];
  }

  bool isEmpty()
  {
    return frontIdx >= arr.size();
  }
};