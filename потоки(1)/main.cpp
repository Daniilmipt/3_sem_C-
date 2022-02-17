#include <iostream>
#include <thread>
#include <math.h>
#include <vector>
# define M_PI

void increment(double x, double y, double sh, double &t){
    t = 0;
    for (double i = x; i < y-1; i=i+sh){
        double s = (1/sqrt(2*3.1415926535897932384626433832795) * exp(-(x+1)*(x+1)/2) + 1/sqrt(2*3.1415926535897932384626433832795) * exp(-(x)*(x)/2)) /2;
        t = t+ s*2e-8;
    }
}

int main()
{
    int n;
    std::vector <std::thread> vc;
    std::vector <double> vc1;

    std::cin >> n;
    double t = 0;
    double x = -5.0;
    double y = -5.0 + ;
    double sh = 500000000 / n;
    for(int i = 0; i < n; ++i){
        //double d = i / pow(10,n);
        //double k = (i+1) / pow(10,n);
        std::thread th(increment,x,y, sh, std::ref(t));
        th.join();
        vc1.push_back(t);
        x = x + (10 / n)*i;
        y = x + (10 / n) *(i+1);
        //vc.push_back(std::move(th));
    }

    std::cout << t;
    return 0;
}
