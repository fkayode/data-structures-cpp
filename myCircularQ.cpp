#include <iostream>
#include <string>

class FixedQueue
{
private:
    int *arr;
    int readIdx = 0;  // next space to read from
    int writeIdx = 0; // free space to write
    int size;

public:
    FixedQueue(int sz)
    {
        this->arr = new int[sz + 1];
        this->size = sz + 1;
    }
    ~FixedQueue()
    {
        delete[] this->arr;
    }

    void enqueue(int value)
    {
        if (full())
        {
            return;
        }
        arr[writeIdx] = value;
        writeIdx++;
        if (this->writeIdx == size)
        {
            this->writeIdx = 0;
        }
    }
    int dequeue()
    {
        if (empty())
        {
            return -1;
        }
        int value = this->arr[readIdx];
        this->readIdx++;
        if (this->readIdx == size)
        {
            this->readIdx = 0;
        }
        return value;
    }
    bool empty()
    {
        if (this->writeIdx == this->readIdx)
        {
            std::cout << "Queue is empty!" << std::endl;
            return true;
        }
        return false;
    }
    bool full()
    {

        if (((writeIdx + 1) % size) == readIdx)
        {
            std::cout << "Queue is full!" << std::endl;
            return true;
        }
        return false;
    }

    void print()
    {

        std::cout << "queue: [ ";
        int curr = readIdx;
        while (curr != writeIdx)
        {

            std::cout << arr[curr] << " ";
            curr = (curr + 1) % size;
        }
        std::cout << "]" << std::endl;
        // for(i:arr){
        //     cout
        // }
    }
};

main()
{

    FixedQueue circle_q = FixedQueue(4);

    circle_q.enqueue(1);
    circle_q.enqueue(2);
    circle_q.enqueue(3);
    circle_q.enqueue(4);

    circle_q.print();
    circle_q.enqueue(5); // queue is full -- will fail
    std::cout << "removed: " << circle_q.dequeue() << std::endl;
    std::cout << "removed: " << circle_q.dequeue() << std::endl;
    circle_q.enqueue(5);
    std::cout << "removed: " << circle_q.dequeue() << std::endl;

    circle_q.print();
    std::cout << "removed: " << circle_q.dequeue() << std::endl;
    std::cout << "removed: " << circle_q.dequeue() << std::endl;
    circle_q.print();
    circle_q.dequeue();// queue is empty -- will fail
}
