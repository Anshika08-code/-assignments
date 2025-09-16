#include <iostream>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    int freq[256] = {0};

    // Array to simulate a queue of characters
    char q[1000];  
    int front = 0, rear = 0;

    for (int i = 0; i < (int)input.size(); ++i) {
       
        if (input[i] == ' ') continue;

        char c = input[i];
        freq[(int)c]++;

        // Enqueue
        q[rear++] = c;

        // Dequeue while front character frequency > 1
        while (front < rear && freq[(int)q[front]] > 1) {
            front++;
        }

        if (front < rear) {
            cout << q[front] << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;

    return 0;
}
