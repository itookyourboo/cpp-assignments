#include <iostream>
#include <vector>
#include <list>
#include "MyNumber.hpp"


MyNumber generateMyNumber(int num) {
    return MyNumber(num, "MyNumber" + std::to_string(num));
}


int generateRandomInt(std::default_random_engine &gen, int from, int to) {
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(gen);
}


int main() {
    std::default_random_engine generator;

    // 1. Создание вектора v1 со случайными элементами
    int v1Size = generateRandomInt(generator, 500, 1000);
    std::vector<MyNumber> v1(v1Size);
    std::generate(v1.begin(), v1.end(), [&]() -> MyNumber {
        int num = generateRandomInt(generator, 1, 1000);
        return generateMyNumber(num);
    });

    // 2. Создание вектора v2
    size_t b = 10, e = 172;
    if (b >= e || e > v1.size()) {
        return 1;
    }
    auto v2 = std::vector<MyNumber>(v1.begin() + b, v1.begin() + e);

    // 3. Формирование списка list1 (n=20-40 наибольших из v1)
    int n = generateRandomInt(generator, 20, 40);
    std::list<MyNumber> list1(n);
    std::sort(v1.rbegin(), v1.rend());
    std::copy(v1.begin(), v1.begin() + n, list1.begin());

    // 4. Формирование списка list2 (n наименьших из v2)
    std::list<MyNumber> list2(n);
    std::sort(v2.begin(), v2.end());
    std::copy(v2.begin(), v2.begin() + n, list2.begin());

    // 5. Удаление из векторов v1 и v2 перемещенных элементов
    v1.erase(v1.begin(), v1.begin() + n);
    v2.erase(v2.begin(), v2.begin() + n);

    // 6. Найти элемент со средним значением и поделить по нему список (большие - в начале)
    // list1 уже отсортирован по убыванию, поэтому ничего делать не нужно
    // В ином случае нужно было бы делать сортировку по lhs.val > average && rhs.val <= average
    
    // 7. Удалить из списка list2 все нечётные элементы
    list2.remove_if([&](const MyNumber& myNumber) {
        return myNumber.getValue() % 2 == 1;
    });

    // 8. Создать вектор v3 (пересечение v1 и v2)
    std::vector<MyNumber> v3;
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    std::set_intersection(
        v1.begin(), v1.end(), 
        v2.begin(), v2.end(), 
        std::back_inserter(v3)
    );

    // 9. Формирование списка list3 из пар списков list1 и list2 с приведением к одному размеру
    int delta = list1.size() - list2.size();
    auto &greatest = delta > 0 ? list1 : list2;
    auto end = greatest.begin();
    std::advance(end, delta);
    greatest.erase(greatest.begin(), end);
    
    std::list<std::pair<MyNumber, MyNumber>> list3;
    std::transform(
        list1.begin(), list1.end(), 
        list2.begin(), std::back_inserter(list3), 
        [](const MyNumber &a, const MyNumber &b) {
            return std::make_pair(a, b);
        }
    );

    // 10. То же самое, только для v1 и v2 без приведения к одному размеру
    size_t minSize = std::min(v1.size(), v2.size());
    std::vector<std::pair<MyNumber, MyNumber>> v4(minSize);
    std::transform(
        v1.begin(), v1.begin() + minSize,
        v2.begin(), std::back_inserter(v4),
        [](const MyNumber &a, const MyNumber &b) {
            return std::make_pair(a, b);
        }
    );

    return 0;
}