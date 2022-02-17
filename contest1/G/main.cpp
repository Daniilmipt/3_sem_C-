#include <iostream>
#include <stack>
#include <string>

int main()
{
    int a = 0;
    std::string x;
    std::stack <int> s;
    std::string oper = "+-*/";



while (std::cin >> x) {
        if (oper.find(x) == 0) {
            a = s.top();
            s.pop();
            a = a + s.top();
            s.pop();
            s.push(a);
        }

        if (oper.find(x) == 1) {
            a = s.top();
            s.pop();
            a = s.top() - a;
            s.pop();
            s.push(a);
        }

        if (oper.find(x) == 2) {
            a = s.top();
            s.pop();
            a = a * s.top();
            s.pop();
            s.push(a);
        }

        if (oper.find(x) == 3) {
            a = s.top();
            s.pop();
            a = s.top() / a;
            s.pop();
            s.push(a);
        }

        if (oper.find(x) == std::string::npos) s.push(std::stoi(x));
}

    std::cout << a;
}
