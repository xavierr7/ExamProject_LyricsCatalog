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
			cout << "Введите корректный номер пункта!";
			system("pause");
			system("cls");
		}
	}
}

int ShowListOfSongs(const Songwriter* obj, int countOfAuthor)
{
    cout << "\t\t\t   --------------------------------------------------------------\n";
    cout << "\t\t\t   |                       СПИСОК ВСЕХ ПЕСЕН                    |\n";
    cout << "\t\t\t   --------------------------------------------------------------\n";
    int tmpCountOfSongs = 1;
    for (size_t i = 0; i < countOfAuthor; i++)
    {
        int countOfSongs = obj[i].n;
        for (size_t j = 0; j < countOfSongs; j++)
        {
            cout << "\t\t\t   | " << tmpCountOfSongs << " | " << "\"" << obj[i].songs[j].nameOfSong << "\" ~ " << obj[i].songwriter_sName;
            if (obj[i].songs[j].yearIsKnown)
            {
                cout << " ~ " << obj[i].songs[j].yearOfRelease << endl;
            }
            else
            {
                cout << endl;
            }
            ++tmpCountOfSongs;
        }
    }
    return tmpCountOfSongs;
}

int ShowListOfAuthors(const Songwriter* obj, int countOfAuthor)
{
    cout << "\t\t\t   --------------------------------------------------------------\n";
    cout << "\t\t\t   |                     СПИСОК ВСЕХ АВТОРОВ                    |\n";
    cout << "\t\t\t   --------------------------------------------------------------\n";
    int tmpCountOfAuthors = 1;
    for (size_t i = 0; i < countOfAuthor; i++)
    {
        cout << "\t\t\t   | " << tmpCountOfAuthors << " | " <<  obj[i].songwriter_sName << endl;
        for (size_t j = 0; j < obj[i].n; j++)
        {
            cout << "\t\t\t      " << "-" << obj[i].songs[j].nameOfSong << endl;
        }
        ++tmpCountOfAuthors;
        cout << endl;
    }
    return tmpCountOfAuthors;
}

