#include <iostream>
#include <list>
#include <iterator>

using namespace std;

list<int> listochek;

int get(list<int> l, int _i){
    list<int>::iterator it = l.begin();
    for(int i = 0; i < _i; i++){
        ++it;
    }
    
    return *it;
}

int main(){
    int size;
    
    cout << "Введите размер двусвязного списка: ";
    cin >> size;
    
    for(int i = 0; i < size; i++){
        int value;
        cout << "Введите " << i + 1 << " узел односвязного списка:";
        cin >> value;
        
        listochek.push_back(value);
    }
    
    int max = 0;
    
    for(int i = 0; i < size - 1; i++){
        if((get(listochek, i) * get(listochek, i + 1)) > max){
            max = get(listochek, i) * get(listochek, i + 1);
        }   
    }
    
    cout << "Максимальное значение среди рядом стоящих чисел: " << max << endl;
    
    return 0;
}
