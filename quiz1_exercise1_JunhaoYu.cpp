#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left + rand() % (right - left + 1)];
    int i = left;
    int j = right;
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int index = partition(arr, left, right);
    quicksort(arr, left, index - 1);
    quicksort(arr, index, right);
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    quicksort(arr, 0, arr.size() - 1);
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}