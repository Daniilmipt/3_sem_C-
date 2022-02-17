#include <iostream>

class Stack
{
public:
    Stack();   /* constructor */
    ~Stack();  /* destructor */

    void push(int elem);  /* method */
private:
    int* content; /* fields */
    int size;
    int capacity;
};

Stack::Stack()
{
    this->content = new int[32];
    this->size = 0;
    this->capacity = 32;
}

Stack::~Stack()
{
    delete []this->content;
}

void Stack::push(int elem)
{
    /* your code here */
    if (this->size == this->capacity)
    {
        int* content_new = new int[this->capacity * 2];
        for (int i = 0; i < size; ++i)
        {
            content_new[i] = this->content[i];
        }
        content_new[this->size]=elem;
        delete[] this->content;
        this->content = content_new;
        this->capacity = this->capacity * 2;
        this->size = this->size + 1;
    }
    else
    {
        this->content[size] = elem;
        this->size = this->size + 1;
    }
}

int main()
{
    Stack st;
    for (int i = 0; i < 1000; i++) {
        st.push(i);
    }
    return 0;
}
