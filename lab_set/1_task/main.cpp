#include <iostream>
#include <fstream>
#include <set>


int main()
{
    std::ifstream file;
    file.open("task1_input_0.txt");
    std::ofstream outfile;
    outfile.open("task1_output_1.txt");

    std::string line;
    std::set<std::string> st;
    while (std::getline(file,line)){
        //std::cout << line << std::endl;
        st.insert(line);
    }
    std::cout<<st.size();

    return 0;
}
