#include <iostream>
#include <fstream>
#include <set>
#include <vector>

struct Doc{
    std::string n;
    std::string k;
};

int main()
{
    std::ifstream file;
    file.open("task2_input_0.txt");
    std::ofstream outfile;
    outfile.open("task2_output_1.txt");

    std::string line;
    std::string a;
    std::string b;
    std::set<Doc> st;
    std::vector<std::string> vec;
    while (std::getline(file,line)){
        //std::cout << line << std::endl;
        a = line.substr(0,line.find(","));
        b = line.substr(line.find(","), line.length()-1);
        Doc d;
        d.n = a;
        d.k = b;
        //vec = {d.n, r.k};
        st.emplace(a, b);
    }
    std::cout<<st.size();
    return 0;
}
