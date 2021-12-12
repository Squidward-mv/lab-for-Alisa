#include <iostream>

using namespace std;

int* init(int* arr, int n){
    
    for(int i = 0; i < n; i++){
        cout << "Введите " << i + 1 << "е число массива\n";
        cin >> arr[i];
    }
    
    cout << "Инициализация массива прошла успешно! \n";
    
    return arr;
}

int maximum(int* arr, int n){
    int max = 0;
    
    for(int i = 0; i < n - 1; i++){
        if(arr[i] * arr[i + 1] > max){
            max = arr[i] * arr[i + 1];
        }
    }
    
    cout << "Максимальное произведение = ";
    
    return max;
}

int main(){
    int n;
    cout << "Введите количество чисел в массиве: ";
    cin >> n;

    int arr[n];
    
    cout << maximum(init(arr, n), n) << endl;
    
    return 0;
}
