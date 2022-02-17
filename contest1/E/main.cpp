#include <iostream>
#include <stack>


int main()
{
    int b,a;
    std::stack <int> st;

    std::cin>>a;
    while(a != 0){
        if (a>0){
            st.push(a);
        }
        else{
            if (!st.empty()){

            if (-a < st.top()){
                int b = a + st.top();
                st.pop();
                st.push(b);
            }
            else{
                st.pop();
            }
            }
        }
        std::cin>>a;
    }

    if(st.empty()){
        std::cout << 0 << " " << -1;
    }else{
        std::cout << st.size() << " " << st.top();
    }
    return 0;
}
