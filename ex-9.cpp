#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string path = "file.txt";

struct student{
    string lastName;
    string course;
};

int main(){
    ifstream file;
    file.open(path);
    
    int n;
    cout << "Введите количество студентов: ";
    cin >> n;
    
    student students[n];
    
    string letter;
    int i = 0;
    
    while(getline(file, letter)){
        if(letter >= "1" && letter <= "9"){
            students[i].course = letter;
            cout << letter << endl;
        }
        else{
            students[i].lastName = letter;
            cout << letter << endl;
        }
        if(!students[i].lastName.empty() && !students[i].course.empty()){
            i++;
        }
    }
    
    file.close();
    
    string hypeLastName = " ";
    int countStudents = 0;

    for(int i = 0; i < n; i++){
        int min = 1;
        for(int j = 1; j < n; j++){
            if((students[j].course == "1") && (students[j].lastName == students[j - 1].lastName)){
                min++;
                hypeLastName = students[j].lastName;
            }
        }
        if(min > countStudents){
            countStudents = min;
        }
    }
    
    cout << "Самая популярная фамилия на первом курсе: " << hypeLastName << endl;
    
    string num;
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
