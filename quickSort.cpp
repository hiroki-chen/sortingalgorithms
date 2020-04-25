#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

template <typename Var>
void quickSort(std::vector<Var>& arr, int left, int right) {
    if (left < right) {
        int i = left, j = right;
        Var pivot = std::move(arr[left]);
        while (i < j) {
            while (i < j && pivot <= arr[j]) j--;
            if (i < j) {arr[i++] = arr[j];}
            while (i < j && pivot >= arr[i]) i++;
            if (i < j) {arr[j--] = arr[i];}
            
        }
        arr[i] = pivot;
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
}

int main(int argc, const char** argv) {
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> list1(0, 100);
    std::uniform_real_distribution<double> list2(0.0, 100.0);
    std::vector<int> testcase1;
    std::vector<double> testcase2;
    for (int i = 0; i < 20; i++) {
        testcase1.push_back(list1(e));
        testcase2.push_back(list2(e));
    }

    quickSort(testcase1, 0, testcase1.size() - 1);
    quickSort(testcase2, 0, testcase2.size() - 1);
    for (auto item : testcase1) std::cout << item << " ";
    std::cout << std::endl;
    for (auto item : testcase2) std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}
