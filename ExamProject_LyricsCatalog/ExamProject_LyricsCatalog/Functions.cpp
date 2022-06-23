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
			cout << "Ââåäèòå êîððåêòíûé íîìåð ïóíêòà!";
			system("pause");
			system("cls");
		}
	}
}

int MainMenu()
{
    //system("cls");
    cout << "   |                         ÌÅÍÞ                           |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No1|            ÂÛÂÅÑÒÈ ÑÏÈÑÎÊ ÂÑÅÕ ÏÅÑÅÍ               |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No2|         ÄÎÁÀÂÈÒÜ ÍÎÂÓÞ ÏÅÑÍÞ È Å¨ ÒÅÊÑÒ            |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No3|           ÓÄÀËÈÒÜ ÒÅÊÑÒ ÎÄÍÎÉ ÈÇ ÏÅÑÅÍ             |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No4|          ÈÇÌÅÍÅÍÈÅ ÒÅÊÑÒÀ ÎÄÍÎÉ ÈÇ ÏÅÑÅÍ           |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No5|          ÑÎÕÐÀÍÅÍÈÅ ÊÀÒÀËÎÃÀ ÏÅÑÅÍ Â ÔÀÉË          |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No6|   ÏÎÈÑÊ È ÎÒÎÁÐÀÆÅÍÈÅ ÂÑÅÕ ÏÅÑÅÍ ÎÄÍÎÃÎ ÀÂÒÎÐÀ     |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No7|               ÏÎÈÑÊ ÏÅÑÅÍ ÏÎ ÑËÎÂÓ                 |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No8|                     ÂÛÕÎÄ                          |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |               ÂÛÁÅÐÈÒÅ ÍÓÆÍÛÉ ÏÓÍÊÒ ÌÅÍÞ:              |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "                                ";
    int option = CheckForCorrect(9);
    system("cls");
    return option;
}

int InputTextMenu()
{
    cout << "   ----------------------------------------------------------\n";
    cout << "   |                           ÌÅÍÞ                         |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No1|             ÂÂÎÄ ÒÅÊÑÒÀ Ñ ÊËÀÂÈÀÒÓÐÛ               |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No2|             ÇÀÃÐÓÇÈÒÜ ÒÅÊÑÒ ÈÇ ÔÀÉËÀ               |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No3|                     ÂÛÕÎÄ                          |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "                                ";
    int option = CheckForCorrect(4);
    system("cls");
    return option;
}

int ChangeTextMenu()
{
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No1|                ÈÇÌÅÍÈÒÜ ÂÅÑÜ ÒÅÊÑÒ                 |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No2|     ÄÎÁÀÂÈÒÜ Â ÊÎÍÅÖ ÒÅÊÑÒÀ ÍÅÄÎÑÒÀÞÙÈÅ ÑÒÐÎÊÈ     |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No3|                     ÂÛÕÎÄ                          |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "                                ";
    int option = CheckForCorrect(4);
    system("cls");
    return option;
}

int ShowListOfSongs(const Songs* obj, int countOfAllSongs)
{
    cout << "   --------------------------------------------------------------\n";
    cout << "   |                       ÑÏÈÑÎÊ ÂÑÅÕ ÏÅÑÅÍ                    |\n";
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

void InputText(Songs* obj, int song)
{
    int countOfStrings = 1;
    system("cls");
    cout << "Íàæìèòå \"Enter\" è íà÷èíàéòå ââîä ñòðî÷êè\n";
    system("pause");
    system("cls");
    for (size_t i = 0; i < countOfStrings; i++)
    {
        string line;
        getline(cin, line);
        cout << "1 - ââåñòè ñëåäóþùóþ ñòðî÷êó\n";
        cout << "2 - ýòî âåñü òåêñò, âåðíóòüñÿ â ãëàâíîå ìåíþ\n";
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
            cout << "Ãîòîâî!\n";
            system("pause");
            system("cls");
            break;
        }
    }
}

Songs* InputTextFromKeyboard(Songs* obj, int& countOfAllSongs)
{
    countOfAllSongs++;
    obj = AddSong(obj, countOfAllSongs);
    cout << "Ââåäèòå èìÿ àâòîðà: ";
    getline(cin, obj[countOfAllSongs - 1].songwriter_sName);
    cout << "Ââåäèòå íàçâàíèå ïåñíè: ";
    getline(cin, obj[countOfAllSongs - 1].nameOfSong);
    cout << "\n Èçâåñòåí ëè âàì ãîä âûïóñêà ýòîé ïåñíè?\n1.) Äà\n2.) Íåò\n";
    int option = CheckForCorrect(3);
    if (option == 1)
    {
        cout << "Ââåäèòå åãî: \n";
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

    cout << "Ãîòîâî!\n";
    system("pause");
    system("cls");
    return obj;
}

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


int ShowListOfAuthors(Songs* obj, int count)
{
    cout << "   --------------------------------------------------------------\n";
    cout << "   |                     ÑÏÈÑÎÊ ÂÑÅÕ ÀÂÒÎÐÎÂ                    |\n";
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

