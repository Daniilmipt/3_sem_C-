#include <iostream>
#include <map>
#include <fstream>

int main()
{
    std::ifstream file;
    file.open("task1_input.txt");
    std::ofstream outfile;
    outfile.open("task1_output.txt");
    std::map<std::string, int> mp;
    std::string line;

    while (std::getline(file,line)){
        if(mp.find(line) != mp.end()){
               ++mp.find(line)->second;
        }
        else mp.insert(std::make_pair(line, 1));
    }

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
    file.close();
    outfile.close();
    return 0;
}
