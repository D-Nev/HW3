#include <iostream>
using namespace std;

template<typename T>
class MyData
{
private:
    T value;
public:
    MyData(T value)
    {
        this->value = value;
    }
    void SetData(T value)
    {
        this->value = value;
    }
    T GetData() const
    {
        return value;
    }
};

template<typename T>
class Node
{
private:
    MyData<T> myData;
    Node* next;
public:
    Node(MyData<T> myData) : myData(myData), next(nullptr) {}

    MyData<T>& GetMyData()
    {
        return myData;
    }

    void SetMyData(MyData<T> myData)
    {
        this->myData = myData;
    }

    Node* GetNext() const
    {
        return next;
    }

    void SetNext(Node* next)
    {
        this->next = next;
    }
};

template<typename T>
class Queue
{
private:
    Node<T>* first;
    Node<T>* last;
    size_t size;
public:
    Queue() : first(nullptr), last(nullptr), size(0) {}

    size_t Size() const
    {
        return size;
    }

    void Enqueue(T value) 
    {
        Node<T>* newNode = new Node<T>(MyData<T>(value));
        if (last == nullptr)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->SetNext(newNode);
            last = newNode;
        }
        size++;
    }

    MyData<T>& Front()
    {
        if (first == nullptr)
        {
            throw runtime_error("Queue is empty!");
        }
        return first->GetMyData();
    }

    const MyData<T> Front() const
    {
        if (first == nullptr)
        {
            throw runtime_error("Queue is empty!");
        }
        return first->GetMyData();
    }

    void Dequeue() 
    {
        if (first == nullptr)
        {
            return;
        }
        Node<T>* temp = first;
        first = first->GetNext();
        if (first == nullptr)
        {
            last = nullptr;
        }
        delete temp;
        size--;
    }

    ~Queue()
    {
        while (first != nullptr)
        {
            Node<T>* temp = first;
            first = first->GetNext();
            delete temp;
        }
    }
};

int main()
{
    Queue<int> queue;
    queue.Enqueue(9);
    queue.Enqueue(1);
    queue.Enqueue(5);
    queue.Enqueue(7);
    queue.Enqueue(3);

    while (queue.Size() > 0)
    {
        cout << queue.Front().GetData() << endl;
        queue.Dequeue();
    }

    return 0;
}
