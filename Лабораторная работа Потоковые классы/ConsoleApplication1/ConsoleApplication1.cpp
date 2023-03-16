

//Дан текстовый файл.Подсчитать число вхождений в файл букв а, б, с, д.и вывести на экран в виде : а — Na б — Nб и т.д.

//Задание 2.

//Дан файл вещественных чисел.Заменить в нем все элементы на их квадраты.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string path = "file.txt";
    fstream f;
    f.open(path);
    int counta = 0, countb = 0, countc = 0, countd = 0;
    char ch;
    if (!f.is_open()) {
        cout << "Файл не найден" << endl;
    }
    else {
        cout << "Файл успешно открыт" << endl;
        while (!f.eof()) {
            f >> ch;
            if (ch == 'a') {
                counta++;
            }
            else if (ch == 'b') {
                countb++;
            }
            else if (ch == 'c') {
                countc++;
            }
            else {
                countd++;
            }
            if (f.eof()) {
                if (ch == 'a') counta -= 1;
                else if (ch == 'b') countb -= 1;
                else if (ch == 'c') countc -= 1;
                else if (ch == 'd') countd -= 1;
            }
        }
        cout << "a = " << counta << "\n" << "b = " << countb << "\n" << "c = " << countc << "\n" << "d = " << countd << endl;
        f.close();
    }
    string path1 = "file2.txt";
    fstream f2;
    f2.open(path1);
    int count2 = 0;
    char ch2;
    if (!f2.is_open()) {
        cout << "Файл не найден" << endl;
    }
    else {
        cout << "Файл успешно открыт" << endl;
        while (!f2.eof()) {
            f2 >> ch2;
            count2++;
        }  
        count2 -= 1;
        cout << count2 << endl;
    }
    f2.close();
    string path3 = "file2.txt";
    fstream f4;
    f4.open(path3);
    if (f4) {
        const int n = count2;
        int* a = new int[n];
        int v;
        for (int i = 0; i < n; i++) {
            f4 >> a[i];
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            a[i] *= a[i];
            cout << a[i] << " ";
        }
        cout << endl;
        f4.close();
        string path3 = "file2.txt";
        ofstream f3;
        f3.open(path3);
        for (int i = 0; i < n; i++) {
            v = a[i];
            f3 << v << " ";
            cout << v << " ";
        }
        f3.close();
    }
}


