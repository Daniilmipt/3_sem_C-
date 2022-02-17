#include <iostream>

class Map {
public:
        virtual void put(int key, int value);
        virtual void add(int key, int increment);
        virtual int get(int key);
};



class StaticMap : public Map {
public:
    StaticMap(); /* constructor */
    ~StaticMap(); /* destructor */

    void put(int key, int value) {
        /* Добавляю */
        if (size == capacity){
            int* key_new = new int[this->capacity * 2];
            for (int i = 0; i < size; ++i)
            {
                key_new[i] = this->keys[i];
            }
            key_new[this->size]=key;
            delete[] this->keys;
            this->keys = key_new;

            int* val_new = new int[this->capacity * 2];
            for (int i = 0; i < size; ++i)
            {
                val_new[i] = this->vals[i];
            }
            val_new[this->size]=value;
            delete[] this->vals;
            this->vals = val_new;
        }

        if (this->size == 0)
        {
            this->size++;
            this->keys[0] = key;
            this->vals[0] = value;
        }

        if (this->size != 0)
        {
            for (int i = 0; i < this->size; ++i)
            {
                if (this->keys[i] == key)
                {
                    this->vals[i] = value;
                    break;
                }
                if (this->keys[i] > key and i < this->size - 1)
                {
                    for (int j = this->size - 1; j >= i; j--)
                    {
                        this->vals[j + 1] = this->vals[j];
                        this->keys[j + 1] = this->keys[j];
                    }
                    this->keys[i] = key;
                    this->vals[i] = value;
                    this->size++;
                    break;
                }
                if (i == this->size - 1 and this->keys[i] < key)
                {
                    this->vals[this->size] = value;
                    this->keys[this->size] = key;
                    this->size++;

                }
            }
        }
    }

    void add(int key, int increment)
    {
        if (this->size == 0)
        {
            throw std::runtime_error("dict is empty");
        } else
          {
            for (int i = 0; i < this->size; ++i)
            {
                if (this->keys[i] == key)
                {
                    this->vals[i] += increment;
                    break;
                } else
                  {
                    if (i == this->size - 1)
                    {
                    throw std::runtime_error("key isn't found");
                    }
                  }
            }
          }
    }


    int get(int key)
    {
        int low = 0;
        int high = this->size - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (key < this->keys[mid])
            {
                high = mid - 1;
            }
            if (key > this->keys[mid])
            {
                low = mid + 1;
            }
            if (key==this->keys[mid])
            {
                return vals[mid];
            }
        }
    }

private:
    int* keys;
    int* vals;
    int size;
    int capacity;
};
StaticMap::StaticMap() {
    this->capacity = 2;
    this->size = 0;
    this->keys = new int[2];
    this->vals = new int[2];
}
StaticMap::~StaticMap() {
    delete[] this->keys;
    delete[] this->vals;
}

int main()
{
    StaticMap dict;
    Map* pDict = &dict;
    pDict->put(11,12);
    pDict->add(11,2);
    int k = pDict->get(11);
    std::cout<<k;
    return 0;
}
