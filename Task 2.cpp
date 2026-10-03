```cpp
#include <iostream>
using namespace std;

class Stack {
    string arr[100];
    int Top;

public:
    Stack() {
        Top = -1;
    }

    bool IsEmpty() {
        return Top == -1;
    }

    void Push(string Value) {
        arr[++Top] = Value;
    }

    string Pop() {
        if (IsEmpty())
            return "";

        return arr[Top--];
    }

    void Clear() {
        Top = -1;
    }
};

class TextEditor {
    Stack UndoStack;
    Stack RedoStack;
    string Document;

public:
    void Type(string Word) {
        UndoStack.Push(Word);
        RedoStack.Clear();

        if (Document.empty())
            Document = Word;
        else
            Document += " " + Word;
    }

    void Undo() {
        if (UndoStack.IsEmpty())
            return;

        string Word = UndoStack.Pop();
        RedoStack.Push(Word);

        int Position = Document.rfind(Word);

        if (Position != string::npos) {
            if (Position > 0)
                Document.erase(Position - 1, Word.length() + 1);
            else
                Document.erase(Position, Word.length());
        }
    }

    void Redo() {
        if (RedoStack.IsEmpty())
            return;

        string Word = RedoStack.Pop();
        UndoStack.Push(Word);

        if (Document.empty())
            Document = Word;
        else
            Document += " " + Word;
    }

    void Print() {
        cout << "Document: " << Document << endl;
    }
};

int main() {
    TextEditor Editor;

    Editor.Type("Hello");
    Editor.Print();

    Editor.Type("World");
    Editor.Print();

    Editor.Undo();
    Editor.Print();

    Editor.Redo();
    Editor.Print();

    Editor.Undo();
    Editor.Print();

    Editor.Type("There");
    Editor.Print();

    Editor.Redo();
    Editor.Print();

    return 0;
}
```
