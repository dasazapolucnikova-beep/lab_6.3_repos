#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Прототипи звичайних функцій
void Create(int* a, const int size, const int Low, const int High);
void Print(const int* a, const int size);
int Min(const int* a, const int size);

// Прототипи шаблонів функцій
template <typename T>
void CreateTemplate(T* a, const int size, const T Low, const T High);

template <typename T>
void PrintTemplate(const T* a, const int size);

template <typename T>
T MinTemplate(const T* a, const int size);

int main()
{
    // Виправлено виклик time(nullptr)
    srand((unsigned)time(nullptr));
    const int n = 10;

    // -------------------------------------------------------------
    // 1. Обробка за допомогою звичайних функцій (для типів int)
    // -------------------------------------------------------------
    cout << "Ordinary functions " << endl;
    int* a = new int[n];

    Create(a, n, -10, 10);
    cout << "a = ";
    Print(a, n);

    int min_val = Min(a, n);
    cout << "Min(a, n) = " << min_val << endl << endl;

    // -------------------------------------------------------------
    // 2. Обробка за допомогою шаблонів функцій (double)
    // -------------------------------------------------------------
    cout << "Function templates " << endl;
    double* b = new double[n];

    CreateTemplate(b, n, -10.0, 10.0);
    cout << "b = ";
    PrintTemplate(b, n);

    double min_val_b = MinTemplate(b, n);
    cout << "MinTemplate(b, n) = " << min_val_b << endl;

    // Звільнення пам'яті
    delete[] a;
    delete[] b;

    return 0;
}

// Формування масиву випадковими числами
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Форматне виведення масиву у рядок
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

// Обчислення мінімального елемента
int Min(const int* a, const int size)
{
    if (size <= 0) return 0;
    int min = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

// --- ШАБЛОНИ ФУНКЦІЙ ---

template <typename T>
void CreateTemplate(T* a, const int size, const T Low, const T High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + (High - Low) * (rand() / (double)RAND_MAX);
}

template <typename T>
void PrintTemplate(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(8) << setprecision(2) << fixed << a[i];
    cout << endl;
}

template <typename T>
T MinTemplate(const T* a, const int size)
{
    if (size <= 0) return T();
    T min = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}