#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> testcase1 = {5,2,7,3,5,7,8,23,1};
std::vector<double> testcase2 = {4.1, 2.2, 8.7, 89.1, 111.5};

template <typename Var>
void quickSort(std::vector<Var>& arr, int left, int right) {
    if (left < right) {
        int i = left, j = right;
        Var pivot = std::move(arr[left]);
        while (i < j) {
            while (i < j && pivot <= arr[j]) j--;
            if (i < j) arr[j] = arr[i];
            while (i < j && pivot >= arr[i]) i++;
            if (i < j) arr[i] = arr[j];
            
        }
        arr[left] = pivot;
        quickSort(arr, 0, i - 1);
        quickSort(arr, i + 1, right);
    }
}

int main(int argc, const char** argv) {
    quickSort(testcase1, 0, testcase1.size() - 1);
    quickSort(testcase2, 0, testcase2.size() - 1);
    for (auto item : testcase1) std::cout << item << " ";
    std::cout << std::endl;
    for (auto item : testcase2) std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}