//string* AddStringToArr(string*& lyricOfSong, int countOfStrings)
//{
//    string* tempLyricOfSong = new string[countOfStrings];
//    for (size_t i = 0; i < countOfStrings - 1; i++)
//    {
//        for (size_t j = 0; j < lyricOfSong[i].length(); j++)
//        {
//            tempLyricOfSong[i] += lyricOfSong[j];
//        }
//    }
//    delete[] lyricOfSong;
//    lyricOfSong = tempLyricOfSong;
//    return lyricOfSong;
//}
//
//Songwriter* AddString(Songwriter* obj, int countOfAuthor, int indexOfAuthor)
//{
//    Songwriter* tempObj = new Songwriter[countOfAuthor];
//    for (size_t i = 0; i < countOfAuthor; i++)
//    {
//        tempObj[i].n = obj[i].n;
//        tempObj[i].songwriter_sName = obj[i].songwriter_sName;
//        for (size_t j = 0; j < obj[i].n; j++)
//        {
//            tempObj[i].songs[j].n = obj[i].songs[j].n;
//            tempObj[i].songs[j].nameOfSong = obj[i].songs[j].nameOfSong;
//            tempObj[i].songs[j].yearIsKnown = obj[i].songs[j].yearIsKnown;
//            tempObj[i].songs[j].yearOfRelease = obj[i].songs[j].yearOfRelease;
//            if (i == (indexOfAuthor) && j == (obj[i].n - 1))
//            {
//                for (size_t k = 0; k < obj[i].songs[j].n - 1; k++)
//                {
//                    tempObj[i].songs[j].lyricOfSong[k] = obj[i].songs[j].lyricOfSong[k];
//                }
//                continue;
//            }
//            for (size_t k = 0; k < obj[i].songs[j].n; k++)
//            {
//                tempObj[i].songs[j].lyricOfSong[k] = obj[i].songs[j].lyricOfSong[k];
//            }
//        }
//    }
//    delete[]obj;
//    obj = tempObj;
//    return obj;
//}
//
//Songwriter* AddStringFromTxt(Songwriter* obj, int countOfAuthor)
//{
//    Songwriter* tempObj = new Songwriter[countOfAuthor];
//    for (size_t i = 0; i < countOfAuthor; i++)
//    {
//        tempObj[i].n = obj[i].n;
//        tempObj[i].songwriter_sName = obj[i].songwriter_sName;
//        for (size_t j = 0; j < obj[i].n; j++)
//        {
//            tempObj[i].songs[j].n = obj[i].songs[j].n;
//            tempObj[i].songs[j].nameOfSong = obj[i].songs[j].nameOfSong;
//            tempObj[i].songs[j].yearIsKnown = obj[i].songs[j].yearIsKnown;
//            tempObj[i].songs[j].yearOfRelease = obj[i].songs[j].yearOfRelease;
//            if (i == (countOfAuthor - 1) && j == (obj[i].n - 1))
//            {
//                break;
//            }
//            for (size_t k = 0; k < obj[i].songs[j].n; k++)
//            {
//                tempObj[i].songs[j].lyricOfSong[k] = obj[i].songs[j].lyricOfSong[k];
//            }
//        }
//    }
//    delete[]obj;
//    obj = tempObj;
//    return obj;
//}
//
//Songwriter* AddStringFromTxt(Songwriter* obj, int countOfAuthor, int indexOfAuthor)
//{
//    Songwriter* tempObj = new Songwriter[countOfAuthor];
//    for (size_t i = 0; i < countOfAuthor; i++)
//    {
//        tempObj[i].n = obj[i].n;
//        tempObj[i].songwriter_sName = obj[i].songwriter_sName;
//        for (size_t j = 0; j < obj[i].n; j++)
//        {
//            tempObj[i].songs[j].n = obj[i].songs[j].n;
//            tempObj[i].songs[j].nameOfSong = obj[i].songs[j].nameOfSong;
//            tempObj[i].songs[j].yearIsKnown = obj[i].songs[j].yearIsKnown;
//            tempObj[i].songs[j].yearOfRelease = obj[i].songs[j].yearOfRelease;
//            if (i == (indexOfAuthor - 1) && j == (obj[i].n - 1))
//            {
//                break;
//            }
//            for (size_t k = 0; k < obj[i].songs[j].n; k++)
//            {
//                tempObj[i].songs[j].lyricOfSong[k] = obj[i].songs[j].lyricOfSong[k];
//            }
//        }
//    }
//    delete[]obj;
//    obj = tempObj;
//    return obj;
//}
//
//Songwriter* AddSong(Songwriter* obj, int countOfAuthor)
//{
//    Songwriter* tempObj = new Songwriter[countOfAuthor];
//    for (size_t i = 0; i < countOfAuthor; i++)
//    {
//        tempObj[i].n = obj[i].n;
//        tempObj[i].songwriter_sName = obj[i].songwriter_sName;
//        for (size_t j = 0; j < obj[i].n - 1; j++)
//        {
//            tempObj[i].songs[j].n = obj[i].songs[j].n;
//            tempObj[i].songs[j].nameOfSong = obj[i].songs[j].nameOfSong;
//            tempObj[i].songs[j].yearIsKnown = obj[i].songs[j].yearIsKnown;
//            tempObj[i].songs[j].yearOfRelease = obj[i].songs[j].yearOfRelease;
//            for (size_t k = 0; k < obj[i].songs[j].n; k++)
//            {
//                tempObj[i].songs[j].lyricOfSong[k] = obj[i].songs[j].lyricOfSong[k];
//            }
//        }
//    }
//    delete[]obj;
//    obj = tempObj;
//    return obj;
//}
//
Songwriter* AddAuthor(Songwriter* obj, int countOfAuthor)
{
    Songwriter* tempObj = new Songwriter[countOfAuthor];
    for (size_t i = 0; i < countOfAuthor - 1; i++)
    {
        tempObj[i].n = obj[i].n;
        tempObj[i].songs = obj[i].songs;
        tempObj[i].songwriter_sName = obj[i].songwriter_sName;
        for (size_t j = 0; j < obj[i].n; j++)
        {
            tempObj[i].songs[j].yearIsKnown = obj[i].songs[j].yearIsKnown;
            tempObj[i].songs[j].nameOfSong = obj[i].songs[j].nameOfSong;
            tempObj[i].songs[j].yearOfRelease = obj[i].songs[j].yearOfRelease;
            tempObj[i].songs[j].lyricOfSong = obj[i].songs[j].lyricOfSong;
        }
    }
    delete[]obj;
    obj = tempObj;
    return obj;
}
//
////void AddNewSongNewAuthor(Songwriter* obj, int countOfAuthor, int& countOfSongs)
////{
////    cout << "Введите имя автора: ";
////    getline(cin, obj[countOfAuthor - 1].songwriter_sName);
////    cout << "Введите название песни: ";
////    getline(cin, obj[countOfAuthor - 1].songs[obj[countOfAuthor - 1].n - 1].nameOfSong);
////    cout << "\n Известен ли вам год выпуска этой песни?\n1.) Да.\n2.) Нет\n";
////    int tmpOption3 = CheckForCorrect(3);
////    system("cls");
////    if (tmpOption3 == 1)
////    {
////        cout << "Введите его: \n";
////        obj[countOfAuthor - 1].songs[obj[countOfAuthor - 1].n - 1].yearIsKnown = true;
////        cin >> obj[countOfAuthor - 1].songs[obj[countOfAuthor - 1].n - 1].yearOfRelease;
////        cin.ignore();
////    }
////    else
////    {
////        obj[countOfAuthor - 1].songs[obj[countOfAuthor - 1].n - 1].yearIsKnown = false;
////    }
////    int countOfStrings = 1;
////    for (size_t i = 0; i < countOfStrings; i++)
////    {
////        getline(cin, obj[countOfAuthor - 1].songs[obj[countOfAuthor - 1].n - 1].lyricOfSong[i]);
////        cout << "1 - ввести следующую строчку\n";
////        cout << "2 - это весь текст, вернуться в главное меню\n";
////        int tmpOption = CheckForCorrect(3);
////        system("cls");
////        if (tmpOption == 1)
////        {
////            obj[countOfAuthor - 1].songs[obj[countOfAuthor - 1].n - 1].lyricOfSong[i] += "\n";
////            for (size_t i = 0; i < countOfStrings; i++)
////            {
////                cout << obj[countOfAuthor - 1].songs[obj[countOfAuthor - 1].n - 1].lyricOfSong[i];
////            }
////            ++countOfStrings;
////            obj[countOfAuthor - 1].songs[obj[countOfAuthor - 1].n - 1].n = countOfStrings;
////            obj = AddString(obj, countOfAuthor);
////        }
////        else
////        {
////            ++countOfSongs;
////            break;
////        }
////    }
////}
//
//void SetFromTxt(Songwriter* obj, string& lyrics, int indexOfAuthor, int countOfStrings)
//{
//    for (size_t i = 0, j = 0; i < countOfStrings; i++)
//    {
//        if (i == countOfStrings - 1)
//        {
//            while (lyrics[j] != '\0')
//            {
//                obj[indexOfAuthor - 1].songs[obj[indexOfAuthor - 1].n - 1].lyricOfSong[i] += lyrics[j];
//            }
//            break;
//        }
//        for (; j < lyrics.length(); j++)
//        {
//            if (lyrics[j] != '\n')
//            {
//                obj[indexOfAuthor - 1].songs[obj[indexOfAuthor - 1].n - 1].lyricOfSong[i] += lyrics[j];
//            }
//            else
//            {
//                obj[indexOfAuthor - 1].songs[obj[indexOfAuthor - 1].n - 1].lyricOfSong[i] += "\n";
//            }
//        }
//    }
//}
//
//void AddNewSongForSelectedAuthor(Songwriter* obj, int indexOfAuthor, int countOfAuthor, int& countOfSongs)
//{
//    obj[indexOfAuthor - 1].n++;
//    obj = AddSong(obj, indexOfAuthor);
//    cout << "Введите название песни: ";
//    getline(cin, obj[indexOfAuthor - 1].songs[obj[indexOfAuthor - 1].n - 1].nameOfSong);
//    cout << "\n Известен ли вам год выпуска этой песни?\n1.) Да.\n2.) Нет\n";
//    int tmpOption3 = CheckForCorrect(3);
//    system("cls");
//    if (tmpOption3 == 1)
//    {
//        cout << "Введите его: \n";
//        obj[indexOfAuthor - 1].songs[obj[indexOfAuthor - 1].n - 1].yearIsKnown = true;
//        cin >> obj[indexOfAuthor - 1].songs[obj[indexOfAuthor - 1].n - 1].yearOfRelease;
//        cin.ignore();
//    }
//    else
//    {
//        obj[indexOfAuthor - 1].songs[obj[indexOfAuthor - 1].n - 1].yearIsKnown = false;
//    }
//    int countOfStrings = 1;
//    for (size_t i = 0; i < countOfStrings; i++)
//    {
//        getline(cin, obj[indexOfAuthor - 1].songs[obj[indexOfAuthor - 1].n - 1].lyricOfSong[i]);
//        cout << "1 - ввести следующую строчку\n";
//        cout << "2 - это весь текст, вернуться в главное меню\n";
//        int tmpOption = CheckForCorrect(3);
//        system("cls");
//        if (tmpOption == 1)
//        {
//            obj[indexOfAuthor - 1].songs[obj[indexOfAuthor - 1].n - 1].lyricOfSong[i] += "\n";
//            for (size_t i = 0; i < countOfStrings; i++)
//            {
//                cout << obj[indexOfAuthor - 1].songs[obj[indexOfAuthor - 1].n - 1].lyricOfSong[i];
//            }
//            ++countOfStrings;
//            obj[indexOfAuthor - 1].songs[obj[indexOfAuthor - 1].n - 1].n = countOfStrings;
//            obj = AddString(obj, countOfAuthor, indexOfAuthor - 1);
//        }
//        else
//        {
//            ++countOfSongs;
//            break;
//        }
//    }
//}
