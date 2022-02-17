#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

int main()
{
    int n,m,k,k0,k1;
    std::string a,b,c,l;
    std::string s,s0,s1,max,min;
    std::map <std::string, int> mp;
    std::cin >> n;
    int p;

    for(int i = 0; i < n; ++i){
        std::cin >> s >> k;

        a = s.substr(0,s.find("."));
        s.erase(0,s.find(".")+1);
        b = s.substr(0,s.find("."));
        c = s.substr(s.find(".")+1, s.length()-1);
        s = c+b+a;

        if(mp.find(s) != mp.end()){
            mp.find(s)->second = std::max(mp.find(s)->second,k);
        }else{
            mp.insert(std::make_pair(s,k));
        }

    }

    max = "0";
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if (it->first > max){
            k1 = it->second;
            s1 = it->first;
            max = k1;
        }
    }

    min = "90000000";
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if (it->first < min){
            k0 = it->second;
            s0 = it->first;
            min = k0;
        }
    }

    std::cin >> m;
    std::vector<int> vec;

    p=0;
    for(int i = 0; i < m; ++i){
        std::cin >> s;
        a = s.substr(0,s.find("."));
        s.erase(0,s.find(".")+1);
        b = s.substr(0,s.find("."));
        c = s.substr(s.find(".")+1, s.length()-1);
        s = c+b+a;

        for(auto it=mp.begin(); it!=mp.end(); ++it){
            if (s>=it->first){
                p = std::max(p,it->second);
            }
        }
        vec.push_back(p);
        p=0;
    }

    for(auto i : vec)
    {
       std::cout<<i<<std::endl;
    }

}
