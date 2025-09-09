#include <iostream>
using namespace std;

const int MAX = 5;
int queue[MAX];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return rear == MAX - 1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full.\n";
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    cout << value << " added to queue.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << queue[front] << " removed from queue.\n";
    if (front == rear) {
        // Queue is now empty
        front = rear = -1;
    } else {
        front++;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Front element: " << queue[front] << endl;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Is Empty\n6. Is Full\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << (isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 6:
                cout << (isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
