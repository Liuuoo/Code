#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 插入排序
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 选择排序
void selectionSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// 冒泡排序
void bubbleSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 快速排序
void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--;
        if (i < j) arr[i++] = arr[j];
        while (i < j && arr[i] <= pivot) i++;
        if (i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

// 堆排序辅助函数
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 堆排序
void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 希尔排序
void shellSort(vector<int>& arr) {
    for (int gap = arr.size() / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < arr.size(); i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 随机数生成
void generateRandomNumbers(vector<int>& arr, int size, int range) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range;
    }
}

// 输出数组
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    const int size = 30;
    const int range = 100;
    vector<int> data(size);

    // 生成随机数
    generateRandomNumbers(data, size, range);
    cout << "随机数组: ";
    printArray(data);

    // 插入排序
    vector<int> insertionData = data;
    insertionSort(insertionData);
    cout << "插入排序: ";
    printArray(insertionData);

    // 选择排序
    vector<int> selectionData = data;
    selectionSort(selectionData);
    cout << "选择排序: ";
    printArray(selectionData);

    // 冒泡排序
    vector<int> bubbleData = data;
    bubbleSort(bubbleData);
    cout << "冒泡排序: ";
    printArray(bubbleData);

    // 快速排序
    vector<int> quickData = data;
    quickSort(quickData, 0, quickData.size() - 1);
    cout << "快速排序: ";
    printArray(quickData);

    // 堆排序
    vector<int> heapData = data;
    heapSort(heapData);
    cout << "堆排序: ";
    printArray(heapData);

    // 希尔排序
    vector<int> shellData = data;
    shellSort(shellData);
    cout << "希尔排序: ";
    printArray(shellData);

    return 0;
}
