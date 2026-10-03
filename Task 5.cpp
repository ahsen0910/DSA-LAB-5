#include <iostream>
using namespace std;

class Stack {
    int Arr[100];
    int Top;

public:
    Stack() {
        Top = -1;
    }

    bool IsEmpty() {
        return Top == -1;
    }

    void Push(int Value) {
        Arr[++Top] = Value;
    }

    int Pop() {
        return Arr[Top--];
    }
};

class MyQueue {
    Stack Incoming;
    Stack Outgoing;

public:
    void Enqueue(int Value) {
        Incoming.Push(Value);
    }

    int Dequeue() {
        if (Outgoing.IsEmpty()) {
            while (!Incoming.IsEmpty()) {
                Outgoing.Push(Incoming.Pop());
            }
        }

        return Outgoing.Pop();
    }
};

int main() {
    MyQueue Q;

    Q.Enqueue(1);
    Q.Enqueue(2);

    cout << Q.Dequeue() << endl;

    Q.Enqueue(3);

    cout << Q.Dequeue() << endl;
    cout << Q.Dequeue() << endl;

    return 0;
}
