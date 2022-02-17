#include <iostream>
#include <ctime>
#include <time.h>

template <unsigned n>
unsigned value () {
        return value<n-1>() + value<n-2>();
}

template <>
unsigned value <1>() {
	return 0;
}

template <>
unsigned value <2>() {
	return 1;
}

int main()
{
    long long n;
    clock_t t2,t1;
    t1 = clock();
    unsigned int start_time = clock();

    std::cin >> n;
    t2 = clock();
    long long a = value<30>();
    t2 = clock() - t2;
    std::cout << a << std::endl;
    std::cout << "compile_time = " << ((double)t2)/CLOCKS_PER_SEC << std::endl;
    t1 = clock() - t1;
    std::cout << "all_time = " << ((double)t1)/CLOCKS_PER_SEC;
    return 0;
}
