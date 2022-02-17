#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>

struct inf{
    std::string in_call, out_call;
};

std::ostream& operator << (std::ostream& out, const inf& p){
    out << p.in_call << " " << p.out_call;
    return out;
}

std::istream& operator >> (std::istream& in, inf& p){
    in >> p.in_call >> p.out_call;
    return in;
}

int main()
{
    std::ifstream file;
    file.open("input.txt");
    std::ofstream outfile;
    outfile.open("output.txt");
    std::vector<inf> v;
    std::set<std::string> st;

    std::copy(std::istream_iterator<inf>(file), std::istream_iterator<inf>(), std::inserter(v,v.end()));
    std::transform(v.begin(), v.end(), std::inserter(st, st.end()),
                 [](auto& a)->std::string{
                    if ((a.in_call).find("7800")==0){return a.out_call;}
                    else {return "-1";}
                });
    st.erase("-1");
    outfile << st.size();
    return 0;
}
