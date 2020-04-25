#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

template <typename Var>
void percDown(std::vector <Var>& arr, int start, int size) {
    int child;
    Var tmp = arr[start]; //Root

    for (tmp = std::move(arr[start]); 2 * start + 1 < size; start = child) {
        child = 2 * start + 1; //Let child be its left child.
        if (child != size - 1 && arr[child] < arr[child + 1]) {child++;} //We choose the maximum as an object of comparison, so we can gaurantee that root is always bigger than its children.
        if (tmp < arr[child]) {arr[start] = std::move(arr[child]);} //The position is not correct, try to find another one.
        else {break;} //Found it.
    }
    arr[start] = std::move(tmp);
}

template <typename Var>
void heapSort(std::vector <Var>& arr) {
    for (int i = arr.size() / 2 - 1; i >= 0; i--) {percDown(arr, i, arr.size());} //build a maxHeap. We will start with the first non-leaf node.
    for (int j = arr.size() - 1; j >= 0; j--) {
        std::swap(arr[0], arr[j]); //Lazy delete process, we will put the first one into the last position.
        percDown(arr, 0, j); //Deleting will cause the whole structure messy, so we should do percDown.
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
    heapSort(testcase1);
    heapSort(testcase2);
    for (auto item : testcase1) std::cout << item << " ";
    std::cout << std::endl;
    for (auto item : testcase2) std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}