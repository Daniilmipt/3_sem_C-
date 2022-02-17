#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    int time_step, id, n, r1;
    double vit_id, acat, anti_tg, neural_activity, mch, min;
    std::map <int, std::pair<double, double>> mp;
    std::vector<std::pair<double,int>> vec;
    double l1,l2;

    std::cin>>n;
    for (int i = 0; i < n; ++i){
        std::cin >>time_step>>id>>vit_id>>acat>> anti_tg>> neural_activity>> mch;

        if(mp.find(id) != mp.end()){
            l1 = (mp.find(id)->second).first;
            l2 = (mp.find(id)->second).second;
            mp.erase(mp.find(id));
            mp.emplace(id, std::make_pair(std::min(l1,neural_activity) ,std::max(l1,neural_activity)));
        }else{
            mp.insert(std::make_pair(id,std::make_pair(neural_activity, 0)));
        }
    }

    for(auto it=mp.begin(); it!=mp.end(); ++it){
            if ((it->second).second != 0){
                vec.push_back(std::make_pair(((it->second).second - (it->second).first),it->first));
            }
    }

    sort(vec.begin(), vec.end());
    int l = vec.size();
    if(l!=0){
        for(int i = 0; i < std::min(3,l); ++i){
                if (vec[i].second !=0){
                    std::cout << vec[i].second << " ";
                }
        }
        } else{
            std::cout<<-1;
            }

    return 0;
}
