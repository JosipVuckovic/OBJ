#include <iostream>
#include <string>
#include <iomanip>
#include <exception>

class Excp_Baza { public: virtual std::string err() = 0; };
class Nije_br : public Excp_Baza { public: std::string err()override { return "not a number"; } };
class djelj_nula : public Excp_Baza { public: std::string err()override { return "divide by zero"; } };
class nedoz_op : public Excp_Baza { public: std::string err()override { return "invalid operation"; } };

int unos_broja()throw (Excp_Baza)
{
	int a;
	std::cin >> a;
	if (!std::cin)
		throw Nije_br();
	
	return a;
}

char unos_oper()throw(Excp_Baza)
{
	char oper;
	std::cin >> oper;
	if (oper != '+' && oper != '-' && oper != '*' && oper != '/') throw nedoz_op();
	return oper;
}

double operacija(const int a, const int b, char c)throw(Excp_Baza)
{
	if (c == '/' && b == 0) throw djelj_nula();
	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return static_cast<double>(a) / b;
	}
	return 0;
}

int main()
{
	while (true)
	{
		try
		{
			int prvi_broj(unos_broja());
			char oper(unos_oper());
			int drugi_broj(unos_broja());
			std::cout << prvi_broj << oper << drugi_broj << "=" << operacija(prvi_broj, drugi_broj, oper) << std::endl;
		}
		catch (Excp_Baza& x)
		{
			std::cout << x.err() << std::endl;
			break;
		}
	}
	//getchar();
	//getchar();
}