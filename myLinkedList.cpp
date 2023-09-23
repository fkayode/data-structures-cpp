#include <iostream>

using namespace std;

struct item
{
    int val;
    item *next = nullptr;

    item(int v = 0)
    {
        val = v;
    }
};

class myLL
{
private:
    item *head;

public:
    myLL()
    {
        // init with 2 node with value of zeros
        head = new item(0);
        head->next = new item(0);
    }

    ~myLL()
    {
        item *tmp;
        while (head != NULL)
        {
            tmp = head;
            head = head->next;
            free(tmp);
        }
    }
    // or track?
    int size()
    {
        int s = 0;
        item *end = head;
        while (end != nullptr)
        {
            end = end->next;
            s++;
        }
        return s;
    }
    bool empty()
    {
        if (size() > 0)
        {
            return false;
        }
        return true;
    }

    int value_at(int idx)
    {
        item *crr = head;
        for (int i = 0; i < idx; i++)
        {
            crr = crr->next;
        }
        return crr->val;
    }
    void push_front(int val)
    {
        item *newItem = new item(val);
        newItem->next = head;
        head = newItem;
    }
    int pop_front()
    {
        item *front = head;
        head = head->next;
        int val = front->val;
        free(front);
        return val;
    }

    void push_back(int value)
    {
        // find end
        item *end = head;
        while (end->next != nullptr)
        {
            end = end->next;
        }
        // create new item
        end->next = new item(value);
    }

    int pop_back()
    {
        // find end
        item *last = head;
        item *new_end = last;
        while (last->next != nullptr)
        {
            new_end = last;
            last = last->next;
        }
        // get last
        int value = last->val;
        free(last);
        new_end->next = nullptr;
        return value;
    }

    int front()
    {
        return head->val;
    }
    int back()
    {
        // find end
        item *end = head;
        while (end->next != nullptr)
        {
            end = end->next;
        }
        return end->val;
    }

    void insert(int idx, int value)
    {
        int i = 0;
        // find index
        item *curr = head;
        while (curr != nullptr)
        {
            i++;
            if (i == idx)
            {
                item *shift_item = curr->next;
                curr->next = new item(value);
                curr->next->next = shift_item;
                return;
            }
            curr = curr->next;
        }
    }

    void erase(int index)
    {
        item *crr = head;
        item *before = crr;
        for (int i = 0; i < index; i++)
        {
            if (crr->next == nullptr)
            {
                // reached the end of the list
                return;
            }
            before = crr;
            crr = crr->next;
        }
        // before should be set to next
        before->next = crr->next;
        free(crr);
    }

    int value_n_from_end(int n)
    {
        int value;
        int length = size(); // get size of list
        value = value_at(length - 1 - n);
        return value;
    }

    void reverse()
    {
        // item* rev_head=nullptr;
        // item* curr=head;
        item *prev = nullptr;
        item *next = head->next;
        while (next != nullptr)
        {
            head->next = prev;
            prev = head;
            head = next;
            next = head->next;
        }
        // enfin
        head->next = prev;
    }

    void remove_value(int value)
    {

        item *curr = head;
        item *before = head;
        while (curr != nullptr)
        {

            if (curr->val == value)
            {
                before->next = curr->next;
                if (head == curr)
                {
                    head = curr->next;
                }
                free(curr);
                return;
            }
            before = curr;
            curr = curr->next;
        }
    }

    void print()
    {

        cout << "List of size: " << size() << endl;
        cout << "[ ";

        item *crr = head;
        while (crr != nullptr)
        {
            cout << crr->val << " ";
            crr = crr->next;
        }
        cout << "]" << endl;
    }
};

main()
{
    myLL list;
    list.print();
    list.push_front(11);

    list.push_front(12);
    list.print();

    cout << list.value_at(1) << endl;
    cout << list.pop_front() << endl;
    list.print();

    list.push_back(9);
    list.print();

    cout << list.pop_back() << endl;
    list.print();

    cout << list.back() << "  " << list.front() << "  " << list.value_n_from_end(1) << endl;
    list.insert(2, 8);
    list.print();
    list.erase(1);
    list.print();

    list.push_back(2);
    list.push_back(3);
    list.reverse();
    list.print();
    list.remove_value(0);
    list.print();
    list.remove_value(1);
    list.print();
    list.remove_value(3);
    list.print();
}