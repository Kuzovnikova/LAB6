#pragma once
#include <algorithm>
#include <iostream>
#include <string>

/// <summary>
/// Шаблонный класс для работы с коллекцией уникальных элементов.
/// </summary>
/// <typeparam name="T">Тип хранимых данных.</typeparam>
template <typename T>
class UniqueList {
private:
    /// <summary>Внутреннее хранилище элементов (массив).</summary>
    std::vector<T> items;

public:
    /// <summary>Добавляет элемент в коллекцию, если он уникален.</summary>
    /// <param name="item">Элемент для добавления.</param>
    void Add(T item) {
        if (!Contains(item)) items.push_back(item);
    }

    /// <summary>Удаляет элемент из коллекции.</summary>
    /// <param name="item">Элемент для удаления.</param>
    void Remove(T item) {
        auto it = std::find(items.begin(), items.end(), item);
        if (it != items.end()) items.erase(it);
    }

    /// <summary>Проверяет, содержится ли элемент в коллекции.</summary>
    /// <param name="item">Искомый элемент.</param>
    /// <returns>True, если элемент найден.</returns>
    bool Contains(T item) const {
        return std::find(items.begin(), items.end(), item) != items.end();
    }

    /// <summary>Выполняет объединение текущей коллекции с другой.</summary>
    /// <param name="other">Вторая коллекция.</param>
    /// <returns>Новая коллекция, содержащая элементы обеих групп.</returns>
    UniqueList Union(const UniqueList& other) {
        UniqueList res = *this;
        for (const auto& x : other.items) res.Add(x);
        return res;
    }

    /// <summary>Находит пересечение двух коллекций.</summary>
    /// <param name="other">Вторая коллекция.</param>
    /// <returns>Коллекция с общими элементами.</returns>
    UniqueList Intersect(const UniqueList& other) {
        UniqueList res;
        for (const auto& x : items) if (other.Contains(x)) res.Add(x);
        return res;
    }

    /// <summary>Вычитает элементы другой коллекции из текущей.</summary>
    /// <param name="other">Коллекция вычитаемых элементов.</param>
    /// <returns>Разность коллекций.</returns>
    UniqueList Except(const UniqueList& other) {
        UniqueList res = *this;
        for (const auto& x : other.items) res.Remove(x);
        return res;
    }

    /// <summary>Выводит содержимое коллекции в консоль.</summary>
    /// <param name="label">Заголовок вывода.</param>
    void Print(std::string label) const {
        std::cout << label << ": ";
        for (const auto& x : items) std::cout << "[" << x << "] ";
        if (items.empty()) std::cout << "пусто";
        std::cout << "\n";
    }
};