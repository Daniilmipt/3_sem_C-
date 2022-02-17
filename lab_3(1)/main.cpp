#include <iostream>
#include <string>
#include <cstring>

class Weekday{
private:
    int n;
public:
    Weekday(int n){
        this->n = n;
    }

    friend std::ostream& operator << (std::ostream &out, const Weekday &w){
        out << w.n;
        return out;
    }

    friend bool operator>(const Weekday &a, const Weekday &b){
        return a.n > b.n;
    }

    int to_number() {
        return this->n;
    }
};



template <typename T >
void sort (T * l, T * r) {
/*
сортировка и вывод в одной функции
*/
int Monday = 0;
int Tuesday = 0;
int Wednesday = 0;
int Thursday = 0;
int Friday = 0;
int Saturday = 0;
int Sunday = 0;

for (auto i = 0; i < r - l; ++i){
        if ((l+i)->to_number() == 1){++Monday;}
        if ((l+i)->to_number() == 2){++Tuesday;}
        if ((l+i)->to_number() == 3){++Wednesday;}
        if ((l+i)->to_number() == 4){++Thursday;}
        if ((l+i)->to_number() == 5){++Friday;}
        if ((l+i)->to_number() == 6){++Saturday;}
        if ((l+i)->to_number() == 7){++Sunday;}
    }
    for(int i = 0 ; i < Monday; ++i){
        std::cout << "1" << std::endl;
    }
    for(int i = 0 ; i < Tuesday; ++i){
        std::cout << "2" << std::endl;
    }
    for(int i = 0 ; i < Wednesday; ++i){
        std::cout << "3" << std::endl;
    }
    for(int i = 0 ; i < Thursday; ++i){
        std::cout << "4" << std::endl;
    }
    for(int i = 0 ; i < Friday; ++i){
        std::cout << "5" << std::endl;
    }
    for(int i = 0 ; i < Saturday; ++i){
        std::cout << "6" << std::endl;
    }
    for(int i = 0 ; i < Sunday; ++i){
        std::cout << "7" << std::endl;
    }
}

template <>
void sort<int>(int * l, int * r) {
/*
только сортировка
*/
	auto sz = r - l;
	if (sz <= 1) return;
	bool b = true;
	while (b) {
		b = false;
		for (auto i = l; i + 1 < r; ++i) {
			if (*i > *(i + 1)) {
				std::swap(*i, *(i + 1));
				b = true;
			}
		}
		r--;
	}
}


int main()
{
    int n;
    Weekday a[] = {1, 2, 3, 1, 1, 1, 6};
    sort(a, a+7);
    std::cout << std::endl;

    int b[] = {100, 200, 300, 100, 150, 10};
    sort(b, b+6);

    for(int i = 0; i < 6; ++i){
        std::cout << b[i] << std::endl;
    }

    return 0;
}
