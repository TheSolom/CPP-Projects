#include <iostream>
using namespace std;

template <typename T> class Vector
{
private:
    T* arr = nullptr;
    T size, capacity = 0;

    void expand_capacity()
    {
        T* arr2 = new T[capacity *= 2] {};

        for (int i = 0; i < size; i++)
            arr2[i] = arr[i];

        swap(arr, arr2);
        delete[] arr2;
    }

public:
    Vector(T size) : size(size)
    {
        if (size < 0)
            size = 1;

        capacity = size;
        arr = new T[capacity];
    }

    ~Vector()
    {
        delete[] arr;
    }

    int get_size()
    {
        return size;
    }

    void set(int index, int val)
    {
        if (index >= 0 && index < size)
        {
            arr[index] = val;
        }
        else
        {
            cout << "Out of the limit";
        }
    }

    int get(int index)
    {
        if (index >= 0 && index < size)
        {
            return arr[index];
        }
        else
        {
            cout << "Out of the limit";
        }
    }

    void insert(int index, int val)
    {
        if (size == capacity)
        {
            expand_capacity();
        }

        if (index >= 0 && index < size)
        {
            for (int i = size - 1; i >= index; i--)
            {
                arr[i + 1] = arr[i];
            }
        }

        arr[index] = val;
        size++;
    }

    void push_back(int value)
    {
        if (size == capacity)
        {
            expand_capacity();
        }

        arr[size++] = value;
    }

    void print()
    {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }

    int find(int value)
    {
        for (int i = 0; i < size; ++i)
            if (arr[i] == value)
                return i;
        return -1;	// -1 for NOT found
    }

    int get_front()
    {
        return arr[0];
    }

    int get_back()
    {
        return arr[size - 1];
    }

    void right_rotate()
    {
        int last = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }

    void left_rotate()
    {
        int first = arr[0];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        arr[size - 1] = first;
    }

    void right_rotate(int times)
    {
        for (int i = 0; i < times%size; i++)
        {
            right_rotate();
        }
    }

    int pop(int index)
    {
        if (index >= 0 && index < size)
        {
            int val = arr[index];
            for (int i = index + 1; i < size; i++)
            {
                arr[i - 1] = arr[i];
            }

            size--;
            return val;
        }  
    }

    int find_transposition(int value)
    {
        int index = find(value);

        if (index == 0 || index == -1)
        {
            return index;
        }

        swap(arr[index], arr[index - 1]);
        return index - 1;
    }
};


int main()
{
    int n = 5;
    Vector <int> v(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);
    v.print();
    
    cout << v.find_transposition(6) << endl;
    v.print();
}