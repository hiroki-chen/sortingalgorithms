#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
@param arr
@param ans as answer
@param leftPos the left part of array: start index
@param rightPos the right part of array: start index
@param rightEnd end index of right part
@param leftEnd end index of left part
*/

template <typename Var>
void merge(vector<Var>& arr, vector<Var>& ans, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int nums = rightEnd - leftPos + 1; //element number.

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (arr[leftPos] <= arr[rightPos]) {ans[tmpPos++] = move(arr[leftPos++]);}
        else {ans[tmpPos++] = move(arr[rightPos++]);}
    }
    while (leftPos <= leftEnd) {
        ans[tmpPos++] = move(arr[leftPos++]);
    }
    while (rightPos <= rightEnd) {
        ans[tmpPos++] = move(arr[rightPos++]);
    }
    for (int i = 0; i < nums; i++, --rightEnd) {arr[rightEnd] = move(ans[rightEnd]);} //Copy back.
} 

template <typename Var>
void mergeSort(vector<Var>& arr, vector<Var>& ans, int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;
        mergeSort(arr, ans, left, mid);
        mergeSort(arr, ans, mid + 1, right);
        merge(arr, ans, left, mid + 1, right);
    }
}

std::vector<int> testcase1 = {5,2,7,3,5,7,8,23,1};
std::vector<double> testcase2 = {4.1, 2.2, 8.7, 89.1, 111.5};

int main(int argc, const char** argv) {
    vector<int> ans1(testcase1.size());
    vector<double> ans2(testcase2.size());
    mergeSort(testcase1, ans1, 0, testcase1.size() - 1);
    mergeSort(testcase2, ans2, 0, testcase2.size() - 1);
    for (auto item : testcase1) std::cout << item << " ";
    std::cout << std::endl;
    for (auto item : testcase2) std::cout << item << " ";
    std::cout << std::endl;
    return 0;
}