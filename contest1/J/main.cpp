#include <iostream>
#include <map>
#include <algorithm>

int main()
{
    int n,m;
    int index,key;
    double value;
    std::string op;
    std::string s = "?+-";

    std::cin >> m >> n;
    std::map <int, double>* arr = new std::map <int, double> [m];


    for (int i=0; i<n; ++i){
        std::cin >> index >> op >> key >> value;
        std::map <int, double> mp = arr[i];

        if (s.find(op)==0){
            if(mp.find(key) != mp.end()){
                std::cout << mp.find(key)->second << std::endl;
            }
            else{
                std::cout << value << std::endl;
            }
        }

        if(s.find(op) == 1){
                if(mp.find(key) != mp.end()){
                    mp.insert(std::make_pair(key, value));
                }
                else mp[key] = value;
        }

        if(s.find(op) == 2){
            mp[key] = 0;
        }
        arr[i] = mp;
    }
    return 0;
}
