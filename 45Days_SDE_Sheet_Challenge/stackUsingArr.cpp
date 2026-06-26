// // ////QUESTION//// //
// Implement Stack using Arrays

// Implement a Last-In-First-Out (LIFO) stack using an array.
// The implemented stack should support the following operations:
// push, pop, peek, and isEmpty.

// You will be provided two arrays operations which contains
//  what operation need to perform and nums which contains the
//   values corresponding to the operations.

// Implement the ArrayStack class:

// void push(int x): Pushes element x onto the stack.

// int pop(): Removes and returns the top element of the stack.

// int top(): Returns the top element of the stack without removing it.

// boolean isEmpty(): Returns true if the stack is empty, false otherwise.

// Example 1

// Input: operations = ["ArrayStack", "push", "push", "top", "pop", "isEmpty"]

// nums = [[], [5], [10], [], [], []]

// Output: [null, null, null, 10, 10, false]

// Explanation:

// ArrayStack stack = new ArrayStack();

// stack.push(5);

// stack.push(10);

// stack.top(); // returns 10

// stack.pop(); // returns 10

// stack.isEmpty(); // returns false

// Example 2

// Input: operations = ["ArrayStack","isEmpty", "push", "pop", "isEmpty"]

// nums = [[], [], [1], [], []]

// Output: [null, true, null, 1, true]

// Explanation:

// ArrayStack stack = new ArrayStack();

// stack.push(1);

// stack.pop(); // returns 1

// stack.isEmpty(); // returns true

// Now your turn!

// Input: operations = ["ArrayStack", "isEmpty"]

// nums = [[], []]

// Output:

// Constraints

// 1 <= numbers of calls made <= 100
// 1 <= x <= 100

#include <bits/stdc++.h>
using namespace std;

class ArrayStack
{
public:
  vector<int> arr;

  ArrayStack()
  {
  }

  void push(int x)
  {
    arr.push_back(x);
  }

  int pop()
  {
    int val = arr.back();
    arr.pop_back();
    return val;
  }

  int top()
  {
    return arr.back();
  }

  bool isEmpty()
  {
    return arr.empty();
  }
};