#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const string GREEN = "\033[32m";
const string RESET = "\033[0m";

float func(const vector<float>& coefficients, float x) {
    float res = 0;
    int length = coefficients.size();

    for (int i = 0; i < length; i++) {
        res += coefficients[i] * pow(x, length - 1 - i);
    }
    return res;
}

void bisection_method(const vector<float>& coefficients, bool find_max = false) {
    cout << GREEN << (find_max ? "����� ����������� ������� (����� ���������)" : 
        "����� ����������� ������� (����� ��������)") << RESET << endl << endl;

    float a, b, epsilon;
    cout << "������� ������� ������� [a, b]: ";
    cin >> a >> b;
    cout << "������� ��������� �������� epsilon: ";
    cin >> epsilon;
    
    if (a >= b) {
        throw invalid_argument("������� ������� ������ �����������: a ������ ���� ������ b");
    }

    int k = 0;
    float x = (a + b) / 2.0f;
    float L = fabs(b - a);

    cout << GREEN << "\n��������� ���������:" << RESET << endl;
    cout << "x0 = " << x << ", L0 = " << L << ", f(x0) = " << func(coefficients, x) << endl;
    while (L > epsilon) {
        cout << GREEN << "\n�������� " << k << ":" << RESET << endl;

        float y = a + L / 4.0f;
        float z = b - L / 4.0f;
        float func_x = func(coefficients, x);
        float func_y = func(coefficients, y);
        float func_z = func(coefficients, z);

        cout << "y = " << y << ", f(y) = " << func_y << endl;
        cout << "z = " << z << ", f(z) = " << func_z << endl;

        if ((!find_max && func_y < func_x) || (find_max && func_y > func_x)) {
            b = x;
            x = y;
            cout << (!find_max ? "f(y) < f(x) => ����� �������: [" : "f(y) > f(x) => ����� �������: [") << a << ", " << b << "]" << endl;
        }
        else {
            if ((!find_max && func_z < func_x) || (find_max && func_z > func_x)) {
                a = x;
                x = z;
                cout << (!find_max ? "f(z) < f(x) => ����� �������: [" : "f(z) > f(x) => ����� �������: [") << a << ", " << b << "]" << endl;
            }
            else {
                a = y;
                b = z;
                cout << (!find_max ? "f(y) >= f(x) � f(z) >= f(x) => ����� �������: [" : "f(y) <= f(x) � f(z) <= f(x) => ����� �������: [") << a << ", " << b << "]" << endl;
            }
        }
        L = fabs(b - a);
        k++;
        cout << "����� ���������: x = " << x << ", L = " << L << endl;
    }
    cout << GREEN << "\n���������:" << RESET << endl;
    cout << "x = " << x << ", f(x) = " << func(coefficients, x) << endl;
    cout << "���������� ��������: " << k << endl;
}

void golden_section_method(const vector<float>& coefficients, bool find_max = false) {
    cout << GREEN << (find_max ? "����� �������� ������� (����� ���������)" :
        "����� �������� ������� (����� ��������)") << RESET << endl << endl;

    float a, b, epsilon;
    cout << "������� ������� ������� [a, b]: ";
    cin >> a >> b;
    cout << "������� ��������� �������� (epsilon): ";
    cin >> epsilon;
    
    if (a >= b) {
        throw invalid_argument("������� ������� ������ �����������: a ������ ���� ������ b");
    }

    int k = 0;
    float del = fabs(a - b);
    float y = a + (3.0f - sqrt(5.0f)) / 2.0f * (b - a);
    float z = a + b - y;

    cout << GREEN << "\n��������� ���������:" << RESET << endl;
    cout << "y0 = " << y << ", z0 = " << z << ", L0 = " << del << endl;

    while (del > epsilon) {
        cout << GREEN << "\n�������� " << k << ":" << RESET << endl;
        
        float func_y = func(coefficients, y);
        float func_z = func(coefficients, z);

        cout << "f(y) = " << func_y << ", f(z) = " << func_z << endl;

        if ((!find_max && func_y <= func_z) || (find_max && func_y >= func_z)) {
            b = z;
            z = y;
            y = a + b - y;
            cout << (!find_max ? "f(y) <= f(z) => ����� �������: [" : "f(y) >= f(z) => ����� �������: [") << a << ", " << b << "]" << endl;
        }
        else {
            a = y;
            y = z;
            z = a + b - z;
            cout << (!find_max ? "f(y) > f(z) => ����� �������: [" : "f(y) < f(z) => ����� �������: [") << a << ", " << b << "]" << endl;
        }
        del = fabs(a - b);
        k++;
        cout << "����� �����: y = " << y << ", z = " << z << ", L = " << del << endl;
    }
    float x = (a + b) / 2.0f;
    cout << GREEN << "\n���������:" << RESET << endl;
    cout << "x = " << x << ", f(x) = " << func(coefficients, x) << endl;
    cout << "���������� ��������: " << k << endl;
}

float fibonacci_number(int N) {
    if (N < 0) return 0;
    if (N == 0 || N == 1) return 1;

    float a = 1, b = 1;
    for (int i = 2; i <= N; ++i) {
        float next = a + b;
        a = b;
        b = next;
    }
    return b;
}

