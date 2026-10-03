#include <iostream>
using namespace std;

class CircularQueue {
    int Arr[6];
    int Front;
    int Rear;
    int Count;

public:
    CircularQueue() {
        Front = 0;
        Rear = -1;
        Count = 0;
    }

    bool IsFull() {
        return Count == 6;
    }

    bool IsEmpty() {
        return Count == 0;
    }

    void Enqueue(int ID) {
        if (IsFull())
            return;

        Rear = (Rear + 1) % 6;
        Arr[Rear] = ID;
        Count++;
    }

    int Dequeue() {
        if (IsEmpty())
            return -1;

        int ID = Arr[Front];
        Front = (Front + 1) % 6;
        Count--;

        return ID;
    }

    void Display() {
        for (int i = 0; i < Count; i++)
            cout << Arr[(Front + i) % 6] << " ";

        cout << endl;
    }

    int GetFront() {
        return Front;
    }

    int GetRear() {
        return Rear;
    }
};

int main() {
    CircularQueue Q;

    Q.Enqueue(101);
    Q.Enqueue(102);
    Q.Enqueue(103);
    Q.Enqueue(104);
    Q.Enqueue(105);
    Q.Enqueue(106);

    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();

    Q.Enqueue(107);
    Q.Enqueue(108);
    Q.Enqueue(109);

    Q.Dequeue();
    Q.Dequeue();

    Q.Enqueue(110);

    Q.Dequeue();

    Q.Enqueue(111);
    Q.Enqueue(112);

    cout << "Final boarding queue: ";
    Q.Display();

    cout << "Front: " << Q.GetFront() << endl;
    cout << "Rear: " << Q.GetRear() << endl;

    return 0;
}
