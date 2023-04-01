#include <iostream>
#include <vector>
using namespace std;

//Problem #1: Sparse 1D Array

struct Node 
{
    int data{};
    int index{};
    Node* next{};
    Node* prev{};

    Node(int data, int index) : data(data), index(index) {};
};

struct Array_LinkedList 
{
private:
    int size{};
    int length{};
    Node* head{};
    Node* tail{};

public:
    Array_LinkedList(int size) : size(size) {};

    void link(Node* first, Node* second) {
        if (first)
            first->next = second;
        if (second)
            second->prev = first;
    }

    void set_value(int value, int idx) {
        Node* item = new Node(value, idx);

        if (length == 0) {
            head = tail = item;
        }
        else if (length == 1 || (item->index < head->index))
        {
            if (item->index < head->index) {
                link(item, head);
                head = item;
            }
            else {
                link(tail, item);
                tail = item;
            }
        }
        else {
            Node* cur = head;

            while (cur->next) {
                if (item->index > cur->next->index)
                    cur = cur->next;
                else
                    break;
            }

            Node* after = cur->next;
            link(cur, item);
            link(item, after);
        }

        ++length;
    }

    void print() {
        Node* cur = head;
        for (int i = 0; i < size; i++)
        {
            if (cur && i == cur->index)
            {
                cout << cur->data << " ";
                cur = cur->next;
            }
            else
                cout << "0 ";
        }
        cout << "\n";
    }

    void print_nonzero() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    int get_value(int idx) {
        for (Node* cur = head; cur; cur = cur->next)
            if (cur->index == idx)
                return cur->data;
        return -1;
    }

    void add(Array_LinkedList& other) {
        vector<int> sum(size, 0); // Prefix sum

        Node* cur = other.head;
        for (int i = 0; i < size; i++)
        {
            if (cur && i == cur->index) {
                sum[i] = cur->data;
                cur = cur->next;
            }
        }

        cur = head;
        for (int i = 0; i < size; i++) {
            if (sum[i] && cur && i == cur->index) {
                cur->data += sum[i];
                cur = cur->next;
            }
            else if (sum[i]) {
                set_value(sum[i], i);
            }
        }
    }
};


///////////////////////////////////////////////////////////////////////////////////////


//Problem #2: Sparse Matrix (2D Array)
struct NODE
{
    int data{};
    int x_index{}, y_index{};
    NODE* next{};
    NODE* prev{};

    NODE(int data, int x_index, int y_index) : data(data), x_index(x_index), y_index(y_index) {};
};

struct Array_LinkedList2
{
private:
    int size{};
    int length{};
    NODE* head{};
    NODE* tail{};

public:
    Array_LinkedList2(int size) : size(size) {};

    void link(NODE* first, NODE* second) {
        if (first)
            first->next = second;
        if (second)
            second->prev = first;
    }

    void set_value(int value, int x_index, int y_index) {
        NODE* item = new NODE(value, x_index, y_index);

        if (length == 0) {
            head = tail = item;
        }
        else if (length == 1 || (item->y_index < head->y_index))
        {
            if (item->y_index == head->y_index) {
                head->data = item->data;
                delete item;
            }
            else if (item->y_index == tail->y_index) {
                tail->data = item->data;
                delete item;
            }
            else if (item->y_index < head->y_index) {
                link(item, head);
                head = item;
            }
            else {
                link(tail, item);
                tail = item;
            }
        }
        else {
            NODE* cur = head;

            while (cur->next) {
                if (item->y_index == cur->y_index)
                {
                    cur->data = item->data;
                    delete item;
                    return;
                }
                else if (item->y_index > cur->next->y_index)
                    cur = cur->next;
                else
                    break;
            }

            NODE* after = cur->next;
            link(cur, item);
            link(item, after);
        }

        ++length;
    }

    void print() {
        NODE* cur = head;
        for (int i = 0; i < size; i++)
        {
            if (cur && i == cur->y_index)
            {
                cout << cur->data << " ";
                cur = cur->next;
            }
            else
                cout << "0 ";
        }
        cout << "\n";
    }

