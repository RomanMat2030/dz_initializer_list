#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;
template <typename T>
T findMax(const vector<T>& arr) {
    T max = arr[0];
    for (const T& elem : arr) {
        if (elem > max) {
            max = elem;
        }
    }
    return max;
}

template <typename T>
T findMin(const vector<T>& arr) {
    T min = arr[0];
    for (const T& elem : arr) {
        if (elem < min) {
            min = elem;
        }
    }
    return min;
}

template <typename T>
void sortArray(vector<T>& arr) {
    bool swapped;
    for (size_t i = 0; i < arr.size() - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

template <typename T>
bool binarySearch(const vector<T>& arr, const T& value) {
    size_t left = 0;
    size_t right = arr.size() - 1;
    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return true;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

template <typename T>
void replaceElement(vector<T>& arr, size_t index, const T& newValue) {
    if (index < arr.size()) {
        arr[index] = newValue;
    }
}

template <typename T>
vector<T> createVector(initializer_list<T> initList) {
    return vector<T>(initList);
}

int main() {
    vector<int> arr = createVector({ 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 });
    int maxElement = findMax(arr);
    cout << "Max: " << maxElement << endl;

    int minElement = findMin(arr);
    cout << "Min: " << minElement << endl;

    sortArray(arr);
    cout << "Sort: ";
    for (const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    int valueToFind = 5;
    bool found = binarySearch(arr, valueToFind);
    cout << "Element " << valueToFind << (found ? " found" : " not found") << endl;

    size_t indexToReplace = 3;
    int newValue = 10;
    replaceElement(arr, indexToReplace, newValue);
    cout << "Array after replacing an element on an index " << indexToReplace << ": ";
    for (const auto& elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
