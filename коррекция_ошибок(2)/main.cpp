#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <set>

std::string check(std::string a){
    std::string base = "1234567890";
    std::optional<std::string> opt1(a);
    if(opt1){
            if ((*opt1).length()==11){
                for (char i : a){
                    if (base.find(i) > 9){
                        a = "0";
                        break;
                    }
                }
            }else a = "0";
        } else a = "0";
    return a;
}


int main()
{
    std::string base = "1234567890";
    std::ifstream file;
    file.open("task1_input.txt");
    std::ofstream outfile;
    outfile.open("task1_output.txt.txt");
    std::string line,a,b;
    int k =0;
    std::set <std::string> st;

    try{
        while (std::getline(file,line)){
            a = line.substr(0,line.find(","));
            b = line.substr(line.find(",")+1, line.length()-1);
            std::optional<std::string> opt1(a);
            std::optional<std::string> opt2(b);

            a = check(a);
            b = check(b);
            if (a=="0" or b=="0"){
                    throw "incorrect number";
            }

            k+=1;
            st.insert(a);
            st.insert(b);
        }
        outfile << k << std::endl;
        outfile << st.size();
        outfile.close();
        file.close();
    }
    catch(const char* exception){
        std::cerr << "Error: " << exception << '\n';
        outfile << k << std::endl;
        outfile << st.size();
        outfile.close();
    }
    return 0;
}
