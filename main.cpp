#include <iostream>
#include <fstream>
#include "UniqueList.h"
#include "MyDictionary.h"
#include "Points.h"

/// <summary>
/// Главная точка входа в программу.
/// </summary>
int main() {
    setlocale(LC_ALL, "Russian");

    // Тест 1: Уникальные списки
    UniqueList<std::string> groupA;
    groupA.Add("Фильм 1"); groupA.Add("Фильм 2");
    UniqueList<std::string> groupB;
    groupB.Add("Фильм 2"); groupB.Add("Фильм 3");
    groupA.Intersect(groupB).Print("Пересечение");

    // Тест 2: Словарь из файла
    MyDictionary<std::string, std::string> phoneBook;
    std::ofstream fout("data.txt");
    fout << "Иван 8999123\nМария 8999456";
    fout.close();

    std::ifstream fin("data.txt");
    std::string name, phone;
    while (fin >> name >> phone) phoneBook.Add(name, phone);
    phoneBook.PrintAll();

    // Тест 3: Точки
    Point3D p1(0, 0, 0), p2(3, 4, 0);
    std::cout << "Расстояние: " << p1.DistanceTo(p2) << std::endl;

    return 0;
}
