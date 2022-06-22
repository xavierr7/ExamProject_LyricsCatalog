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
			cout << "������� ���������� ����� ������!";
			system("pause");
			system("cls");
		}
	}
}

int MainMenu()
{
    system("cls");
    cout << "   |                         ����                           |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No1|            ������� ������ ���� �����               |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No2|         �������� ����� ����� � Ũ �����            |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No3|           ������� ����� ����� �� �����             |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No4|          ��������� ������ ����� �� �����           |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No5|          ���������� ������ ����� � ����            |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No6|   ����� � ����������� ���� ����� ������ ������     |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No7|               ����� ����� �� �����                 |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No8|                     �����                          |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |               �������� ������ ����� ����:              |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "                                ";
    int option = CheckForCorrect(9);
    system("cls");
    return option;
}

int InputTextMenu()
{
    cout << "   ----------------------------------------------------------\n";
    cout << "   |                           ����                         |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No1|             ���� ������ � ����������               |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No2|             ��������� ����� �� �����               |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No3|                     �����                          |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "                                ";
    int option = CheckForCorrect(4);
    system("cls");
    return option;
}

int ChangeTextMenu()
{
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No1|                �������� ���� �����                 |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No2|     �������� � ����� ������ ����������� ������     |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "   |No3|                     �����                          |\n";
    cout << "   ----------------------------------------------------------\n";
    cout << "                                ";
    int option = CheckForCorrect(4);
    system("cls");
    return option;
}

int ShowListOfSongs(const Songs* obj, int countOfAllSongs)
{
    cout << "   --------------------------------------------------------------\n";
    cout << "   |                       ������ ���� �����                    |\n";
    cout << "   --------------------------------------------------------------\n";
    int tmpCount = 1;
    for (size_t i = 0; i < countOfAllSongs; i++)
    {
        cout << "\t\t\t     " << tmpCount << " | " << "\"" << obj[i].nameOfSong << "\" ~ " << obj[i].songwriter_sName;
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
    cout << "������� \"Enter\" � ��������� ���� �������\n";
    for (size_t i = 0; i < countOfStrings; i++)
    {
        string line;
        getline(cin, line);
        cout << "1 - ������ ��������� �������\n";
        cout << "2 - ��� ���� �����, ��������� � ������� ����\n";
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
            cout << "������!\n";
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
    cout << "������� ��� ������: ";
    getline(cin, obj[countOfAllSongs - 1].songwriter_sName);
    cout << "������� �������� �����: ";
    getline(cin, obj[countOfAllSongs - 1].nameOfSong);
    cout << "\n �������� �� ��� ��� ������� ���� �����?\n1.) ��\n2.) ���\n";
    int option = CheckForCorrect(3);
    if (option == 1)
    {
        cout << "������� ���: \n";
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

    cout << "������!\n";
    system("pause");
    system("cls");
    return obj;
}

Songs* AddSong(Songs* obj, int countOfAllSongs)
{
    Songs* tempObj = new Songs[countOfAllSongs];
    for (size_t i = 0; i < countOfAllSongs - 1; i++)
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

//int ShowListOfAuthors(const Songwriter* obj, int countOfAuthor)
//{
//    cout << "\t\t\t   --------------------------------------------------------------\n";
//    cout << "\t\t\t   |                     ������ ���� �������                    |\n";
//    cout << "\t\t\t   --------------------------------------------------------------\n";
//    int tmpCountOfAuthors = 1;
//    for (size_t i = 0; i < countOfAuthor; i++)
//    {
//        cout << "\t\t\t   | " << tmpCountOfAuthors << " | " <<  obj[i].songwriter_sName << endl;
//        for (size_t j = 0; j < obj[i].n; j++)
//        {
//            cout << "\t\t\t      " << "-" << obj[i].songs[j].nameOfSong << endl;
//        }
//        ++tmpCountOfAuthors;
//        cout << endl;
//    }
//    return tmpCountOfAuthors;
//}

