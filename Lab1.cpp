#include <conio.h> 
#include <string>
#include <iostream>
#include <locale>
using namespace std;

struct fio { char surname[30]; char name[30]; char patronymic[30]; }; //�������, ���, ��������
//=======     class Phone    =================    
class Phone {
	fio t;
	char adress[50];//������
	int ph_number;//����� ��������
	int intracity, ld_calls;//���-�� ����� ������- � ������������� ���������� 
public:
	Phone();//�����������
	int getintracity();//�������� ���-�� ����� ��������������� ����������
	int getld_calls();//�������� ���-�� ����� ������������� ����������
	char* getsurname();//������� �������� �������
	void show();
};
Phone::Phone()//�����������
{
	cout << "������� �������: "; cin >> t.surname;
	cout << "������� ���: "; cin >> t.name;
	cout << "������� ��������: "; cin >> t.patronymic;
	cout << "������� �����: ";	cin >> adress;
	cout << "������� ����� ��������: ";	cin >> ph_number;
	cout << "������� ����� ��������������� ���������� (���): ";	cin >> intracity;
	cout << "������� ����� ������������� ���������� (���): ";	cin >> ld_calls;
	cout << "==============================" << endl;
}
void Phone::show()
{
	cout << "���             : " << t.surname << ' ' << t.name << ' ' << t.patronymic << endl;
	cout << "�����           : " << adress << endl;
	cout << "����� ��������  : " << ph_number << endl;
}
int Phone::getintracity() { return intracity; }//�������� ���-�� ����� ��������������� ����������
int Phone::getld_calls() { return ld_calls; }//�������� ���-�� ����� ������������� ����������
char* Phone::getsurname() { return t.surname; }//������� �������� �������
void intracitycallsexceedsspecified(Phone spis[], int n)// �)�������� �� ���������, ����� ��������������� ���������� ������� ��������� ��������
{
	int ex_time;
	cout << "������� �������� ���������� �����: ";
	cin >> ex_time;
	for (int i = 0; i < n; i++) {
		if (spis[i].getintracity() < ex_time) {
			spis[i].show();
			cout << "==============================" << endl;
		}
	}
}
void useldcom(Phone spis[], int n)// �) �������� �� ���������, ����������������� ������������� ������
{
	for (int i = 0; i < n; i++)
		if (spis[i].getld_calls() != 0)
			spis[i].show();
}
void alphabet(Phone spis[], int n)// �) �������� �� ���������, ���������� � ���������� �������
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
	cout << "������� ���������� ���������: ";
	cin >> n;
	spis = new Phone[n];
	for (int i = 0; i < n; i++)
	{
		cout << "==============================" << endl;
		spis[i].show();
	}
	cout << "�) �������� �� ���������, ����� ��������������� ���������� ������� ��������� ��������" << endl;
	intracitycallsexceedsspecified(spis, n);
	cout << "�) �������� �� ���������, ����������������� ������������� ������" << endl;
	useldcom(spis, n);
	cout << "�) �������� �� ���������,  ���������� � ���������� �������" << endl;
	alphabet(spis, n);
	for (int i = 0; i < n; i++)
	{
		cout << "==============================" << endl;
		spis[i].show();
	}
	delete[] spis;
	cout << "������� ����� ������!";
		while (!_kbhit());
}