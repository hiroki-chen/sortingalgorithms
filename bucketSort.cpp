#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

template <typename Var>
void bucketSort(std::vector<Var>& arr) {
    std::vector<Var> bucket(10000);
    for (Var item : arr) {
        bucket[item] ++;
    }
    int i = 0;
    for (int j = 0; j < bucket.size(); j++) {
        if (bucket[j] != 0) {arr[i++] = j;}
    }
}

int main(int argc, const char** argv) {
    std::default_random_engine e;
    std::uniform_int_distribution<unsigned> list1(50, 100);
    std::uniform_real_distribution<double> list2(100.0, 200.0); //无法对double进行排序。
    std::vector<int> testcase1;
    std::vector<double> testcase2;
    for (int i = 0; i < 20; i++) {
        testcase1.push_back(list1(e));
        testcase2.push_back(list2(e));
    }
    bucketSort(testcase1);
    bucketSort(testcase2);
    for (auto item : testcase1) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    for (auto item : testcase2) {
        std::cout << item << " ";
    }
    return 0;
}