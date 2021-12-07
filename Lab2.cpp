#include <iostream>
#include <conio.h>
#include <string>
#include <locale>

using namespace std;

class Engine {
protected:
    string name;

public:
    static Engine* begin;
    Engine* next;

    static void add(Engine* cur) {
        cur->next = begin;
        begin = cur;
    }

    Engine() {
        add(this);
    }

    virtual void show() {
        cout << "������������: " << name << endl;
        cout << "----------------------------" << endl;
    }

    virtual void set_parameters() {
        string s;

        cout << "�����������: ";
        cin >> s;

        name = s;
    }

    virtual void print() {
        Engine* l = begin;

        while (l) {
            l->show();
            l = l->next;
        }
    }
};

Engine* Engine::begin;

class ICengine : public Engine {
protected:
    int cylinder;//���-�� ���������
    float CCvolume;//����� ������ ��������
    int power;//�������� ��������� (�.�)

public:
    ICengine() : Engine() {}

    void show() {
        cout << "������������: " << name << endl;
        cout << "���������� ���������: " << cylinder << endl;
        cout << "����� ������ ��������: " << CCvolume << endl;
        cout << "�������� ��������� � �.�. : " << power << endl;
        cout << "----------------------------" << endl;
    }

    void set_parameters() {
        int c, p;
        float cc;
        string n;

        cout << "������������: "; cin >> n;
        cout << "���������� ���������: "; cin >> c;
        cout << "����� ������ ��������: "; cin >> cc;
        cout << "�������� ��������� � �.�. : "; cin >> p;

        name = n;
        cylinder = c;
        CCvolume = cc;
        power = p;
    }

};

class Diesel : public Engine {
protected:
    int efficiency;//% ������������� ���������

public:
    Diesel() :Engine() {}

    void show() {
        cout << "������������: " << name << endl;
        cout << "������������� ���������: " << efficiency << endl;
        cout << "----------------------------" << endl;
    }

    void set_parameters() {
        int e;
        string n;

        cout << "������������: "; cin >> n;
        cout << "������������� ���������: "; cin >> e;

        name = n;
        efficiency = e;
    }
};

class Turbojet : public Engine {
protected:
    int contour; //���-�� ��������
    int thrust; //����������� ���������� ���� (���-�� ������� � ������)
public:
    Turbojet() :Engine() {}

    void show() {
        cout << "������������: " << name << endl;
        cout << "���������� ��������: " << contour << endl;
        cout << "����������� ���������� ����: " << thrust << endl;
        cout << "----------------------------" << endl;
    }

    void set_parameters() {
        int c, t;
        string n;

        cout << "������������: "; cin >> n;
        cout << "���������� ��������: "; cin >> c;
        cout << "����������� ���������� ����: "; cin >> t;

        name = n;
        contour = c;
        thrust = t;
    }
};

int main() {
    setlocale(LC_CTYPE, "rus");
    Engine::begin = 0;
    Engine engine;
    ICengine icengine;
    Diesel diesel;
    Turbojet turbojet;

    cout << "���������" << endl;
    engine.set_parameters();

    cout << "��������� ����������� ��������" << endl;
    icengine.set_parameters();

    cout << "��������� ���������" << endl;
    diesel.set_parameters();

    cout << "�����-���������� ���������" << endl;
    turbojet.set_parameters();

    cout << "============================" << endl;
    cout << "��� ���������" << endl;
    cout << "============================" << endl;

    engine.print();

    return 0;
}