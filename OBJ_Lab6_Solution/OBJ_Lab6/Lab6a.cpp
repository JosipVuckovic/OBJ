#include <ostream>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

int main()
{
	std::string unos;
	std::map<std::string,int> mapa;
	while (std::cin >> unos)
	{
		std::transform(unos.begin(), unos.end(), unos.begin(), ::tolower);
		mapa[unos]++;
	}
	for (auto elem : mapa)
	{
		std::cout << elem.first << " : " << elem.second << std::endl;
	}
	return 0;
}
