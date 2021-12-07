#include <iostream>
#include <cstring>
#include <string>
 
using namespace std;

bool checker(const char * s, int counter = 0, int counterSquare = 0, int counterFigure = 0){
    if ((counter < 0) || (counterSquare < 0) || (counterFigure < 0)) return false;

    for( ; *s; ++s)
        switch(*s){
            case '(': return checker(s + 1, counter + 1, counterSquare, counterFigure);
            case ')': return checker(s + 1, counter - 1, counterSquare, counterFigure);
            case '[': return checker(s + 1, counter, counterSquare + 1, counterFigure);
            case ']': return checker(s + 1, counter, counterSquare - 1, counterFigure);
            case '{': return checker(s + 1, counter, counterSquare, counterFigure + 1);
            case '}': return checker(s + 1, counter, counterSquare, counterFigure - 1);
        }
        
    return ((counter || counterSquare || counterSquare) == 0);
}

int main(){
    string str;
    cout << "Введите выражение: ";
    cin >> str; 
    
    const char * strBuf = str.c_str();
    
    if (checker(strBuf)){  // сюда вписываешь интересующее выражение
        cout << "Скобки расставлены верно" << endl;
    }
    else {
        cout << "Скобки расставлены неверно" << endl;
    }
        
    return 0;
}
