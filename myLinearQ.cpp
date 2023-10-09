#include <iostream>
#include <string>

struct item
{
    int val = 0;
    item *next = nullptr;
    item(int v = 0)
    {
        val = v;
    }
};

class LLQueue
{
private:
    item *tail;
    item *head;

public:
    ~LLQueue()
    {
        // loop through queue and delete
        item *tmp;
        while (head != NULL)
        {
            tmp = head;
            head = head->next;
            free(tmp);
        }
    }
    void enqueue(int value)
    {
        item *newValue = new item(value);
        if (empty())
        {
            head = newValue;
            tail = head;
        }
        else
        {
            this->tail->next = newValue;
            tail = tail->next;
        }
        std::cout << "added " << tail->val << std::endl;
    }
    int dequeue()
    {
        if (empty())
        {
            throw std::string("EMPTY");
        }

        item *oldHead = head;
        head = head->next;
        int value = oldHead->val;
        delete oldHead;
        return value;
    }
    bool empty()
    {
        if (head == NULL)
        {
            std::cout << "Queue is empty!" << std::endl;
            return true;
        }

        return false;
    }

    void print()
    {
        std::cout << "queue: [ ";
        item *curr = head;
        while (curr != nullptr)
        {

            std::cout << curr->val << " ";
            curr = curr->next;
        }
        std::cout << "]" << std::endl;
    }
};

main()
{

    LLQueue linear_q = LLQueue();
    try
    {
        linear_q.enqueue(2);
        linear_q.enqueue(3);
        linear_q.enqueue(4);

        linear_q.print();
        std::cout << "removed: " << linear_q.dequeue() << std::endl;
        std::cout << "removed: " << linear_q.dequeue() << std::endl;
        std::cout << "removed: " << linear_q.dequeue() << std::endl;

        linear_q.print();
        std::cout << "removed: " << linear_q.dequeue() << std::endl;

        linear_q.print();
    }
    catch (...)
    {
        std::cout << "Caught error" << std::endl;
    }

}