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
                cout << "Ñïèñîê ïîêà ÷òî ïóñò, âðåìÿ åãî ïîïîëíèòü!\n";
                system("pause");
                system("cls");
            }
            else
            {
                while (true)
                {
                    int tmpCount = ShowListOfSongs(songs, countOfAllSongs);
                    cout << "     " << tmpCount << " | Âûéòè â ãëàâíîå ìåíþ\n";
                    cout << "   --------------------------------------------------------------\n";
                    cout << "   |     ÂÂÅÄÈÒÅ ÍÎÌÅÐ ÏÅÑÍÈ, ÒÅÊÑÒ ÊÎÒÎÐÎÉ ÕÎÒÈÒÅ ÏÎÑÌÎÒÐÅÒÜ   |\n";
                    cout << "   |     ÈËÈ ÑÎÎÒÂÅÒÑÒÂÓÞÙÈÉ ÏÓÍÊÒ ÄËß ÂÛÕÎÄÀ Â ÃËÀÂÍÎÅ ÌÅÍÞ:   |\n";
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
                    cout << "Ââåäèòå òî÷íîå èìÿ òåêñòîâîãî ôàéëà ñ ó÷¸òîì ðåãèñòðà, áåç óêàçàíèÿ ðàñøèðåíèÿ ôàéëà(òàêæå óáåäèòåñü ÷òîáû ôàéë íàõîäèëñÿ â ïàïêå ïðîãðàììû): ";
                    string filename = "";
                    cin >> filename;
                    cin.ignore();
                    filename += ".txt";
                    fileIn.open(filename);
                    if (fileIn.fail())
                    {
                        cout << "Ôàéë íå îòêðûëñÿ, ïðîâåðüòå íà ïðàâèëüíîñòü íàïèñàíèÿ íàçâàíèÿ èëè íà íàëè÷èå åãî â ïàïêå ïðîãðàììû!\a";
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
                cout << "     " << tmpCount << " | Âûéòè â ãëàâíîå ìåíþ\n";
                cout << "   --------------------------------------------------------------\n";
                cout << "   |     ÂÂÅÄÈÒÅ ÍÎÌÅÐ ÏÅÑÍÈ, ÒÅÊÑÒ ÊÎÒÎÐÎÉ ÕÎÒÈÒÅ ÓÄÀËÈÒÜ      |\n";
                cout << "   |     ÈËÈ ÑÎÎÒÂÅÒÑÒÂÓÞÙÈÉ ÏÓÍÊÒ ÄËß ÂÛÕÎÄÀ Â ÃËÀÂÍÎÅ ÌÅÍÞ:   |\n";
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
                    songs[tmpCount - 1].lyricOfSong = "";
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
                cout << "     " << tmpCount << " | Âûéòè â ãëàâíîå ìåíþ\n";
                cout << "   --------------------------------------------------------------\n";
                cout << "   |     ÂÂÅÄÈÒÅ ÍÎÌÅÐ ÏÅÑÍÈ, ÒÅÊÑÒ ÊÎÒÎÐÎÉ ÕÎÒÈÒÅ ÈÇÌÅÍÈÒÜ     |\n";
                cout << "   |     ÈËÈ ÑÎÎÒÂÅÒÑÒÂÓÞÙÈÉ ÏÓÍÊÒ ÄËß ÂÛÕÎÄÀ Â ÃËÀÂÍÎÅ ÌÅÍÞ:   |\n";
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
                    int option = ChangeTextMenu();
                    if (option ==1)
                    {
                        songs[tmpCount - 1].lyricOfSong = "";
                        input
                    }
                    else if (option == 2)
                    {

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

    }

    delete[] songs;
    return 0;
    system("pause");
}