#include <iostream>

class Map {
public:
        void put(int key, int value);
        void add(int key, int increment);
        int get(int key);
};

class StaticMap
{
public:
StaticMap();
~StaticMap();

void put(int key, int value) {
        if (this->size == this->capacity){
        int* new_keys = new int [this->capacity * 2];
        int* old_keys;
        this->capacity = this->capacity * 2;
        for (int i = 0; i < this->size; i++){
            new_keys[i] = this->keys[i];
        }
        old_keys = this->keys;
        this->keys = new_keys;
        delete[] old_keys;

        int* new_values = new int [this->capacity * 2];
        int* old_values;
        for (int i = 0; i < this->size; i++){
            new_values[i] = this->values[i];
        }
        old_values = this->values;
        this->values = new_values;
        delete[] old_values;
    }
    if (this->size == 0) {
        this->keys[0] = key;
        this->values[0] = value;
        this->size++;
    } else {
        for (int i = 0; i < this->size; ++i) {
            if (this->keys[i] == key) {
                this->values[i] = value;
                break;
            }
            if (this->keys[i] > key) {
                for (int j = this->size - 1; j >= i; j--) {
                    this->keys[j + 1] = this->keys[j];
                    this->values[j + 1] = this->values[j];
                }
                this->keys[i] = key;
                this->values[i] = value;
                this->size++;
                break;
            }
            if (i == this->size - 1 and this->keys[i] < key) {
                this->keys[this->size] = key;
                this->values[this->size] = value;
                this->size++;
            }
        }
    }
}

void add(int key, int increment) {
    if (this->size == 0) {
        throw std::runtime_error("key not found");
    } else {
        for (int i = 0; i < this->size; ++i) {
            if (this->keys[i] == key) {
                this->values[i] += increment;
                break;
            } else {
                if (i == this->size - 1) {
                    throw std::runtime_error("key not found");
                }
            }
        }
    }
}

int get(int key) {
    int low = 0;
    int high = this->size - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key < this->keys[mid]) {
            high = mid - 1;
        }
        if (key > this->keys[mid]) {
            low = mid + 1;
        }
        if (key==this->keys[mid]){
            return values[mid];
        }
    }
    throw std::runtime_error("key not found");
}
private:
int* keys;
int size;
int capacity ;
int* values;
};

StaticMap::StaticMap() {
this->keys = new int[2];
this->values = new int[2];
this->size = 0;
this->capacity = 2;
}

StaticMap::~StaticMap() {
delete [] this->keys;
delete [] this->values;
}

int main()
{
    StaticMap dict;
    dict.put(11,12);
    dict.add(11,2);
    int k = dict.get(11);
    std::cout<<k;
    return 0;
}
