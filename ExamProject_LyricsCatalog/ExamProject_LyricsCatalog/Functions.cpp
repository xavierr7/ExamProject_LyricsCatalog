#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "Header.h"
using std::string;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;

/// <summary>
/// проверяет на корректность введёное число.
/// диапазон от нуля до числа заданного аргументом функции + 1
/// </summary>
/// <param name="endOfRange">конец диапазона</param>
/// <returns> корректно введёное пользователем число</returns>
int CheckForCorrect(int endOfRange)
{
	int tmp;
	while (true)
	{
		cin >> tmp;
		cin.ignore();
		if (tmp > 0 && tmp < endOfRange)
		{
			return tmp;
		}
		else
		{
			cout << "Введите корректный номер пункта!";
			system("pause");
			system("cls");
		}
	}
}
/// <summary>
/// выводит на экран главное меню и просит пользователя выбрать пункт
/// </summary>
/// <returns>введёное пользователем число для выбора пункта меню</returns>
int MainMenu()
{
    system("cls");
    cout << "   |                         МЕНЮ                           |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No1|            ВЫВЕСТИ СПИСОК ВСЕХ ПЕСЕН               |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No2|         ДОБАВИТЬ НОВУЮ ПЕСНЮ И ЕЁ ТЕКСТ            |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No3|           УДАЛИТЬ ТЕКСТ ОДНОЙ ИЗ ПЕСЕН             |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No4|          ИЗМЕНЕНИЕ ТЕКСТА ОДНОЙ ИЗ ПЕСЕН           |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No5|          СОХРАНЕНИЕ КАТАЛОГА ПЕСЕН В ФАЙЛ          |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No6|   ПОИСК И ОТОБРАЖЕНИЕ ВСЕХ ПЕСЕН ОДНОГО АВТОРА     |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No7|               ПОИСК ПЕСЕН ПО СЛОВУ                 |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No8|                     ВЫХОД                          |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |               ВЫБЕРИТЕ НУЖНЫЙ ПУНКТ МЕНЮ:              |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "                                ";
    int option = CheckForCorrect(9);
    system("cls");
    return option;
}
/// <summary>
/// выводит на экран меню для выбора способа внесения песни в список и просит выбрать пункт
/// </summary>
/// <returns>введёное пользователем число для выбора пункта меню</returns>
int InputTextMenu()
{
    cout << "   ----------------------------------------------------------\n";
    cout << "   |                           МЕНЮ                         |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No1|             ВВОД ТЕКСТА С КЛАВИАТУРЫ               |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No2|             ЗАГРУЗИТЬ ТЕКСТ ИЗ ФАЙЛА               |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No3|                     ВЫХОД                          |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "                                ";
    int option = CheckForCorrect(4);
    system("cls");
    return option;
}
/// <summary>
/// выводит на экран меню для выбора способа изменения текста песни и просит выбрать пункт
/// </summary>
/// <returns>введёное пользователем число для выбора пункта меню</returns>
int ChangeTextMenu()
{
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No1|                ИЗМЕНИТЬ ВЕСЬ ТЕКСТ                 |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No2|     ДОБАВИТЬ В КОНЕЦ ТЕКСТА НЕДОСТАЮЩИЕ СТРОКИ     |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No3|                     ВЫХОД                          |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "                                ";
    int option = CheckForCorrect(4);
    system("cls");
    return option;
}
/// <summary>
/// Выводит на экран список песен, а также предоставляет возможность выбрать песню для просмотра её текста
/// </summary>
/// <param name="obj">указатель на массив структур</param>
/// <param name="countOfAllSongs">текущее количество песен</param>
/// <returns></returns>
int ShowListOfSongs(const Songs* obj, int countOfAllSongs)
{
    cout << "   --------------------------------------------------------------\n";
    cout << "   |                       СПИСОК ВСЕХ ПЕСЕН                    |\n";
    cout << "   --------------------------------------------------------------\n";
    int tmpCount = 1;
    for (size_t i = 0; i < countOfAllSongs; i++)
    {
        cout << "     " << tmpCount << " | " << "\"" << obj[i].nameOfSong << "\" ~ " << obj[i].songwriter_sName;
        if (obj[i].yearIsKnown)
        {
            cout << " ~ " << obj[i].yearOfRelease << endl;
        }
        else
        {
            cout << endl;
        }
        ++tmpCount;
    }
    return tmpCount;
}
/// <summary>
/// функция для ввода текста с клавиатуры пока пользователь не захочет прекратить ввод
/// </summary>
/// <param name="obj">указатель на массив структур</param>
/// <param name="song">индекс определённой структуры или текущее количество песен</param>
void InputText(Songs* obj, int song)
{
    int countOfStrings = 1;
    system("cls");
    cout << "Нажмите \"Enter\" и начинайте ввод строчки\n";
    system("pause");
    system("cls");
    for (size_t i = 0; i < countOfStrings; i++)
    {
        string line;
        getline(cin, line);
        cout << "1 - ввести следующую строчку\n";
        cout << "2 - это весь текст, вернуться в главное меню\n";
        int tmpOption = CheckForCorrect(3);
        system("cls");
        if (tmpOption == 1)
        {
            obj[song - 1].lyricOfSong += line + "\n";

            cout << obj[song - 1].lyricOfSong;

            ++countOfStrings;
        }
        else
        {
            obj[song - 1].lyricOfSong += line + "\n";
            cout << "Готово!\n";
            system("pause");
            system("cls");
            break;
        }
    }
}
/// <summary>
/// функция для добавления структуры песни с вводом текста с клавиатуры
/// </summary>
/// <param name="obj">указатель на массив структур</param>
/// <param name="countOfAllSongs">текущее количество песен</param>
/// <returns>указатель на новый массив структур</returns>
Songs* InputTextFromKeyboard(Songs* obj, int& countOfAllSongs)
{
    countOfAllSongs++;
    obj = AddSong(obj, countOfAllSongs);
    cout << "Введите имя автора: ";
    getline(cin, obj[countOfAllSongs - 1].songwriter_sName);
    cout << "Введите название песни: ";
    getline(cin, obj[countOfAllSongs - 1].nameOfSong);
    cout << "\n Известен ли вам год выпуска этой песни?\n1.) Да\n2.) Нет\n";
    int option = CheckForCorrect(3);
    if (option == 1)
    {
        cout << "Введите его: \n";
        obj[countOfAllSongs - 1].yearIsKnown = true;
        cin >> obj[countOfAllSongs - 1].yearOfRelease;
        cin.ignore();
        system("cls");
    }
    else
    {
        obj[countOfAllSongs - 1].yearIsKnown = false;
        system("cls");
    }

    InputText(obj, countOfAllSongs);

    return obj;
}
/// <summary>
/// внесение либо одной песни либо целого каталога песен из файла
/// </summary>
/// <param name="obj">указатель на массив структур</param>
/// <param name="fileIn">ссылка на переменную открывающую поток ввода</param>
/// <param name="countOfAllSongs">текущее количество песен</param>
/// <returns></returns>
Songs* InputTextFromFile(Songs* obj, ifstream& fileIn, int& countOfAllSongs)
{
    countOfAllSongs++;
    obj = AddSong(obj, countOfAllSongs);
    
    int tmp = 1;
    while (!fileIn.eof())
    {
        if (tmp == 1)
        {
            string line;
            getline(fileIn, line);
            obj[countOfAllSongs - 1].songwriter_sName += line;
            getline(fileIn, line);
            obj[countOfAllSongs - 1].nameOfSong += line;
            getline(fileIn, line);
            if (line == "")
            {
                obj[countOfAllSongs - 1].yearIsKnown = false;
            }
            else
            {
                obj[countOfAllSongs - 1].yearIsKnown = true;
                obj[countOfAllSongs - 1].yearOfRelease += line;
            }
            ++tmp;
        }
        string line;
        getline(fileIn, line);
        if (line == "~~~~~~~~~~")
        {
            tmp = 1;
            obj[countOfAllSongs - 1].lyricOfSong[obj[countOfAllSongs - 1].lyricOfSong.length() - 1] = '\0';
            ++countOfAllSongs;
            obj = AddSong(obj, countOfAllSongs);
        }
        else
        {
            if (line == "")
            {
                obj[countOfAllSongs - 1].lyricOfSong += "\n";
                continue;
            }
            obj[countOfAllSongs - 1].lyricOfSong += line + "\n";
        }
    }
    obj[countOfAllSongs - 1].lyricOfSong[obj[countOfAllSongs-1].lyricOfSong.length() - 1] = '\0';

    cout << "Готово!\n";
    system("pause");
    system("cls");
    return obj;
}
/// <summary>
/// функция для пересоздания массива структур с заданным количеством
/// </summary>
/// <param name="obj">указатель на массив структур</param>
/// <param name="count">требуемое количество структур в новом массиве</param>
/// <returns></returns>
Songs* AddSong(Songs* obj, int count)
{
    Songs* tempObj = new Songs[count];
    for (size_t i = 0; i < count - 1; i++)
    {
        tempObj[i].lyricOfSong = obj[i].lyricOfSong;
        tempObj[i].nameOfSong = obj[i].nameOfSong;
        tempObj[i].songwriter_sName = obj[i].songwriter_sName;
        tempObj[i].wordIsHere = obj[i].wordIsHere;
        tempObj[i].yearIsKnown = obj[i].yearIsKnown;
        tempObj[i].yearOfRelease = obj[i].yearOfRelease;

    }
    delete[] obj;
    obj = tempObj;
    return obj;
}
/// <summary>
/// показывает список авторов каждой песни
/// </summary>
/// <param name="obj">указатель на массив структур</param>
/// <param name="count">количество песен</param>
/// <returns></returns>
int ShowListOfAuthors(Songs* obj, int count)
{
    cout << "   --------------------------------------------------------------\n";
    cout << "   |                     СПИСОК ВСЕХ АВТОРОВ                    |\n";
    cout << "   --------------------------------------------------------------\n";
    int tmpCountOfAuthors = 1;
    string tmp;
    bool flag = false;

    for (size_t i = 0, k = 0; i < count; i++)
    {
        cout << "    " << tmpCountOfAuthors << " | " << obj[i].songwriter_sName << endl;
        ++tmpCountOfAuthors;
    }

    return tmpCountOfAuthors;
}

