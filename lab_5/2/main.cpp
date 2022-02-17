#include <iostream>
#include <map>
#include <fstream>
#include <set>
#include <cmath>

int main()
{
    std::ifstream file;
    file.open("task2_inputcalls_2.txt");
    std::ifstream file1;
    file1.open("task2_inputspam_2.txt");
    std::ofstream outfile;
    outfile.open("task2_output_2.txt");
    std::map<std::string, int> mp;
    std::set<std::string> st;
    std::string line,a,b,c;
    int c_time = 0;

    while (std::getline(file1,line)){
        st.insert(line);
    }

    while (std::getline(file,line)){
        a = line.substr(0,line.find(","));
        line.erase(0,line.find(",")+1);
        b = line.substr(0,line.find(","));
        c = line.substr(line.find(",")+1, line.length()-1);

        for(char i : c){
            c_time *= 10;
            c_time += (i-'0');
        }

        if(st.find(a) != st.end()){
                if(mp.find(b) != mp.end()){
                    mp.find(b)->second += c_time;
                }
                else mp.insert(std::make_pair(b,c_time));
        }
        c_time = 0;
    }

    if (mp.size()==0){
        std::cout << "There were no calls from spammers";
    } else{
    std::string k = mp.begin()->first;
    int max = mp.begin()->second;
    for(auto it=mp.begin(); it!=mp.end(); ++it){
        if(it->second > max){
            max = it->second;
            k = it->first;
        }
        if(it->second == max && it->first < k){
            k = it->first;
        }
    }
    outfile << k << " " << max;
    }



    return 0;
}
