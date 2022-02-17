#include <iostream>
#include <deque>
#include <queue>
#include <string>
int main()
{
	std::deque <int> dq;
	int N;
	std::cin>>N;
	for (int i=0;i<N;++i)
	{
		std::string m;
		std::cin>>m;
		if (m=="*")
		{
			std::string k;
			std::cin>>k;
			int a = std::stoi(k);
			dq.insert(dq.begin()+dq.size()%2+dq.size()/2,a);
		}
		else if (m=="+")
		{
			std::string k;
			std::cin>>k;
			int a = std::stoi(k);
			dq.push_back(a);
		}
		else if (m=="-")
		{
			int a = dq.front();
			dq.pop_front();
			std::cout<<a<<std::endl;
		}
	}
	return 0;
}
