#include <iostream>

using namespace std;

int *apply_all(int array1 [], int size1, int array2 [], int size2);
void print(int result [], int size);

int main() {
    
    int array1 [] {1,2,3,4,5,6,7,8};
    int array2 [] {10,20,30,29,56};
    
    int size1 {sizeof(array1)/4};
    int size2 {sizeof(array2)/4};
    int result_size {size1 * size2};
    
    cout << size1 << " " << size2;
    
    cout << "\nArray 1: ";
    print(array1, size1);
    
    cout << "\n\nArray 2: ";
    print(array2, size2);
    cout << endl;
    
    int *result = apply_all(array1, size1, array2, size2);
    
    cout << result[0];
    
    cout << "\nResulting array: \n";
    print(result, result_size);
    
    return 0;
}

int *apply_all(int array1 [], int size1, int array2 [], int size2) {
    
    int size {size1 * size2};
    int *result_ptr {nullptr};
    result_ptr = new int [size];
    
    int number {0};
    
    for (int i {0}; i < size2; i++)  {
        for(int j {0}; j < size1; j++)  {
            *(result_ptr + number) = array1[j] * array2[i];
            number++;
        }
    }
    
    return result_ptr;
}

void print(int result [], int size) { // WORKS
    for(int i {0}; i < size; i++)
        cout << result[i] << " ";
}