#include <iostream>
using namespace std;

class Stack {
    int Arr[7];
    int Top;

public:
    Stack() {
        Top = -1;
    }

    void Push(int Value) {
        Arr[++Top] = Value;
    }

    int Pop() {
        return Arr[Top--];
    }
};

class CircularQueue {
    int Arr[7];
    int Front;
    int Rear;
    int Count;

public:
    CircularQueue() {
        Front = 0;
        Rear = -1;
        Count = 0;
    }

    void Enqueue(int Value) {
        Rear = (Rear + 1) % 7;
        Arr[Rear] = Value;
        Count++;
    }

    int Dequeue() {
        int Value = Arr[Front];
        Front = (Front + 1) % 7;
        Count--;
        return Value;
    }

    void Display() {
        for (int i = 0; i < Count; i++)
            cout << Arr[(Front + i) % 7] << " ";

        cout << endl;
    }
};

void reverseFirstK(CircularQueue &q, int K) {
    Stack s;

    for (int i = 0; i < K; i++) {
        int Value = q.Dequeue();
        s.Push(Value);
    }

    for (int i = 0; i < K; i++) {
        int Value = s.Pop();
        q.Enqueue(Value);
    }
}

int main() {
    CircularQueue q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);

    reverseFirstK(q, 3);

    q.Display();

    return 0;
}
