#include <iostream>
#include <map>
#include <algorithm>

int main()
{
    int n;
    int max = 0;
    std::string a,b;
    std::cin >> n;
    std::map <std::string, int> mp;

    for(int i = 0; i < n; ++i){
        std::cin>>a;
        std::transform(a.begin(), a.end(), a.begin(), tolower);
        if(mp.find(a) != mp.end()){
            ++mp.find(a)->second;
        }else{
            mp[a] = 1;
        }
    }

    for(auto it=mp.begin(); it!=mp.end(); it++){
        if (it->second > max){
            max = it->second;
            b = it->first;
        }
    }
    std::cout<<b<<" "<<max;
    return 0;
}
