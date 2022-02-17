#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>


int main()
{
    int n;
    std::string a;
    std::set <std::string> st;
    std::cin >> n;

    for(int i = 0; i < n; ++i){
        std::cin >> a;
        std::transform(a.begin(), a.end(), a.begin(), tolower);
        st.insert(a);

    }
    std::reverse_copy(st.begin(), st.end(), std::ostream_iterator<std::string>(std::cout, " "));
    return 0;
}
