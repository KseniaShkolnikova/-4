
#include <iostream>
using namespace std;
#include <vector>
#include <random>
#include <Windows.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "");
    cout << "----------------Измененитель слов----------------\n";
    string slovonavvod;
    const string glasnie("eyuioaуеыаоэяию");
    const string soglasnie("qwrtpsdfghjklzxcvbnmйцкнгшщзхфвпрлджчсмтб");
    int otvet;
    while (true)
    {
        cout << "\n Введите свое слово: ";
        cin >> slovonavvod;
        int dlinslova = slovonavvod.length();
        vector<char> slovo(dlinslova);
        cout << "\n----------------------Меню----------------------\n Что вы хотите сделать со своим словом?:\n  1. Вывести слово задом наперед.\n  2. Вывести слово без гласных.\n  3. Вывести слово без согласных.\n  4. Рандомно поставить буквы слова.\n  5. Выйти\n";
        cin >> otvet;
        switch (otvet)
        {
        case(1):
            reverse(slovonavvod.begin(), slovonavvod.end());
            break;
        case(2):
            slovonavvod.erase(
                remove_if(slovonavvod.begin(), slovonavvod.end(), [&glasnie](char i) {
                    return glasnie.find(i) != string::npos;
                    }),
                slovonavvod.end()
            );
            break;
        case(3):
            slovonavvod.erase(
                remove_if(slovonavvod.begin(), slovonavvod.end(), [&soglasnie](char j) {
                    return soglasnie.find(j) != string::npos;
                    }),
                slovonavvod.end()
            );
            break;
        case(4):
            random_device random;
            shuffle(slovonavvod.begin(), slovonavvod.end(), random);
            break;
        case (5):
            cout << "----------------------Пока----------------------";
            exit(0);
            break;
        default:
            cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!Нужно вводить вариант ответа!!!!!!!!!!!!!!!!!!!!!!!!\n";
            exit(0);
            break;
        }
        cout << " Ответ: " + slovonavvod + "\n------------------------------------------------\n";
    }
}