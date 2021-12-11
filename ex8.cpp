#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string path = "file.txt"; // Сюды путь до файла


int countDigits(){
    char letter;
    int result = 0;
    ifstream file;
    
    file.open(path);

    while(file.get(letter)){
        if(letter >= '0' && letter <= '9'){
            result++;    
        }
    }
    
    file.close();
    
    return result;
}

int main(){

    cout << "Количество цифр в тексте: "  << countDigits() << endl;

    return 0;
}
