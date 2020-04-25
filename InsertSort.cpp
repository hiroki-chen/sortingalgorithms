#include <iostream>
#include <vector>
#include <random>

template <typename Var>
void insertSort(std::vector<Var>& arr) {
    for (int i = 1; i < arr.size(); i++) { //i moves towards right.
        Var tmp = std::move(arr[i]);
        int j;
        for (j = i; j >= 1 && tmp < arr[j - 1]; j--) {arr[j] = std::move(arr[j - 1]);}
        arr[j] = std::move(tmp);
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

    insertSort(testcase1);
    insertSort(testcase2);
    for (auto item : testcase1) std::cout << item << " ";
    std::cout << std::endl;
    for (auto item : testcase2) std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}