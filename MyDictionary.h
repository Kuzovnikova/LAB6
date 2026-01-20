#pragma once
#include <iostream>

/// <summary>
/// Шаблонный класс, реализующий функционал словаря (ключ-значение).
/// </summary>
template <typename K, typename V>
class MyDictionary {
private:
    /// <summary>Структура для хранения пары ключ-значение.</summary>
    struct Node { K key; V value; };
    std::vector<Node> nodes;

public:
    /// <summary>Добавляет пару в словарь. Если ключ существует, обновляет значение.</summary>
    /// <param name="key">Уникальный ключ.</param>
    /// <param name="value">Значение.</param>
    void Add(K key, V value) {
        for (auto& n : nodes) {
            if (n.key == key) {
                n.value = value;
                return;
            }
        }
        nodes.push_back({ key, value });
    }

    /// <summary>Удаляет элемент из словаря по ключу.</summary>
    /// <param name="key">Ключ для удаления.</param>
    void Remove(K key) {
        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            if (it->key == key) {
                nodes.erase(it);
                return;
            }
        }
    }

    /// <summary>Ищет значение по ключу.</summary>
    /// <param name="key">Ключ.</param>
    /// <returns>Указатель на значение или nullptr.</returns>
    V* Get(K key) {
        for (auto& n : nodes) if (n.key == key) return &n.value;
        return nullptr;
    }

    /// <summary>Отображает все элементы словаря.</summary>
    void PrintAll() const {
        for (const auto& n : nodes)
            std::cout << "Ключ: " << n.key << " | Значение: " << n.value << "\n";
    }
};