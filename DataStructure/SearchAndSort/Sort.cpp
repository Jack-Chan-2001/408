/**
 * 排序的 C++ 实现
 * 用了容器来做，排序算法是一样的
 * 等有空了或者复试的时候再换成C语言实现一次
 */
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void initVec(vector<int>& v, int length) {
    srand(time(nullptr));
    for (int i = 0; i < length; ++i) {
        v.push_back(rand() % 100);
    }
}

ostream& operator<<(ostream& out, const vector<int>& v) {
    for (auto i : v) {
        out << setiosflags(ios::right) << setw(3) << i;
    }
    return out;
}

void BubbleSort(vector<int>& v) {
    bool flag; // 优化，判断提前结束
    for (int i = 0; i < v.size() - 1; ++i) {
        flag = false;
        for (int j = v.size() - 1; j > i; --j) {
            if (v[j] < v[j - 1]) {
                swap(v[j], v[j - 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

/**
 * 快排辅助函数
 * 返回中轴位置
 * 交换法
 */
int Partition1(vector<int>& v, int left, int right) {
    int k, i;
    for (k = left, i = left; i < right; ++i) {
        if (v[i] < v[right]) {
            swap(v[k], v[i]);
            ++k;
        }
    }
    swap(v[right], v[k]);
    return k;
}

/**
 * 挖坑法
 */
int Partition2(vector<int>& vec, int left, int right) {
    int temp = vec[left];
    while (left < right) {
        while (left < right && temp <= vec[right]) {
            right--;
        }
        vec[left] = vec[right];
        while (left < right && temp >= vec[left]) {
            left++;
        }
        vec[right] = vec[left];
    }
    vec[left] = temp;
    return left;
}

void QuickSort(vector<int>& v, int low, int high) {
    if (low < high) {
        int pivotPos = Partition2(v, low, high);
        QuickSort(v, low, pivotPos - 1);
        QuickSort(v, pivotPos + 1, high);
    }
}

void InsertSort(vector<int>& v) {
    int i, j;
    for (i = 1; i < v.size(); ++i) {
        int temp = v[i];
        j = i;
        while (j > 0 && temp < v[j - 1]) {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = temp;
    }
}

void MidInsertSort(vector<int>& v) {
    int low, high, i, j;
    for (i = 1; i < v.size(); ++i) {
        low = 0;
        high = i - 1;
        int temp = v[i];
        while (low <= high) {
            int mid = (low + high) / 2;
            if (temp < v[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (j = i - 1; j > high; --j) {
            v[j + 1] = v[j];
        }
        v[high + 1] = temp;
    }
}

void ShellSort(vector<int>& v) {
    int dk, i, j;
    for (dk = v.size() / 2; dk >= 1; dk /= 2) {
        for (i = dk; i < v.size();++i) {
            if (v[i] < v[i - dk]) {
                int temp = v[i];
                for (j = i - dk; j >= 0 && v[j] > temp;j = j - dk) {
                    v[j + dk] = v[j];
                }
                v[j + dk] = temp;
            }
        }
    }
}

void SelectSort(vector<int>& v) {
    int min_idx;
    for (int i = 0; i < v.size() - 1; ++i) {
        min_idx = i;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        if (i != min_idx) {
            swap(v[i], v[min_idx]);
        }
    }
}

void PercDown(vector<int>& v, int i, int N) {
    int temp = v[i];
    int child_idx;
    while (i < N / 2) {
        child_idx = 2 * i + 1;
        if (child_idx + 1 < N && v[child_idx + 1] > v[child_idx]) {
            child_idx++;
        }
        if (v[child_idx] > temp) {
            v[i] = v[child_idx];
            i = child_idx;
        } else {
            break;
        }
        v[i] = temp;
    }
}

void HeapSort(vector<int>& v) {
    // 建堆
    for (int i = v.size() / 2 - 1; i >= 0; --i) {
        PercDown(v, i, v.size());
    }

    // 调整大根堆
    for (int i = v.size() - 1; i > 0; i--) {
        swap(v[i], v[0]);
        PercDown(v, 0, i);
    }
}

void Merge(vector<int>& v, int low, int mid, int high) {
    int i, j, k;
    const vector<int> temp(v); // 创建辅助数组
    for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++) { // 合并两个有序数组
        if (temp[i] < temp[j]) {
            v[k] = temp[i++];
        } else {
            v[k] = temp[j++];
        }
    }
    while (i <= mid) {
        v[k++] = temp[i++];
    }
    while (j <= high) {
        v[k++] = temp[j++];
    }
}

void MergeSort(vector<int>& v, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(v, low, mid);
        MergeSort(v, mid + 1, high);
        Merge(v, low, mid, high);
    }
}


int main() {
    vector<int> vecInt;
    initVec(vecInt, 10);
    cout << vecInt << endl;
    // BubbleSort(vecInt);
    // QuickSort(vecInt, 0, 9);
    // InsertSort(vecInt);
    // MidInsertSort(vecInt);
    // ShellSort(vecInt);
    // SelectSort(vecInt);
    // HeapSort(vecInt);
    MergeSort(vecInt, 0, 9);
    cout << vecInt << endl;
    return 0;
}
