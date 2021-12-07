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
        cout << "Наименование: " << name << endl;
        cout << "----------------------------" << endl;
    }

    virtual void set_parameters() {
        string s;

        cout << "Наиенование: ";
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
    int cylinder;//Кол-во цилиндров
    float CCvolume;//Объём камеры сгорания
    int power;//Мощность двигателя (л.с)

public:
    ICengine() : Engine() {}

    void show() {
        cout << "Наименование: " << name << endl;
        cout << "Количество цилиндров: " << cylinder << endl;
        cout << "Объём камеры сгорания: " << CCvolume << endl;
        cout << "Мощность двигателя в л.с. : " << power << endl;
        cout << "----------------------------" << endl;
    }

    void set_parameters() {
        int c, p;
        float cc;
        string n;

        cout << "Наименование: "; cin >> n;
        cout << "Количество цилиндров: "; cin >> c;
        cout << "Объём камеры сгорания: "; cin >> cc;
        cout << "Мощность двигателя в л.с. : "; cin >> p;

        name = n;
        cylinder = c;
        CCvolume = cc;
        power = p;
    }

};

class Diesel : public Engine {
protected:
    int efficiency;//% эффективности двигателя

public:
    Diesel() :Engine() {}

    void show() {
        cout << "Наименование: " << name << endl;
        cout << "Эффективность двигателя: " << efficiency << endl;
        cout << "----------------------------" << endl;
    }

    void set_parameters() {
        int e;
        string n;

        cout << "Наименование: "; cin >> n;
        cout << "Эффективность двигателя: "; cin >> e;

        name = n;
        efficiency = e;
    }
};

class Turbojet : public Engine {
protected:
    int contour; //Кол-во контуров
    int thrust; //Создаваемая двигателем тяга (кол-во воздуха в секнду)
public:
    Turbojet() :Engine() {}

    void show() {
        cout << "Наименование: " << name << endl;
        cout << "Количество контуров: " << contour << endl;
        cout << "Создаваемая двигателем тяга: " << thrust << endl;
        cout << "----------------------------" << endl;
    }

    void set_parameters() {
        int c, t;
        string n;

        cout << "Наименование: "; cin >> n;
        cout << "Количество контуров: "; cin >> c;
        cout << "Создаваемая двигателем тяга: "; cin >> t;

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

    cout << "Двигатель" << endl;
    engine.set_parameters();

    cout << "Двигатель внутреннего сгорания" << endl;
    icengine.set_parameters();

    cout << "Дизельный двигатель" << endl;
    diesel.set_parameters();

    cout << "Турбо-реактивный двигатель" << endl;
    turbojet.set_parameters();

    cout << "============================" << endl;
    cout << "Все двигатели" << endl;
    cout << "============================" << endl;

    engine.print();

    return 0;
}