    void print_nonzero() {
        for (NODE* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    vector<int> prefix_sum() {
        vector<int> sum(size, 0); // Prefix sum

        NODE* cur = head;
        for (int i = 0; i < size; i++)
        {
            if (cur && i == cur->y_index) {
                sum[i] = cur->data;
                cur = cur->next;
            }
        }
        return sum;
    }

    void add(vector<int>& sum, int x_index) {
        NODE* cur = head;
        for (int i = 0; i < size; i++) {
             if (sum[i] && cur && i == cur->y_index) {
                cur->data += sum[i];
                cur = cur->next;
            }
            else if (sum[i]) {
                set_value(sum[i], x_index ,i);
            }
        }
    }

};

struct Parent_LinkedList
{
    int x_index{};
    Parent_LinkedList(int x_index) : x_index(x_index) {};
    Parent_LinkedList* next{};

    Array_LinkedList2* arr{};
    void set_value(int size, int value, int x_index, int y_index) {
        if (!arr) {
            arr = new Array_LinkedList2(size);
            arr->set_value(value, x_index, y_index);
        }
        else {
            arr->set_value(value, x_index, y_index);
        }
    }

    void print_matrix() {
        arr->print();
    }

    void print_matrix_nonzero() {
        arr->print_nonzero();
    }
    
    vector<int> prefix_sum() {
        return arr->prefix_sum();
    }

    void add(vector<int>& sum, Parent_LinkedList* other) {
        arr->add(sum, other->x_index);
    }
};

struct SparseMatrix
{
private:
    int rows_size{}, cols_size{}; //Like 2D-array
    int length{};
    Parent_LinkedList* head{};
    Parent_LinkedList* tail{};

public:
    SparseMatrix(int x_size, int y_size) : rows_size(x_size), cols_size(y_size) {};

    Parent_LinkedList* list = head;
    void set_value(int value, int x_index, int y_index)
    {
        if (x_index >= rows_size || y_index >= cols_size)
            return;

        bool found = false;
        while (list) {
            if (list->x_index == x_index) {
                found = true;
                break;
            }
            list = list->next;
        }

        if (found)
            list->set_value(cols_size, value, x_index, y_index);
        else 
        {
            list = new Parent_LinkedList(x_index);
            list->set_value(cols_size, value, x_index, y_index);

            if (length == 0) {
                head = tail = list;
            }
            else if (length == 1 || (x_index < head->x_index))
            {
                if (x_index < head->x_index) {
                    list->next = head;
                    head = list;
                }
                else {
                    head->next = list;
                    tail = list;
                }
            }
            else {
                Parent_LinkedList* cur = head;

                while (cur->next) {
                    if (x_index > cur->next->x_index)
                        cur = cur->next;
                    else
                        break;
                }

                Parent_LinkedList* after = cur->next;
                cur->next = list;
                list->next = after;
            }

            ++length;
        }
    }

    void print_matrix() {
        cout << "Print matrix: " << rows_size << " x " << cols_size << "\n";

        Parent_LinkedList* cur = head;
        for (int i = 0; i < rows_size; i++)
        {
            if (cur && cur->x_index == i)
            {
                cur->print_matrix();
                cur = cur->next;
            }
            else {
                for (int i = 0; i < cols_size; i++)
                    cout << "0 ";
                cout << "\n";
            }
        }
    }

    void print_matrix_nonzero() {
        cout << "Print matrix: " << rows_size << " x " << cols_size << "\n";

        Parent_LinkedList* cur = head;
        while (cur) {
            cur->print_matrix_nonzero();
            cur = cur->next;
        }
    }

    void add(SparseMatrix& other) 
    {
        vector<int> vec(cols_size, 0);

        Parent_LinkedList* other_cur = other.head;
        Parent_LinkedList* cur = head;
        while (other_cur) {
            vec = other_cur->prefix_sum();
            while (cur)
            {
                cur->add(vec, other_cur);
                cur = cur->next;
            }
            other_cur = other_cur->next;
        }       
    }
};

void test1() 
{
    Array_LinkedList arr(10);
    arr.set_value(50, 5);
    arr.set_value(60, 6);
    arr.set_value(20, 2);
    arr.set_value(70, 7);
    arr.set_value(40, 4);

    arr.print();
    arr.print_nonzero();
    cout << arr.get_value(7) << "\n\n";

    Array_LinkedList arr2(10);
    arr2.set_value(3, 3);
    arr2.set_value(5, 0);
    arr2.set_value(6, 2);

    arr2.print();
    arr2.print_nonzero();
    cout << "\n";

    arr.add(arr2);
    arr.print();
    arr.print_nonzero();
}

void test2() 
{
    SparseMatrix mat(10, 10);
    mat.set_value(5, 3, 5);
    mat.set_value(7, 3, 7);
    mat.set_value(0, 3, 2);
    mat.set_value(2, 3, 2);
    mat.set_value(6, 5, 6);
    mat.set_value(4, 5, 4);
    mat.set_value(3, 7, 3);
    mat.set_value(1, 7, 1);
    mat.set_value(1, 70, 1);

    mat.print_matrix();
    mat.print_matrix_nonzero();

    SparseMatrix mat2(10, 10);
    //mat2.set_value(5, 1, 9);
    //mat2.set_value(6, 3, 8);
    mat2.set_value(9, 9, 9);

    mat.add(mat2);
    mat.print_matrix_nonzero();
}

int main()
{
    //test1();
    
    test2();
}
