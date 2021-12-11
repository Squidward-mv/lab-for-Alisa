#include <iostream>

using namespace std;

template<typename T> class Node{
    public:
        Node *pNext;
        T data;
        
        Node(T data = T(), Node *pNext = nullptr){
            this->data = data;
            this->pNext = pNext;
        }
  };

template<typename T> class LinkedList{

public:
    LinkedList();
    ~LinkedList();
    
    void pop_front();
    void push_back(T data);
    void clear();
    void removeAt(int index);
    
    int getSize(){
        return sizeLL;
    }
    
    T& operator[](const int index);
    
private:
  
  int sizeLL;
  Node<T> *head;
};

template<typename T>
LinkedList<T>::LinkedList(){

    sizeLL = 0;
    head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList(){
    cout << "\n\nВызвался деструктор";
    clear();
}

template<typename T>
void LinkedList<T>::push_back(T data){

    if(head == nullptr){
        head = new Node<T>(data);
    }
    else{
        Node<T> *current = this->head;
        
        while(current->pNext != nullptr){
            current = current->pNext;
        }
        
        current->pNext = new Node<T>(data);
    }
    
    sizeLL++;
}

template<typename T>
T& LinkedList<T>::operator[](const int index){
    int counter = 0;
    Node<T> *current = this->head;
    
    while(current != nullptr){
        if(counter == index){
            return current->data;
        }
        
        current = current->pNext;
        counter++;
    }
    
    return current->data;
}

template<typename T>
void LinkedList<T>::pop_front(){
    Node<T> *temp = head;
    
    head = head->pNext;
    
    delete temp;
    
    sizeLL--;
}

template<typename T>
void LinkedList<T>::clear(){
    while(sizeLL){
        pop_front();
    }
}

template<typename T>
void LinkedList<T>::removeAt(int index){
        if(index == 0){
            pop_front();
        }
        else{
            Node<T> *prev = this->head;
            for(int i = 0; i < index - 1; i++){
                prev = prev->pNext;
            }
        
            Node<T> *toDelete = prev->pNext;
        
            prev->pNext = toDelete->pNext;
        
            delete toDelete;
            sizeLL--;
        }
}

int main(){
    int size;
    
    cout << "Введите размер односвязного списка: ";
    cin >> size;
    
    LinkedList<int> list;
    
    for(int i = 0; i < size; i++){
        int value;
        cout << "Введите " << i + 1 << " узел односвязного списка:";
        cin >> value;
        
        list.push_back(value);
    }
    
    cout << "Всего значений: " << list.getSize() << endl;
    
    for(int i = 0; i < list.getSize(); i++){
        cout << i + 1 << "й узел = " << list[i] << endl;
    }
    
    cout << "Удалив все значения кратные трем получаем следующую структуру" << endl;

    for(int i = 0; i < list.getSize(); i++){
        if(list[i] % 3 == 0){
            list.removeAt(i);
            i--;
        }
    }

    cout << "Всего значений: " << list.getSize() << endl;
    
    for(int i = 0; i < list.getSize(); i++){
        cout << i + 1 << "й узел = " << list[i] << endl;
    }
    
    return 0;
}