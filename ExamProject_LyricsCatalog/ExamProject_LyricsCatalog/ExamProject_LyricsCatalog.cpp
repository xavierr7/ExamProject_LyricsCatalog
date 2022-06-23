//  Экзаменационная работа "каталог текстов песен"
//  Выполнил Артём Миллер
//  06/23/2022
//
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

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int countOfAllSongs = 1;

    Songs* songs = new Songs[countOfAllSongs];
    --countOfAllSongs;

    while (true)
    {
        int option = MainMenu();

        if (option == 1)
        {
            if (songs[0].nameOfSong.length() == 0)
            {
                cout << "Список пока что пуст, время его пополнить!\n";
                system("pause");
                system("cls");
            }
            else
            {
                while (true)
                {
                    int tmpCount = ShowListOfSongs(songs, countOfAllSongs);
                    cout << "     " << tmpCount << " | Выйти в главное меню\n";
                    cout << "   --------------------------------------------------------------\n";
                    cout << "   |     ВВЕДИТЕ НОМЕР ПЕСНИ, ТЕКСТ КОТОРОЙ ХОТИТЕ ПОСМОТРЕТЬ   |\n";
                    cout << "   |     ИЛИ СООТВЕТСТВУЮЩИЙ ПУНКТ ДЛЯ ВЫХОДА В ГЛАВНОЕ МЕНЮ:   |\n";
                    cout << "   --------------------------------------------------------------\n";
                    cout << "                                ";
                    int option = CheckForCorrect(tmpCount + 1);
                    system("cls");

                    if (option == tmpCount)
                    {
                        break;
                    }
                    else
                    {
                        int tmpCountOfSongs = 1;
                        for (size_t i = 0; i < countOfAllSongs; i++)
                        {
                            if (tmpCountOfSongs == option)
                            {
                                cout << songs[i].lyricOfSong;
                            }
                            ++tmpCountOfSongs;
                        }
                    }
                    cout << endl;
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (option == 2)
        {
            int option = InputTextMenu();
            if (option == 1)
            {
                songs = InputTextFromKeyboard(songs, countOfAllSongs);
            }
            else if (option == 2)
            {
                ifstream fileIn;
                while (true)
                {
                    cout << "Введите точное имя текстового файла с учётом регистра, без указания расширения файла(также убедитесь чтобы файл находился в папке программы): ";
                    string filename = "";
                    cin >> filename;
                    cin.ignore();
                    filename += ".txt";
                    fileIn.open(filename);
                    if (fileIn.fail())
                    {
                        cout << "Файл не открылся, проверьте на правильность написания названия или на наличие его в папке программы!\a";
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        system("cls");
                        break;
                    }
                }
                songs = InputTextFromFile(songs, fileIn, countOfAllSongs);
                fileIn.close();
            }
            else
            {
                break;
            }
        }
        else if (option == 3)
        {
            while (true)
            {
                int tmpCount = ShowListOfSongs(songs, countOfAllSongs);
                cout << "     " << tmpCount << " | Выйти в главное меню\n";
                cout << "   --------------------------------------------------------------\n";
                cout << "   |     ВВЕДИТЕ НОМЕР ПЕСНИ, ТЕКСТ КОТОРОЙ ХОТИТЕ УДАЛИТЬ      |\n";
                cout << "   |     ИЛИ СООТВЕТСТВУЮЩИЙ ПУНКТ ДЛЯ ВЫХОДА В ГЛАВНОЕ МЕНЮ:   |\n";
                cout << "   --------------------------------------------------------------\n";
                cout << "                                ";
                int tmOption = CheckForCorrect(tmpCount + 1);
                system("cls");

                if (tmOption == tmpCount)
                {
                    break;
                }
                else
                {
                    songs[tmOption - 1].lyricOfSong = "";

                }
                system("pause");
                system("cls");
            }

        }
        else if (option == 4)
        {
            while (true)
            {
                int tmpCount = ShowListOfSongs(songs, countOfAllSongs);
                cout << "     " << tmpCount << " | Выйти в главное меню\n";
                cout << "   --------------------------------------------------------------\n";
                cout << "   |     ВВЕДИТЕ НОМЕР ПЕСНИ, ТЕКСТ КОТОРОЙ ХОТИТЕ ИЗМЕНИТЬ     |\n";
                cout << "   |     ИЛИ СООТВЕТСТВУЮЩИЙ ПУНКТ ДЛЯ ВЫХОДА В ГЛАВНОЕ МЕНЮ:   |\n";
                cout << "   --------------------------------------------------------------\n";
                cout << "                                ";
                int tmpOption = CheckForCorrect(tmpCount + 1);
                system("cls");

                if (tmpOption == tmpCount)
                {
                    break;
                }
                else
                {
                    int tmpOption2 = ChangeTextMenu();
                    if (tmpOption2 == 1)
                    {
                        songs[tmpOption - 1].lyricOfSong = "";
                        InputText(songs, tmpOption);
                    }
                    else if (tmpOption2 == 2)
                    {
                        songs[tmpOption - 1].lyricOfSong += "\n";
                        InputText(songs, tmpOption);
                    }
                    else
                    {
                        break;
                    }
                }
                system("pause");
                system("cls");
            }
        }
        else if (option == 5)
        {
            SongsChar* songsChar = new SongsChar[countOfAllSongs];
            for (size_t i = 0; i < countOfAllSongs; i++)
            {
                strcpy_s(songsChar[i].lyricOfSong, songs[i].lyricOfSong.c_str());
                strcpy_s(songsChar[i].nameOfSong, songs[i].nameOfSong.c_str());
                strcpy_s(songsChar[i].songwriter_sName, songs[i].songwriter_sName.c_str());
                strcpy_s(songsChar[i].yearOfRelease, songs[i].yearOfRelease.c_str());
                songsChar[i].wordIsHere = songs[i].wordIsHere;
                songsChar[i].yearIsKnown = songs[i].yearIsKnown;

            }

            ofstream fileOut;
            string filename = "CurrentListOfSongs.txt";
            fileOut.open(filename);
            for (size_t i = 0; i < countOfAllSongs; i++)
            {
                fileOut.write((char*)&songsChar[i], sizeof(SongsChar));
            }
            fileOut.close();

            delete[] songsChar;
        }
        else if (option == 6)
        {
            while (true)
            {
                int tmpCount = ShowListOfAuthors(songs, countOfAllSongs);
                cout << "     " << tmpCount << " | Выйти в главное меню\n";
                cout << "   --------------------------------------------------------------\n";
                cout << "   |   ВВЕДИТЕ НОМЕР АВТОРА, ПЕСНИ КОТОРОГО ХОТИТЕ ПОСМОТРЕТЬ   |\n";
                cout << "   |    ИЛИ СООТВЕТСТВУЮЩИЙ ПУНКТ ДЛЯ ВЫХОДА В ГЛАВНОЕ МЕНЮ:    |\n";
                cout << "   --------------------------------------------------------------\n";
                cout << "                                ";
                int tmOption = CheckForCorrect(tmpCount + 1);
                system("cls");

                if (tmOption == tmpCount)
                {
                    break;
                }
                else
                {
                    cout << "|" << songs[tmOption - 1].songwriter_sName << endl;
                    for (size_t i = 0; i < countOfAllSongs; i++)
                    {
                        if (songs[i].songwriter_sName == songs[tmOption - 1].songwriter_sName)
                        {
                            cout << "  -" << songs[i].nameOfSong << endl;;
                        }
                    }

                }
                system("pause");
                system("cls");
            }

        }
        else if (option == 7)
        {
            string rusAlphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
            string word;
            cout << "   --------------------------------------------------------------\n";
            cout << "   |       УКАЖИТЕ СЛОВО ПО КОТОРОМУ ХОТИТЕ НАЙТИ ПЕСНИ         |\n";
            cout << "   --------------------------------------------------------------\n\n   -";
            cin >> word;
            for (size_t i = 0; i < countOfAllSongs; i++)
            {
                int k = 0;
                while (songs[i].lyricOfSong[k] != '\0')
                {
                    string currentWord;
                    for (; k < songs[i].lyricOfSong.length(); k++)
                    {
                        if ((songs[i].lyricOfSong[k] >= 32 && songs[i].lyricOfSong[k] <= 64) || (songs[i].lyricOfSong[k] >= 91 && songs[i].lyricOfSong[k] <= 96) || (songs[i].lyricOfSong[k] >= 123 && songs[i].lyricOfSong[k] <= 126))
                        {
                            break;
                        }
                        if ((songs[i].lyricOfSong[k] >= 65 && songs[i].lyricOfSong[k] <= 90) || (songs[i].lyricOfSong[k] >= 97 && songs[i].lyricOfSong[k] <= 122))
                        {
                            break;
                        }
                        for (size_t j = 0; j < rusAlphabet.length(); j++)
                        {
                            if (songs[i].lyricOfSong[k] == rusAlphabet[j])
                            {
                                currentWord += songs[i].lyricOfSong[k];
                                break;
                            }
                        }
                    }
                    while ((songs[i].lyricOfSong[k] >= 65 && songs[i].lyricOfSong[k] <= 90) || (songs[i].lyricOfSong[k] >= 97 && songs[i].lyricOfSong[k] <= 122))
                    {
                        currentWord += songs[i].lyricOfSong[k];
                        ++k;
                    }
                    if (currentWord == word)
                    {
                        songs[i].wordIsHere = true;
                        break;
                    }
                    else
                    {
                        while ((songs[i].lyricOfSong[k] >= 32 && songs[i].lyricOfSong[k] <= 64) || (songs[i].lyricOfSong[k] >= 91 && songs[i].lyricOfSong[k] <= 96) || (songs[i].lyricOfSong[k] >= 123 && songs[i].lyricOfSong[k] <= 126))
                        {
                           
                            ++k;
                        }
                    }
                }

            }
            system("cls");
            cout << "   --------------------------------------------------------------\n";
            cout << "   |                       СПИСОК ВСЕХ ПЕСЕН                    |\n";
            cout << "   --------------------------------------------------------------\n";

            int tmpCount = 1;
            for (size_t i = 0; i < countOfAllSongs; i++)
            {
                if (songs[i].wordIsHere == true)
                {
                    cout << "     " << tmpCount << " | " << "\"" << songs[i].nameOfSong << "\" ~ " << songs[i].songwriter_sName;
                    if (songs[i].yearIsKnown)
                    {
                        cout << " ~ " << songs[i].yearOfRelease << endl;
                    }
                    else
                    {
                        cout << endl;
                    }
                    ++tmpCount;
                }
            }
            system("pause");
            system("cls");

        }
    }

    delete[] songs;

    return 0;
    system("pause");
}