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
    /*string filename = "";
    ifstream fileIn;
    fileIn.open(filename);
    if (fileIn.fail())
    {
        cout << "Error opening file!\a";
        return 404;
    }
    fileIn.close();
    ofstream fileOut;
    fileOut.open(filename);
    fileOut.close();*/

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
                    ShowListOfSongs(songs, countOfAllSongs);
                    int option = CheckForCorrect(countOfAllSongs + 1);
                    system("cls");

                    if (option == countOfAllSongs)
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
                InputTextFromKeyboard(songs, countOfAllSongs);
            }
            else if (option == 2)
            {
                ifstream fileIn;
                while (true)
                {
                    cout << "Введите точное имя текстового файла с учётом регистра, без указания расширения файла(также убедитесь чтобы файл находился в папке программы): ";
                    string filename = "";
                    cin >> filename;
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
                        break;
                    }
                }
                InputTextFromFile(songs, fileIn, countOfAllSongs);


                fileIn.close();
            }
            else
            {
                break;
            }



        }
        else if (option == 3)
        {

        }

    }

    delete[] songs;
    return 0;
    system("pause");
}