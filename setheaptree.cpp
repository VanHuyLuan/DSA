#include <iostream>

// Hàm để hoán đổi hai phần tử trong mảng
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm để biến một mảng thành cây heap
void heapify(int arr[], int n, int i) {
    int largest = i; // Khởi tạo largest là nút cha
    int left = 2 * i + 1; // Vị trí của nút con trái
    int right = 2 * i + 2; // Vị trí của nút con phải

    // So sánh nút cha với nút con trái và nút con phải
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Nếu largest không phải là nút cha, thực hiện hoán đổi và gọi đệ quy để tiếp tục heapify
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Hàm để sắp xếp một mảng bằng cách sử dụng cây heap
void buildHeap(int arr[], int n) {
    // Bắt đầu từ nút cuối cùng có thể là nút cha (n/2 - 1) và thực hiện heapify cho từng nút cha
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Hàm để in mảng
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Mảng trước khi thiết lập cây heap: ";
    printArray(arr, n);

    buildHeap(arr, n);

    std::cout << "Mảng sau khi thiết lập cây heap: ";
    printArray(arr, n);

    return 0;
}
