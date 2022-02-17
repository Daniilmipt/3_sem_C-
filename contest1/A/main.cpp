#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

int main()
{
    int n;
    long long s;
    std::set <std::vector<int>> st;
    std::vector <int> vec;
    std::cin >> n;
    int *a = new int [n];
    for (int i = 0; i < n; ++i){
        std::cin >> a[i];
    }
    std::sort(a, a + n);
    std::cin >> s;
    for (int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            for (int k = j + 1; k < n; ++k){
                for(int m = k + 1; m < n; ++m){
                    if (a[i] + a[j] + a[k] + a[m] == s){
                        vec = {a[i],a[j],a[k],a[m]};
                        st.insert(vec);
                    }
                }
            }
        }
    }
    for(auto i : st){
            for (auto j : i){
                std::cout << j << " ";
            }
        std::cout << std::endl;
    }


    return 0;
}
