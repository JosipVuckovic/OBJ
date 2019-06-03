#include <ostream>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iterator> 


bool isPowerOfTwo(int n)
{
	if (n == 0)
		return false;
return (ceil(log2(n)) == floor(log2(n)));
}
bool paran(int n)
{
	return n % 2==0;
}
bool neparan(int n)
{
	return n % 2 != 0;
}
// funkcijski objekt 
class less 
{
	int n;
public:
	less(int n) : n(n) {};
	bool operator()(int num) { return num > n; }
};
bool my_sort(int prvi, int drugi)
{
	bool ret = prvi < drugi;
	if (prvi % 2 == 0 && drugi % 2 == 0)
	{
		return ret;;
	}
	else if (prvi % 2 == 0)
	{
		return true;
	}
	else if(drugi %2 == 0)
	{
		return false;
	}
	return ret;
}

int main()
{
	std::vector<int> unos;
	std::istream_iterator<int> is(std::cin), eof;
	copy(is, eof, std::back_inserter(unos));

	if (!unos.empty())
	std::cout << *(std::min_element(unos.begin(), unos.end())) << std::endl;
	

	std::vector<int>::const_iterator it = std::find_if(unos.begin(), unos.end(), neparan);
	if (it != unos.end())
		std::cout << *it <<std::endl;


	std::cout << std::count_if(unos.begin(), unos.end(), neparan) << std::endl;
	unos.erase(std::remove_if(unos.begin(), unos.end(), less(100)), unos.end());
	std::replace_if(unos.begin(), unos.end(), isPowerOfTwo, 2);

	std::sort(unos.begin(), unos.end(), my_sort);
	

	std::ostream_iterator<int> os(std::cout," ");
	copy(unos.begin(), unos.end(), os);

	return 0;
}