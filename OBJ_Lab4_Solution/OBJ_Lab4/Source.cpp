#include <iostream>
#include <string>
#include <iomanip>
class Money
{
	int kune;
	int lipe;
public:
	Money(int kune=0, int lipe=0) :kune(kune), lipe(kune) {};
	~Money() {};
	Money operator+(const Money &drugi)
	{
		this->kune=this->kune + drugi.kune;
		if ((this->lipe=this->lipe + drugi.lipe) >= 100)
		{
			this->kune = this->kune + ((this->lipe + drugi.lipe) / 100);
			this->lipe = this->lipe % 100;
		}
		return *this;
	}
	Money operator+=(const Money &drugi)
	{
		this->kune = this->kune + drugi.kune;
		if ((this->lipe = this->lipe + drugi.lipe) >= 100)
		{
			this->kune = this->kune + ((this->lipe + drugi.lipe) / 100);
			this->lipe = this->lipe % 100;
		}
		return *this;
	}
	Money operator-(const Money &drugi)
	{
		this->kune = this->kune - drugi.kune;
		if (this->lipe < drugi.lipe)
		{
			this->lipe = this->lipe + 100 - drugi.lipe;
			this->kune--;
		}
		else
			this->lipe = this->lipe - drugi.lipe;
		return *this;
	}
	Money operator-=(const Money &drugi)
	{
		this->kune = this->kune - drugi.kune;
		if (this->lipe < drugi.lipe)
		{
			this->lipe = this->lipe + 100 - drugi.lipe;
			this->kune--;
		}
		else
			this->lipe = this->lipe - drugi.lipe;
		return *this;
	}
	friend std::ostream &operator<<(std::ostream &output, const Money &unos)
	{
		
			output << unos.kune << " kn" << std::endl;
			
			if (unos.lipe)
				output << ", " << std::setw(2) << std::setfill('0') << unos.lipe << " lp" << std::endl;
			
		return output;
	}

	friend std::istream &operator>>(std::istream &input, Money &unos)
	{
		input >> unos.kune >> unos.lipe;
		return input;
	}
};

int main()
{
	Money unos;
	Money total(0, 0);
	char op;
	while (std::cin >> op >> unos)
	{
		switch (op)
		{
		case '-':
			total -= unos;
			break;
		default:
			total+=unos;
			break;
		}
		
		std::cout << total<<std::endl;
	}
	/*getchar();
	getchar();*/
}