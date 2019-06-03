#include <iostream>
#include <string>

class Zivotinje
{
public:
	virtual unsigned int broj_nogu() = 0;
	virtual std::string vrsta() = 0;
	virtual ~Zivotinje()= 0;
};
Zivotinje::~Zivotinje()
{
	/*std::cout << "No more nice Zivotinja...\n";*/
}
class Insect : public Zivotinje
{
public:
	/*virtual std::string vrsta()=0;*/
	unsigned int broj_nogu() override
	{
		return 6;
	};
	~Insect()
	{
		/*std::cout << "Raid WORKS!!!\n";*/
	}
};
class cockroach : public Insect
{
	/*virtual*/ std::string vrsta() override
	{
		return "cockroach";
	};
	~cockroach()
	{
	/*	std::cout << "Yucky roach is goneee!!!\n";*/
	}
};
class Spider :public Zivotinje
{
public:
	unsigned int broj_nogu() override
	{
		return 8;
	};
	~Spider()
	{
		/*std::cout << "Not so scarry anymore...\n";*/
	}
};
class tarantula : public Spider
{
	/*virtual*/ std::string vrsta() override
	{
		return "tarantula";
	};
	~tarantula()
	{
		/*std::cout << "No more gross tarantula!!!\n";*/
	}
};
class Bird : public Zivotinje
{
public:
	/*virtual std::string vrsta()=0;*/
	/*virtual*/ unsigned int broj_nogu() override
	{
		return 2;
	};
	~Bird()
	{
		/*std::cout << "Where did the bird go??\n";*/
	}
};
class sparrow : public Bird
{
	/*virtual*/ std::string vrsta() override
	{
		return "sparrow";
	};
	~sparrow()
	{
		/*std::cout << "sparrow goes Ka Boom!!!\n";*/
	}
	
};

Zivotinje* zivotinjice(const unsigned int& Id)
{
	switch (Id)
	{
	case 1:
	{
		return new cockroach;
		break;
	}
	case 2:
	{
		return new tarantula;
		break;
	}
	case 3:
	{
		return new sparrow;
		break;
	}
	default:
		std::cout << "Nema takve zivotinje!!";
		break;
	}
	
}
class brojac
{
	unsigned int br_nogu = 0;
public:
	void dodaj(Zivotinje* zivotinjica)
	{
		std::cout << zivotinjica->vrsta()<< std::endl;
		br_nogu += zivotinjica->broj_nogu();
		delete zivotinjica;
	}
	unsigned int ukupno()
	{
		return br_nogu;
	}
	~brojac()
	{
		/*std::cout << "Pobrisano!!";*/
	}
};

int main()
{
	brojac brojim; unsigned int id;
	while (std::cin >> id )
	{
		/*if (id == 1 || id == 2 || id == 3)*/
		/*{*/
			brojim.dodaj(zivotinjice(id));
			
		/*}*/
		/*else
			break;*/
	}
	/*brojim.dodaj(zivotinjice(1));
	brojim.dodaj(zivotinjice(2));
	brojim.dodaj(zivotinjice(3));*/
	std::cout << brojim.ukupno();
	/*getchar();
	getchar();*/
	return 0;
}

