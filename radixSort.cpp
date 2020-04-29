#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

template <typename Var>
void radixSort(std::vector<Var>& arr, int len) {
    std::vector<std::vector<Var>> buckets(10000);
    for (int pos = len - 1; pos >= 0; pos--) {
        for (Var& item : arr) {buckets[item[pos]].push_back(std::move(item));}
            int i = 0;
            for (auto& thisBucket : buckets) {
                for (Var& item : thisBucket) {
                    arr[i++] = std::move(item);
                }
                    thisBucket.clear();
            }
    }
}

int main(int argc, const char** argv) {
    std::default_random_engine e;
    std::uniform_int_distribution<int> list1(100, 999);
    std::vector<std::string> testcase;
    for (int i = 0; i < 20; i++) {testcase.push_back(std::to_string(list1(e)));}
    radixSort(testcase, 3);
    for (auto i : testcase) {std::cout << i << " ";}
    return 0;
}
