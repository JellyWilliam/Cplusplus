#include <conio.h> 
#include <string>
#include <iostream>
#include <locale>
using namespace std;

struct fio { char surname[30]; char name[30]; char patronymic[30]; }; //Фамилия, Имя, Отчество
//=======     class Phone    =================    
class Phone {
	fio t;
	char adress[50];//адресс
	int ph_number;//номер телефона
	int intracity, ld_calls;//Кол-во минут внутри- и междугородних разговоров 
public:
	Phone();//конструктор
	int getintracity();//Получить кол-во минут внутригородских разговоров
	int getld_calls();//Получить кол-во минут междугородних разговоров
	char* getsurname();//Функция возврата фамилии
	void show();
};
Phone::Phone()//Конструктор
{
	cout << "Введите фамилию: "; cin >> t.surname;
	cout << "Введите имя: "; cin >> t.name;
	cout << "Введите отчество: "; cin >> t.patronymic;
	cout << "Введите адрес: ";	cin >> adress;
	cout << "Введите номер телефона: ";	cin >> ph_number;
	cout << "Введите время внутригородских разговоров (мин): ";	cin >> intracity;
	cout << "Введите время междугородних разговоров (мин): ";	cin >> ld_calls;
	cout << "==============================" << endl;
}
void Phone::show()
{
	cout << "ФИО             : " << t.surname << ' ' << t.name << ' ' << t.patronymic << endl;
	cout << "Адрес           : " << adress << endl;
	cout << "Номер телефона  : " << ph_number << endl;
}
int Phone::getintracity() { return intracity; }//Получить кол-во минут внутригородских разговоров
int Phone::getld_calls() { return ld_calls; }//Получить кол-во минут междугородних разговоров
char* Phone::getsurname() { return t.surname; }//Функция возврата фамилии
void intracitycallsexceedsspecified(Phone spis[], int n)// а)сведения об абонентах, время внутригородских разговоров которых превышает заданное
{
	int ex_time;
	cout << "Введите заданное количество минут: ";
	cin >> ex_time;
	for (int i = 0; i < n; i++) {
		if (spis[i].getintracity() < ex_time) {
			spis[i].show();
			cout << "==============================" << endl;
		}
	}
}
void useldcom(Phone spis[], int n)// б) сведения об абонентах, воспользовавшихся междугородней связью
{
	for (int i = 0; i < n; i++)
		if (spis[i].getld_calls() != 0)
			spis[i].show();
}
void alphabet(Phone spis[], int n)// в) сведения об абонентах, выведенные в алфавитном порядке
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (strcmp(spis[i].getsurname(), spis[j].getsurname()) > 0) 
				swap(spis[i], spis[j]);
	}
}
// ========    main   ================
void main()
{
	setlocale(LC_CTYPE, "rus");
	Phone* spis;
	int n;
	cout << "Введите количество абонентов: ";
	cin >> n;
	spis = new Phone[n];
	for (int i = 0; i < n; i++)
	{
		cout << "==============================" << endl;
		spis[i].show();
	}
	cout << "а) сведения об абонентах, время внутригородских разговоров которых превышает заданное" << endl;
	intracitycallsexceedsspecified(spis, n);
	cout << "б) сведения об абонентах, воспользовавшихся междугородней связью" << endl;
	useldcom(spis, n);
	cout << "в) сведения об абонентах,  выведенные в алфавитном порядке" << endl;
	alphabet(spis, n);
	for (int i = 0; i < n; i++)
	{
		cout << "==============================" << endl;
		spis[i].show();
	}
	delete[] spis;
	cout << "Нажмите любую кнопку!";
		while (!_kbhit());
}