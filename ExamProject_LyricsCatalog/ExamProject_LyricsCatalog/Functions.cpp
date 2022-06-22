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
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |                         ����                           |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |No1|            ������� ������ ���� �����               |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |No2|         �������� ����� ����� � Ũ �����            |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |No3|           ������� ����� ����� �� �����             |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |No4|          ��������� ������ ����� �� �����           |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |No5|          ���������� ������ ����� � ����            |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |No6|   ����� � ����������� ���� ����� ������ ������     |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |No7|               ����� ����� �� �����                 |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |No8|                     �����                          |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |               �������� ������ ����� ����:              |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t                                 ";
    int option = CheckForCorrect(9);
    system("cls");
    return option;
}

int InputTextMenu()
{
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |                           ����                         |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |No1|             ���� ������ � ����������               |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |No2|             ��������� ����� �� �����               |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t   |No3|                     �����                          |\n";
    cout << "\t\t\t   ----------------------------------------------------------\n";
    cout << "\t\t\t                                ";
    int option = CheckForCorrect(4);
    system("cls");
    return option;
}

void ShowListOfSongs(const Songs* obj)
{
    cout << "\t\t\t   --------------------------------------------------------------\n";
    cout << "\t\t\t   |                       ������ ���� �����                    |\n";
    cout << "\t\t\t   --------------------------------------------------------------\n";
    for (size_t i = 0; i < countOfAllSongs; i++)
    {
        cout << "\t\t\t     " << countOfAllSongs << " | " << "\"" << obj[i].nameOfSong << "\" ~ " << obj[i].songwriter_sName;
        if (obj[i].yearIsKnown)
        {
            cout << " ~ " << obj[i].yearOfRelease << endl;
        }
        else
        {
            cout << endl;
        }
    }
}
void InputTextFromKeyboard(Songs* obj)
{
    countOfAllSongs++;
    obj = AddSong(obj);
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

    int countOfStrings = 1;

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
            obj[countOfAllSongs - 1].lyricOfSong += line + "\n";

            cout << obj[countOfAllSongs - 1].lyricOfSong;

            ++countOfStrings;
        }
        else
        {
            obj[countOfAllSongs - 1].lyricOfSong += line + "\n";
            cout << "������!\n";
            system("pause");
            system("cls");
            break;
        }
    }
}

Songs* AddSong(Songs* obj)
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

