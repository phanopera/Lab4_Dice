// dice.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

void dice(string param) {
    string getNum="";

    //cout << "param" <<  param << endl;
    int diceCount=1;
    int diceFaces=0;
    int diceAdditor=0;
    bool additorExcists = false;
    int result=0;
    for (int i = 0; i <= param.size(); i++) {

       
        if (param[i] == 'd') {
            diceCount = stoi(getNum);
            getNum = "";
        } 
        if (param[i] == '+') { 

            diceFaces = stoi(getNum);
            getNum = ""; 
            additorExcists = true;
        }else if(!additorExcists&& param[i] == ','|| i== param.size()) {
            diceFaces = stoi(getNum);

            for (int i = 0; i < diceCount; i++) {
                int newValue;
                newValue = rand() % diceFaces+1;
                result += newValue;
                //cout << "dice #" << i << " =" << newValue << endl;
            }
            result += diceAdditor;
            if (diceCount == 1) {
                cout << "dice d" << diceFaces << " --> " << result << endl;
            }
            else {
                cout << diceCount << " dices d" << diceFaces << " --> " << result << endl;
            }
           

            getNum = "";
        }
        if (additorExcists && param[i] == ',') {
            diceAdditor = stoi(getNum);

            getNum = "";
            for (int i = 0; i < diceCount; i++) {
                int newValue;
                newValue = rand() % diceFaces + 1;
                result += newValue;
              //  cout << "dice #" << i << " =" << newValue << endl;
            }
            result += diceAdditor;
            //cout << "dice " << diceCount << "d" << diceFaces<<"+"<< diceAdditor << " result " << result << endl;

            if (diceCount == 1) {
                cout << "dice d" << diceFaces << "+" << diceAdditor << " --> " << result << endl;
            }
            else {
                cout << diceCount << " dices d" << diceFaces << "+" << diceAdditor << " --> " << result << endl;
            }
            diceAdditor = false;
        }
        if (param[i] == ',' || param[i] == 'd') {
            //result = 0;
        }
        else {
            getNum += param[i];
        }
    }
}



int main()
{
    srand(time(NULL));
    dice("2d6+2,3d10");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
