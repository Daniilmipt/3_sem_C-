#include <iostream>

template <typename T>
class Grid {
private:
 T *memory;
 size_t x_size, y_size;

public:
 Grid(size_t x_size, size_t y_size): x_size(x_size), y_size(y_size) {
    memory = new T[x_size * y_size];
    for (int i = 0; i < x_size * y_size; ++i){
        *(memory + i) = 0;
    }
 }


 ~Grid()
	{
		delete[] this->memory;
	}

 T operator()(size_t x_idx, size_t y_idx) const{
    return *(memory + y_idx - 1 + (x_idx - 1)*x_size);
 }

 T& operator()(size_t x_idx, size_t y_idx){
    T &t = this->memory[y_idx - 1 + (x_idx - 1)*x_size];
    return t;
 }

 size_t get_xsize() const{
    return this->x_size;
 }
 size_t get_ysize() const{
    return this->y_size;
 }

 Grid& operator=(T a){
    for (int i = 0; i < x_size * y_size; ++i){
        *(memory + i) = a;
    }
    return *this;
 }

 Grid(Grid const &g){
    this->x_size = g.x_size;
    this->y_size = g.y_size;
    T* new_memory = new T[x_size * y_size];
    for (int i = 0; i < x_size * y_size; ++i){
        new_memory[i] = g.memory[i];
    }
    this->memory = new_memory;
 }

 friend std::ostream& operator<<(std::ostream &out, Grid const &g){
     int j = 1;
     std::cout << "PRINT INFO ABOUT GRID (" << g.x_size << ", " << g.y_size << ")" << std::endl;
     for (int i = 0; i < g.x_size * g.y_size; ++i){
         out << g.memory[i] << ' ';
         if (j % g.x_size == 0){
            out << std::endl;
         }
         ++j;
    }
    return out;
 }

 friend std::istream& operator>>(std::istream &in, Grid &g){
    for (int i = 0; i < g.x_size * g.y_size; ++i){
         in >> g.memory[i];
    }
    return in;
 }
};


int main()
{
    Grid<float> g(2,2);
    std::cin >> g;
    g = 4.1;
    Grid<float> g2 = g;
    g2(2,2) = 3.0;
    std::cout << g2;
    return 0;
}
