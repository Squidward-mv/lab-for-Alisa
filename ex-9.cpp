#include <iostream>
#include <string>

using namespace std;

struct student{
    string lastName;
    int course;
};

int main(){
    int n;
    cout << "Введите количество студентов: ";
    cin >> n;
    
    student students[n];
    
    for(int i = 0; i < n; i++){
        cout << "Введите фамилию студента: ";
        cin >> students[i].lastName;
        cout << "Введите курс студента: ";
        cin >> students[i].course;
    }
    
    string hypeLastName = " ";
    int countStudents = 0;

    for(int i = 0; i < n; i++){
        int min = 1;
        for(int j = 1; j < n; j++){
            if((students[j].course == 1) && (students[j].lastName == students[j - 1].lastName)){
                min++;
                hypeLastName = students[j].lastName;
            }
        }
        if(min > countStudents){
            countStudents = min;
        }
    }
    
    cout << "Самая популярная фамилия на первом курсе: " << hypeLastName << endl;
    
    int num;
    cout << "Введите интересующий вас курс: ";
    cin >> num;
    
     for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            if(students[j].course == num){
                student temp = students[j - 1];
                students[j - 1] = students[j];
                students[j] = temp;
            } 
        }
    }
    
    cout << "Реузльтат сортировки: \n" << endl;

    for(int i = 0; i < n; i++){
        cout << "________________________" << endl;
        cout << "Фамилия: " << students[i].lastName << "\nКурс: " << students[i].course << endl;
    }

    return 0;
}
