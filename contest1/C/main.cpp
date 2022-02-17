#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

int main()
{
    int n;
    int a;
    std::cin >> n;
    std::set <int> st;
    for (int i = 0; i < n; ++i){
        std::cin >> a;
        st.insert(a);
    }
    std::cout << std::endl;
    std::cout << st.size();
    return 0;
}
