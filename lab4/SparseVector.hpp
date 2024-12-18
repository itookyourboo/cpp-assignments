#include <unordered_map>
#include <cmath>
#include <iostream>

using namespace std;

template <typename T>
class SparseVector {
public:
    std::unordered_map<int, T> data;
    int size;

    SparseVector(int size) : size(size) {}

    void set(int index, T value) {
        if (value != 0) {
            data[index] = value;
        } else {
            data.erase(index);
        }
    }

    T get(int index) const {
        auto it = data.find(index);
        return (it != data.end()) ? it->second : 0;
    }

    SparseVector<T> operator+(const SparseVector<T>& other) {
        SparseVector<T> result(size);
        for (const auto& [index, value] : data) {
            result.set(index, value + other.get(index));
        }
        for (const auto& [index, value] : other.data) {
            result.set(index, value + get(index));
        }
        return result;
    }

    T dot(const SparseVector<T>& other) {
        T result = 0;
        for (const auto& [index, value] : data) {
            result += value * other.get(index);
        }
        return result;
    }

    SparseVector<T> operator+(const T scalar) {
        SparseVector<T> result(size);
        for (const auto& [index, value] : data) {
            result.set(index, value + scalar);
        }
        return result;
    }

    SparseVector<T> operator*(const T scalar) {
        SparseVector<T> result(size);
        for (const auto& [index, value] : data) {
            result.set(index, value * scalar);
        }
        return result;
    }

    SparseVector<T> operator^(const T scalar) {
        SparseVector<T> result(size);
        for (const auto& [index, value] : data) {
            result.set(index, pow(value, scalar));
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const SparseVector<T>& vector) {
        for (size_t i = 0; i < vector.size; i++) {
            os << vector.get(i) << " ";
        }
        os << endl;
        return os;
    }
};
