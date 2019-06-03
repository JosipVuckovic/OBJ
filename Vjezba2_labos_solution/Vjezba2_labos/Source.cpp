#include <iostream>
#include <string>
struct  student
{
	int ocjena;
	std::string ime;
};
class rezultat
{
	int index;
	student* stud;	
public:
	rezultat(int count) :index(0)
	{
		stud = new student[count];
	}
	void add(const student& s)
	{
		stud[index++] = s;
	}
	int prvoslovo(char slovo)const
	{
		int count = 0, i = 0;
		while (i < index) {
			if (tolower(stud[i].ime[0]) == tolower(slovo)) {
				count++;
			}
			i++;
		}
		return count;
	}
	int imaocjenu(int ocjena) const
	{
		int brojac = 0, i;
		for (i = 0; i<index; i++)
		{
			if (stud[i].ocjena == ocjena) {
				brojac++;
			}
		}
		return brojac;
	}
	~rezultat() {
		delete[] stud;
		stud = nullptr;
	}
};
int main()
{
	int i, brojunosa;
	/*std::cout << "Broj Unosa:";*/
	std::cin >> brojunosa;
	rezultat rez(brojunosa);
	for (i = 0; i != brojunosa; i++)
	{
		student stud;
		std::cin >> stud.ime >> stud.ocjena;
		rez.add(stud);
	}
	int ocjena;
	char slovo;
	//std::cout << "Ocjena:";
	std::cin >> ocjena;
	//std::cout << "Unesi slovo:";
	std::cin >> slovo;
	std::cout << rez.imaocjenu(ocjena) << "\n";
	std::cout << rez.prvoslovo(slovo);
	//std::cout << "kraj:";
}