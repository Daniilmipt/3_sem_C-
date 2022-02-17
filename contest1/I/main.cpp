#include <iostream>
#include <set>

class Checker {
public:
    Checker();
    void Add(const std::string& s);
    bool Exists(const std::string& s);
private:
    std::set <std::string> st;
};

Checker::Checker(){

}

void Checker::Add(const std::string& s){
    st.insert(s);
}

bool Checker::Exists(const std::string& s){
    std::cout.setf(std::ios::boolalpha);
    if (st.find(s) != st.end()){
        return true;
    } else return false;
}

int main()
{
    Checker s;
    s.Add("aaa");
    std::cout << s.Exists("aa");
    return 0;
}
