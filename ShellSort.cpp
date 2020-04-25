#include <iostream>
#include <vector>
#include <random>

/*
@param arr
@param leftPos, leftEnd
@param rightPos, rightend
@param gap
*/

template <typename Var>
void ShellSort(std::vector<Var>& arr) {
    for (int gap = arr.size() >> 2; gap > 0; gap >>= 1) {
        for (int i = gap; i < arr.size(); i++) {
            Var tmp = std::move(arr[i]);
            int j;
            for (j = i; j >= gap && tmp < arr[j - gap]; j -= gap) {arr[j] = std::move(arr[j - gap]);}
            arr[j] = std::move(tmp);
        }
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

    ShellSort(testcase1);
    ShellSort(testcase2);
    for (auto item : testcase1) std::cout << item << " ";
    std::cout << std::endl;
    for (auto item : testcase2) std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}