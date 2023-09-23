#include <iostream>

using namespace std;

class myIntVector
{
private:
    int *arr;
    int sz;
    int cap = 4;
    void resize(int new_cap)
    {
        int *tmp = new int[new_cap];
        // copy arrar
        for (int i = 0; i < this->sz; i++)
        {
            tmp[i] = this->arr[i];
        }
        // delete old array
        delete[] this->arr;
        this->arr = tmp;
        cap = new_cap;
    }

public:
    myIntVector(int length)
    {
        this->arr = new int[cap];
        this->sz = length;
        if (sz >= cap)
        {
            resize(cap * 2);
        }
        else if (sz <= cap / 4)
        {
            resize(cap / 2);
        }

        // init with 0s
        for (int i = 0; i < length; i++)
        {
            this->arr[i] = 0;
        }
    }
    ~myIntVector()
    {
        delete[] this->arr;
    }

    int size()
    {
        return this->sz;
    }
    int capacity()
    {
        return this->cap;
    }
    bool is_empty()
    {
        if (this->sz > 0)
        {
            return false;
        }
        else
            return true;
    }

    int at(int idx)
    {
        return *(this->arr + idx);
    }

    void push(int val)
    {
        if (++sz >= cap)
        {
            resize(cap * 2);
        }

        arr[sz - 1] = val;
    }

    void insert(int idx, int val)
    {
        // increase by 1
        if (++sz >= cap)
        {
            resize(cap * 2);
        }
        // shift from end
        for (int i = sz - 1; i > idx; i--)
        {
            arr[i] = arr[i - 1];
        }
        // add value at index
        arr[idx] = val;
    }
    void prepend(int val)
    {
        insert(0, val);
    }

    int pop()
    {
        // get value at end
        this->sz--;
        int end = *(this->arr + sz);

        if (sz <= cap / 4)
        {
            resize(cap / 2);
        }

        return end;
    }

    void del(int idx)
    {

        // reduce by 1
        if (--sz <= cap / 4)
        {
            resize(cap / 2);
        }
        // shift from idx                                                                                                                
        for (int i = idx; i < sz; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
    int find(int val)
    {
        // loop through array
        for (int i = 0; i < sz; i++)
        {
            if (arr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    void remove(int val)
    {
        // loop through array
        for (int i = 0; i < sz; i++)
        {
            if (arr[i] == val)
            {
                // del
                del(i);
            }
        }
    }

    void print()
    {
        cout << "Vector of size: " << size() << " | cap: " << capacity() << endl;
        cout << "[ ";
        for (int i = 0; i < size(); i++)
        {
            cout << at(i) << " ";
        }
        cout << "]" << endl;
    }
};

main()
{

    myIntVector v = myIntVector(1);
    v.push(3);
    v.print();

    cout << v.pop() << endl;
    v.print();

    v.push(1);
    v.push(3);
    v.print();

    v.insert(1, 8);
    v.prepend(12);
    v.print();

    v.del(2);
    v.print();
    v.push(0);
    v.print();
    v.remove(0);
    v.print();
    cout << v.find(4) << " " << v.find(3) << endl;
}