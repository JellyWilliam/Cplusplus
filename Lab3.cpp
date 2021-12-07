#include <iostream>
#include <time.h>
#include <fstream>
#include <array>
using namespace std;


class Matrix
{
protected:
    int l, c;
    int** matrix;


public:
    Matrix(int, int);
    Matrix();
    Matrix(const Matrix& ob); //����������� �����������
    Matrix& operator=(const Matrix&); // ����������� ������������
    Matrix operator*(int)const;
    Matrix operator + (Matrix& ob);
    friend ostream& operator<<(ostream&, const Matrix&);
    friend istream& operator>>(istream&, Matrix&);
    Matrix transpositionColumn(Matrix& ob);
    Matrix transpositionLine(Matrix& ob);

    ~Matrix();
};

// ����������� �� ���������
Matrix::Matrix()
{
    l = 0;
    c = 0;
    matrix = 0;
}

// ����������� � ����������� � �������� ������ ���������  ������� � �������������� �������� �������

Matrix::Matrix(int l1, int c1)
{
    l = l1;
    c = c1;

    matrix = new int* [l];
    for (int i = 0; i < l; i++)
    {
        matrix[i] = new int[c];
    }
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            matrix[i][j] = { 0 };
}

Matrix::Matrix(const Matrix& ob)
{
    l = ob.l;
    c = ob.c;
    if (ob.matrix == 0)
    {
        matrix = 0;
        return;
    }

    matrix = new int* [l];
    for (int i = 0; i < l; i++)
    {
        matrix[i] = new int[c];
    }
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            matrix[i][j] = ob.matrix[i][j];
}


Matrix::~Matrix()
{
    if (matrix != 0)
    {
        for (int i = 0; i < l; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
}

// �������� ��������� ������� �� �����
Matrix Matrix::operator * (int a)const
{
    Matrix temp(l, c);
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            temp.matrix[i][j] = matrix[i][j] * a;
    return temp;
}

// ������������� �������� ����� �������

istream& operator >> (istream& in, Matrix& ob)
{
    if (ob.matrix != 0)
    {
        for (int i = 0; i < ob.l; i++)
            for (int j = 0; j < ob.c; j++)
                in >> ob.matrix[i][j];
    }
    return in;
}

// ������������� �������� ������ �������

ostream& operator<<(ostream& out, const Matrix& ob)
{
    if (ob.matrix != 0)
    {
        out << "�������:" << endl;
        for (int i = 0; i < ob.l; i++)
        {
            for (int j = 0; j < ob.c; j++)
                out << ob.matrix[i][j] << "\t";
            out << endl;
        }
    }
    else
        out << "������� �����" << endl;
    return out;
}


Matrix Matrix::operator + (Matrix& ob)
{
    if (c == ob.c)
    {
        // �������� �������-����������
        Matrix temp(l, ob.c);
        // ���������� �������-����������
        for (int i = 0; i < l; i++)
            for (int j = 0; j < ob.c; j++)
                temp.matrix[i][j] = matrix[i][j] + ob.matrix[i][j];

        return temp;
    }

}

Matrix& Matrix::operator = (const Matrix& ob)
{
    if (c != ob.c || l != ob.l)
    {
        // ������������ ������ � ����� ��������
        for (int i = 0; i < l; i++)
            delete[] matrix[i];
        delete[] matrix;
        // ��������� ������ � ����� ��������
        c = ob.c;
        l = ob.l;
        matrix = new int* [l];
        for (int i = 0; i < l; i++)
            matrix[i] = new int[c];
    }
    // ����������� ������ ������� �������� � �����
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            matrix[i][j] = ob.matrix[i][j];
    return *this;
}

Matrix Matrix::transpositionColumn(Matrix& ob)
{
    Matrix temp(l, c);
    cout << "������ ������������ ������� (2 �����): ";
    int n = 0;
    int* arr1 = new int[c];
    for (int i = 0; i < c; i++)
        cin >> arr1[i];
    for (int i = 0; i < c; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++)
            temp.matrix[i][j] = ob.matrix[i][arr1[j]];
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++)
            ob.matrix[i][j] = temp.matrix[i][j];

    }

    return ob;
}

Matrix Matrix::transpositionLine(Matrix& ob)
{
    Matrix temp(l, c);
    cout << "������ ������������ ������ (2 �����): ";
    int n = 0;
    int* arr2 = new int[l];
    for (int i = 0; i < l; i++)
        cin >> arr2[i];
    for (int i = 0; i < l; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++)
            temp.matrix[i][j] = ob.matrix[arr2[i]][j];
    }

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++)
            ob.matrix[i][j] = temp.matrix[i][j];

    }

    return ob;
}



class QMatrix : public Matrix
{
public:

    // �������� ������������
    QMatrix& operator = (const Matrix& ob)
    {
        Matrix::operator = (ob);
        return *this;
    }

    QMatrix(const Matrix& ob) : Matrix(ob)
    {
    }

    explicit QMatrix(int n) : Matrix(n, n)
    {

    }

    // ����������� �� ���������
    QMatrix() :Matrix()
    {

    }

    using Matrix::operator*;

    QMatrix operator * (QMatrix& ob)
    {
        if (c == ob.l)
        {
            // �������� �������-����������
            QMatrix temp(ob.c);
            // ���������� �������-����������
            for (int i = 0; i < l; i++)
                for (int j = 0; j < ob.c; j++)
                    for (int k = 0; k < c; k++)
                        temp.matrix[i][j] +=
                        (matrix[i][k] * ob.matrix[k][j]);
            return temp;
        }
    }

    // ���������������� �������
    QMatrix operator !()
    {
        QMatrix temp(c);
        for (int i = 0; i < l; i++)
            for (int j = 0; j < c; j++)
                temp.matrix[j][i] = matrix[i][j];
        return temp;
    }


};

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������� ������� a � �������� 2*3: " << endl;
    Matrix a(2, 3), d(2, 3);
    cin >> a;
    cout << "������� ������� d � �������� 2*3: " << endl;
    cin >> d;
    cout << "�������� �������: " << endl;
    cout << a << endl;
    cout << d << endl;
    cout << "������� c = a * 5: " << endl;
    Matrix c = a * 5;
    cout << c << endl;
    cout << "������� r = a + d: " << endl;
    Matrix r = a + d;
    cout << r;
    cout << "����������������� ������� �: " << endl;
    cout << a.transpositionColumn(r);
    cout << "������� ������� o � �������� 2*2: ";
    QMatrix o(2), u(2);
    cin >> o;
    cout << "������� ������� u � �������� 2*2: ";
    cin >> u;
    cout << "�������� �������: " << endl;
    cout << o << endl;
    cout << u << endl;
    cout << "������� t = o * u: " << endl;
    QMatrix t = o * u;
    cout << t << endl;
    cout << "����������������� ������� t: ";
    cout << !t << endl;
    cout << t.transpositionColumn(t);
    cout << t.transpositionLine(t);
    cout << "������� v = o * 5: " << endl;
    QMatrix v = o * 5;
    cout << v;
    cout << "o + u: " << endl;
    cout << o + u;
    system("pause");
}