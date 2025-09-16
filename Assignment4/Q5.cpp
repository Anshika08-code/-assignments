#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int capacity;
    int frontIndex, rearIndex, count;

public:
    Queue(int size = 1000) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void push(int x) {
        if (count == capacity) {
            cout << "Queue overflow\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = x;
        count++;
    }

    void pop() {
        if (empty()) return;
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    int front() {
        if (empty()) throw runtime_error("Queue is empty");
        return arr[frontIndex];
    }

    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }
};

// Stack using two queues
class StackTwoQueues {
    Queue q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // swap q1 and q2 by swapping their internals
        swapQueues();
    }

    void pop() {
        if (!q1.empty()) q1.pop();
    }

    int top() {
        if (!q1.empty()) return q1.front();
        throw runtime_error("Stack is empty");
    }

    bool empty() {
        return q1.empty();
    }

private:
    void swapQueues() {
        // swap internals of q1 and q2
        std::swap(q1, q2);
    }
};

// Stack using one queue
class StackOneQueue {
    Queue q;
public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        // rotate queue to move new element to front
        for (int i = 0; i < sz - 1; ++i) {