void fibonacci_method(const vector<float>& coefficients, bool find_max = false) {
    cout << GREEN << (find_max ? "����� ����� ��������� (����� ���������)" :
        "����� ����� ��������� (����� ��������)") << RESET << endl << endl;

    float a, b, epsilon, l;
    cout << "������� ������� ������� [a, b]: ";
    cin >> a >> b;
    cout << "������� ��������� �������� epsilon: ";
    cin >> epsilon;
    cout << "������� �������� l: ";
    cin >> l;

    if (a >= b) {
        throw invalid_argument("������� ������� ������ �����������: a ������ ���� ������ b");
    }
    if (epsilon <= 0 || l <= 0) {
        throw invalid_argument("�������� � �������� l ������ ���� ��������������");
    }

    float FN = fabs(a - b) / l;
    int N = 0;
    while (fibonacci_number(N) < FN) {
        N++;
        if (N > 1000) {
            throw runtime_error("������� ������� N, �������� ������������");
        }
    }

    cout << "\nF(N) = " << FN << ", N = " << N << endl;

    int k = 0;
    float y = a + (fibonacci_number(N - 2) / fibonacci_number(N)) * (b - a);
    float z = a + (fibonacci_number(N - 1) / fibonacci_number(N)) * (b - a);
    cout << GREEN << "\n��������� ���������:" << RESET << endl;
    cout << "y0 = " << y << ", z0 = " << z << endl;

    while (k < N - 2) {
        cout << GREEN << "\n�������� " << k << ":" << RESET << endl;
        float func_y = func(coefficients, y);
        float func_z = func(coefficients, z);
        cout << "f(y) = " << func_y << ", f(z) = " << func_z << endl;

        if ((!find_max && func_y <= func_z) || (find_max && func_y >= func_z)) {
            b = z;
            z = y;
            y = a + (fibonacci_number(N - k - 3) / fibonacci_number(N - k - 1)) * (b - a);
            cout << (!find_max ? "f(y) <= f(z) => ����� �������: [" : "f(y) >= f(z) => ����� �������: [") << a << ", " << b << "]" << endl;
        }
        else {
            a = y;
            y = z;
            z = a + (fibonacci_number(N - k - 2) / fibonacci_number(N - k - 1)) * (b - a);
            cout << (!find_max ? "f(y) > f(z) => ����� �������: [" : "f(y) < f(z) => ����� �������: [") << a << ", " << b << "]" << endl;
        }
        k++;
        cout << "����� �����: y = " << y << ", z = " << z << endl;
    }
    float y_final = y;
    float z_final = y_final + epsilon;
    float func_y_final = func(coefficients, y_final);
    float func_z_final = func(coefficients, z_final);

    if ((!find_max && func_y_final <= func_z_final) || (find_max && func_y_final >= func_z_final)) {
        b = z_final;
    }
    else {
        a = y_final;
    }
    float x = (a + b) / 2.0f;
    cout << GREEN << "\n���������:" << RESET << endl;
    cout << "x = " << x << ", f(x) = " << func(coefficients, x) << endl;
    cout << "���������� ��������: " << k << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int degree;
    cout << "������� ������� ��������: ";
    cin >> degree;
    if (degree < 1) {
        throw invalid_argument("������� �������� ������ ���� �������������.");
    }

    vector<float> coefficients(degree + 1);
    cout << "������� " << degree + 1 << " ������������� �������� (�� ������� ������� � �������):\n";
    for (int i = 0; i <= degree; ++i) {
        cin >> coefficients[i];
    }

    if (cin.fail()) {
        throw runtime_error("������ ��� ����� �������������");
    }

    cout << "\n��������� �������: ";
    for (int i = 0; i < coefficients.size(); ++i) {
        if (i > 0) cout << " + ";
        cout << coefficients[i];
        if (i < coefficients.size() - 1) {
            cout << "*x^" << coefficients.size() - 1 - i;
        }
    }
    cout << endl;

    int choice;
    cout << "\n�������� �����:\n"
        << "1. ����� ����������� �������.\n"
        << "2. ����� �������� �������.\n"
        << "3. ����� ���������.\n"
        << "��� �����: ";
    cin >> choice;

    int choice2;
    cout << "\n��������:\n" 
        << "1. ����� ��������.\n"
        << "2. ����� ���������.\n";
    cin >> choice2;
    
    switch (choice)
    {
    case 1:
        if (choice2 != 1 && choice2 != 2) {
            throw invalid_argument("�������� ����� ��� ������ ����������� �������.");
        }
        choice2 == 1 ? bisection_method(coefficients) : bisection_method(coefficients, true);
        break;
    case 2:
        if (choice2 != 1 && choice2 != 2) {
            throw invalid_argument("�������� ����� ��� ������ \"��������\" �������.");
        }
        choice2 == 1 ? golden_section_method(coefficients) : golden_section_method(coefficients, true);
        break;
    case 3:
        if (choice2 != 1 && choice2 != 2) {
            throw invalid_argument("�������� ����� ��� ������ ����� ���������.");
        }
        choice2 == 1 ? fibonacci_method(coefficients) : fibonacci_method(coefficients, true);
        break;
    default:
        throw invalid_argument("�������� ����� ������");
    }
    return 0;
}