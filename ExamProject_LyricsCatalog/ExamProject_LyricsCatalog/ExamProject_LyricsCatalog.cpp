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

int countOfAuthor = 1;
int countOfAllSongs = 1;

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

    
    Songwriter* songwriter = new Songwriter[countOfAuthor];
    

    while (true)
    {
        system("cls");
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   |                         ÌÅÍÞ                           |\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   |No1|            ÂÛÂÅÑÒÈ ÑÏÈÑÎÊ ÂÑÅÕ ÏÅÑÅÍ               |\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   |No2|         ÄÎÁÀÂÈÒÜ ÍÎÂÓÞ ÏÅÑÍÞ È Å¨ ÒÅÊÑÒ            |\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   |No3|           ÓÄÀËÈÒÜ ÒÅÊÑÒ ÎÄÍÎÉ ÈÇ ÏÅÑÅÍ             |\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   |No4|          ÈÇÌÅÍÅÍÈÅ ÒÅÊÑÒÀ ÎÄÍÎÉ ÈÇ ÏÅÑÅÍ           |\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   |No5|          ÑÎÕÐÀÍÅÍÈÅ ÒÅÊÑÒÀ ÏÅÑÍÈ Â ÔÀÉË            |\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   |No6|   ÏÎÈÑÊ È ÎÒÎÁÐÀÆÅÍÈÅ ÂÑÅÕ ÏÅÑÅÍ ÎÄÍÎÃÎ ÀÂÒÎÐÀ     |\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   |No7|               ÏÎÈÑÊ ÏÅÑÅÍ ÏÎ ÑËÎÂÓ                 |\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   |No8|                     ÂÛÕÎÄ                          |\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t   |               ÂÛÁÅÐÈÒÅ ÍÓÆÍÛÉ ÏÓÍÊÒ ÌÅÍÞ:              |\n";
        cout << "\t\t\t   ----------------------------------------------------------\n";
        cout << "\t\t\t                                ";
        int option = CheckForCorrect(9);
        system("cls");

        if (option == 1)
        {
            if (songwriter[0].songwriter_sName.length() == 0)
            {
                cout << "Ñïèñîê ïîêà ÷òî ïóñò, âðåìÿ åãî ïîïîëíèòü!\n";
                system("pause");
                system("cls");
            }
            else
            {
                while (true)
                {
                    int tmpCountOfSongs1;
                    tmpCountOfSongs1 = ShowListOfSongs(songwriter, countOfAuthor);
                    cout << "\t\t\t   | " << tmpCountOfSongs1 << " | Âûéòè â ãëàâíîå ìåíþ\n";
                    cout << "\t\t\t   --------------------------------------------------------------\n";
                    cout << "\t\t\t   |     ÂÂÅÄÈÒÅ ÍÎÌÅÐ ÏÅÑÍÈ, ÒÅÊÑÒ ÊÎÒÎÐÎÉ ÕÎÒÈÒÅ ÏÎÑÌÎÒÐÅÒÜ   |\n";
                    cout << "\t\t\t   |     ÈËÈ ÑÎÎÒÂÅÒÑÒÂÓÞÙÈÉ ÏÓÍÊÒ ÄËß ÂÛÕÎÄÀ Â ÃËÀÂÍÎÅ ÌÅÍÞ:   |\n";
                    cout << "\t\t\t   --------------------------------------------------------------\n";
                    cout << "\t\t\t                                ";
                    int option1 = CheckForCorrect(tmpCountOfSongs1 + 1);
                    system("cls");

                    if (option1 == tmpCountOfSongs1)
                    {
                        break;
                    }
                    else
                    {
                        int tmpCountOfSongs2 = 1;
                        for (size_t i = 0; i < countOfAuthor; i++)
                        {
                            for (size_t j = 0; j < songwriter[i].n; j++)
                            {
                                if (tmpCountOfSongs2 == option1)
                                {
                                    cout << songwriter[i].songs[j].lyricOfSong;
                                }
                                ++tmpCountOfSongs2;
                            }
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
            while (true)
            {
                if (countOfAuthor == 1 && countOfAllSongs == 1)
                {
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   |                           ÌÅÍÞ                         |\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   |No1|             ÂÂÎÄ ÒÅÊÑÒÀ Ñ ÊËÀÂÈÀÒÓÐÛ               |\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   |No2|             ÇÀÃÐÓÇÈÒÜ ÒÅÊÑÒ ÈÇ ÔÀÉËÀ               |\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   |No3|                     ÂÛÕÎÄ                          |\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t                                ";
                    int option3 = CheckForCorrect(4);
                    system("cls");
                    int countOfSongs = 1;
                    Song* songs = new Song[countOfSongs];
                    if (option3 == 1)
                    {
                        songwriter[countOfAuthor - 1].n = countOfSongs;
                        songwriter[countOfAuthor - 1].songs = songs;
                        cout << "Ââåäèòå èìÿ àâòîðà: ";
                        getline(cin, songwriter[countOfAuthor - 1].songwriter_sName);
                        cout << "Ââåäèòå íàçâàíèå ïåñíè: ";
                        getline(cin, songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].nameOfSong);
                        cout << "\n Èçâåñòåí ëè âàì ãîä âûïóñêà ýòîé ïåñíè?\n1.) Äà\n2.) Íåò\n";
                        int tmpOption3 = CheckForCorrect(3);
                        if (tmpOption3 == 1)
                        {
                            cout << "Ââåäèòå åãî: \n";
                            songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].yearIsKnown = true;
                            cin >> songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].yearOfRelease;
                            cin.ignore();
                            system("cls");
                        }
                        else
                        {
                            songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].yearIsKnown = false;
                            system("cls");
                        }
                        
                        int countOfStrings = 1;
                        
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
                                songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong += line + "\n";
                                
                                cout << songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong;

                                ++countOfStrings;   
                            }
                            else
                            {
                                songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong += line + "\n";
                                ++countOfAllSongs;
                                cout << "Ãîòîâî!\n";
                                system("pause");
                                system("cls");
                                break;
                            }
                        }
                        break;
                    }
                    else if (option3 == 2)
                    {
                        
                        string filename = "Lyrics.txt";
                        ifstream fileIn;
                        fileIn.open(filename);
                        if (fileIn.fail())
                        {
                            cout << "Error opening file!\a";
                            return 404;
                        }
                        songwriter[countOfAuthor - 1].n = countOfSongs;
                        songwriter[countOfAuthor - 1].songs = songs;
                        cout << "Ââåäèòå èìÿ àâòîðà: ";
                        getline(cin, songwriter[countOfAuthor - 1].songwriter_sName);
                        cout << "Ââåäèòå íàçâàíèå ïåñíè: ";
                        getline(cin, songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].nameOfSong);
                        cout << "\n Èçâåñòåí ëè âàì ãîä âûïóñêà ýòîé ïåñíè?\n1.) Äà\n2.) Íåò\n";
                        int tmpOption3 = CheckForCorrect(3);
                        if (tmpOption3 == 1)
                        {
                            songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].yearIsKnown = true;
                            cin >> songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].yearOfRelease;
                            cin.ignore();
                            system("cls");
                        }
                        else
                        {
                            songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].yearIsKnown = false;
                            system("cls");
                        }

                        int countOfStrings = 1;
                        
                        while (!fileIn.eof())
                        {
                            string line;
                            getline(fileIn, line);
                            if (line == "")
                            {
                                songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong += "\n";
                            }
                            line += "\n";
                            songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong += line;
                            ++countOfStrings;
                        }
                        songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong[songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong.length() - 1] = '\0';
                        fileIn.close();
                        ++countOfAllSongs;
                        cout << "Ãîòîâî!\n";
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        break;
                    }
                    break;
                    
                }
                else
                {
                    
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   |                           ÌÅÍÞ                         |\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   |No1|             ÂÂÎÄ ÒÅÊÑÒÀ Ñ ÊËÀÂÈÀÒÓÐÛ               |\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   |No2|             ÇÀÃÐÓÇÈÒÜ ÒÅÊÑÒ ÈÇ ÔÀÉËÀ               |\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t   |No3|                     ÂÛÕÎÄ                          |\n";
                    cout << "\t\t\t   ----------------------------------------------------------\n";
                    cout << "\t\t\t                                ";
                    int option5 = CheckForCorrect(4);
                    system("cls");
                    if (option5 == 1)
                    {
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   |                           ÌÅÍÞ                         |\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   |No1|  ÄÎÁÀÂÈÒÜ ÏÅÑÍÞ ÀÂÒÎÐÀ ÎÄÍÎÃÎ ÈÇ ÐÀÍÅÅ ÄÎÁÀÂËÅÍÍÛÕ |\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   |No2|         ÄÎÁÀÂÈÒÜ ÍÎÂÓÞ ÏÅÑÍÞ ÍÎÂÎÃÎ ÀÂÒÎÐÀ         |\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   |No3|                     ÂÛÕÎÄ                          |\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t                                ";
                        int tmpOption1 = CheckForCorrect(4);
                        system("cls");

                        if (tmpOption1 == 1)
                        {
                            int tmpCountOfAuthors1;
                            tmpCountOfAuthors1 = ShowListOfAuthors(songwriter, countOfAuthor);
                            cout << "\t\t\t   | " << tmpCountOfAuthors1 << " | Âûéòè â ãëàâíîå ìåíþ\n";
                            cout << "\t\t\t   --------------------------------------------------------------\n";
                            cout << "\t\t\t   |  ÂÂÅÄÈÒÅ ÍÎÌÅÐ ÀÂÒÎÐÀ, ×ÜÞ ÏÅÑÍÞ ÕÎÒÈÒÅ ÄÎÁÀÂÈÒÜ Â ÑÏÈÑÎÊ  |\n";
                            cout << "\t\t\t   |     ÈËÈ ÑÎÎÒÂÅÒÑÒÂÓÞÙÈÉ ÏÓÍÊÒ ÄËß ÂÛÕÎÄÀ Â ÃËÀÂÍÎÅ ÌÅÍÞ:   |\n";
                            cout << "\t\t\t   --------------------------------------------------------------\n";
                            cout << "\t\t\t                                ";
                            int tmpOption2 = CheckForCorrect(tmpCountOfAuthors1 + 1);
                            system("cls");

                            if (tmpOption2 == tmpCountOfAuthors1)
                            {
                                break;
                            }
                            else
                            {
                                int countOfSongs = ++songwriter[tmpOption2 - 1].n;
                                Song* songs = new Song[countOfSongs];
                                songwriter[countOfAuthor - 1].songs = songs;
                                cout << "Ââåäèòå íàçâàíèå ïåñíè: ";
                                getline(cin, songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].nameOfSong);
                                cout << "\n Èçâåñòåí ëè âàì ãîä âûïóñêà ýòîé ïåñíè?\n1.) Äà\n2.) Íåò\n";
                                int tmpOption3 = CheckForCorrect(3);
                                system("cls");
                                if (tmpOption3 == 1)
                                {
                                    cout << "Ââåäèòå åãî: \n";
                                    songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].yearIsKnown = true;
                                    cin >> songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].yearOfRelease;
                                    cin.ignore();
                                }
                                else
                                {
                                    songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].yearIsKnown = false;
                                }
                                int countOfStrings = 1;
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
                                        songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong += line + "\n";

                                        cout << songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].lyricOfSong;

                                        ++countOfStrings;
                                    }
                                    else
                                    {
                                        songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong += line + "\n";
                                        ++countOfAllSongs;
                                        cout << "Ãîòîâî!\n";
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                }
                            }
                        }
                        else if (tmpOption1 == 2)
                        {
                            ++countOfAuthor;
                            songwriter = AddAuthor(songwriter, countOfAuthor);
                            int countOfSongs = 1;
                            Song* songs = new Song[countOfSongs];
                            songwriter[countOfAuthor - 1].n = countOfSongs;
                            songwriter[countOfAuthor - 1].songs = songs;
                            cout << "Ââåäèòå èìÿ àâòîðà: ";
                            getline(cin, songwriter[countOfAuthor - 1].songwriter_sName);
                            cout << "Ââåäèòå íàçâàíèå ïåñíè: ";
                            getline(cin, songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].nameOfSong);
                            cout << "\n Èçâåñòåí ëè âàì ãîä âûïóñêà ýòîé ïåñíè?\n1.) Äà\n2.) Íåò\n";
                            int tmpOption3 = CheckForCorrect(3);
                            if (tmpOption3 == 1)
                            {
                                cout << "Ââåäèòå åãî: \n";
                                songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].yearIsKnown = true;
                                cin >> songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].yearOfRelease;
                                cin.ignore();
                                system("cls");
                            }
                            else
                            {
                                songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].yearIsKnown = false;
                                system("cls");
                            }

                            int countOfStrings = 1;

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
                                    songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong += line + "\n";

                                    cout << songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong;

                                    ++countOfStrings;
                                }
                                else
                                {
                                    songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong += line + "\n";
                                    ++countOfAllSongs;
                                    cout << "Ãîòîâî!\n";
                                    system("pause");
                                    system("cls");
                                    break;
                                }
                            }
                        }
                        else
                        {
                            break;
                        }
                        
                    }
                    else if (option5 == 2)
                    {
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   |                           ÌÅÍÞ                         |\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   |No1|  ÄÎÁÀÂÈÒÜ ÏÅÑÍÞ ÀÂÒÎÐÀ ÎÄÍÎÃÎ ÈÇ ÐÀÍÅÅ ÄÎÁÀÂËÅÍÍÛÕ |\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   |No2|         ÄÎÁÀÂÈÒÜ ÍÎÂÓÞ ÏÅÑÍÞ ÍÎÂÎÃÎ ÀÂÒÎÐÀ         |\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t   |No3|                     ÂÛÕÎÄ                          |\n";
                        cout << "\t\t\t   ----------------------------------------------------------\n";
                        cout << "\t\t\t                                ";
                        int tmpOption1 = CheckForCorrect(4);
                        system("cls");
                        if (tmpOption1 == 1)
                        {
                            int tmpCountOfAuthors1;
                            tmpCountOfAuthors1 = ShowListOfAuthors(songwriter, countOfAuthor);
                            cout << "\t\t\t   | " << tmpCountOfAuthors1 << " | Âûéòè â ãëàâíîå ìåíþ\n";
                            cout << "\t\t\t   --------------------------------------------------------------\n";
                            cout << "\t\t\t   |  ÂÂÅÄÈÒÅ ÍÎÌÅÐ ÀÂÒÎÐÀ, ×ÜÞ ÏÅÑÍÞ ÕÎÒÈÒÅ ÄÎÁÀÂÈÒÜ Â ÑÏÈÑÎÊ  |\n";
                            cout << "\t\t\t   |     ÈËÈ ÑÎÎÒÂÅÒÑÒÂÓÞÙÈÉ ÏÓÍÊÒ ÄËß ÂÛÕÎÄÀ Â ÃËÀÂÍÎÅ ÌÅÍÞ:   |\n";
                            cout << "\t\t\t   --------------------------------------------------------------\n";
                            cout << "\t\t\t                                ";
                            int tmpOption2 = CheckForCorrect(tmpCountOfAuthors1 + 1);
                            system("cls");

                            if (tmpOption2 == tmpCountOfAuthors1)
                            {
                                break;
                            }
                            else
                            {
                                string filename = "Lyrics.txt";
                                ifstream fileIn;
                                fileIn.open(filename);
                                if (fileIn.fail())
                                {
                                    cout << "Error opening file!\a";
                                    return 404;
                                }
                                int countOfSongs = ++songwriter[tmpOption2 - 1].n;
                                Song* songs = new Song[countOfSongs];
                                songwriter[countOfAuthor - 1].songs = songs;

                                cout << "Ââåäèòå èìÿ àâòîðà: ";
                                getline(cin, songwriter[tmpOption2 - 1].songwriter_sName);
                                cout << "Ââåäèòå íàçâàíèå ïåñíè: ";
                                getline(cin, songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].nameOfSong);
                                cout << "\n Èçâåñòåí ëè âàì ãîä âûïóñêà ýòîé ïåñíè?\n1.) Äà\n2.) Íåò\n";
                                int tmpOption3 = CheckForCorrect(3);
                                if (tmpOption3 == 1)
                                {
                                    songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].yearIsKnown = true;
                                    cin >> songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].yearOfRelease;
                                    cin.ignore();
                                    system("cls");
                                }
                                else
                                {
                                    songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].yearIsKnown = false;
                                    system("cls");
                                }

                                int countOfStrings = 1;

                                while (!fileIn.eof())
                                {
                                    string line;
                                    getline(fileIn, line);
                                    if (line == "")
                                    {
                                        songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].lyricOfSong += "\n";
                                    }
                                    line += "\n";
                                    songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].lyricOfSong += line;
                                    ++countOfStrings;
                                }
                                songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].lyricOfSong[songwriter[tmpOption2 - 1].songs[songwriter[tmpOption2 - 1].n - 1].lyricOfSong.length() - 1] = '\0';
                                fileIn.close();
                                cout << "Ãîòîâî!\n";
                                system("pause");
                                system("cls");
                            }
                        }
                        else if (tmpOption1 == 2)
                        {
                            string filename = "Lyrics.txt";
                            ifstream fileIn;
                            fileIn.open(filename);
                            if (fileIn.fail())
                            {
                                cout << "Error opening file!\a";
                                return 404;
                            }
                            ++countOfAuthor;
                            songwriter = AddAuthor(songwriter, countOfAuthor);
                            int countOfSongs = 1;
                            Song* songs = new Song[countOfSongs];
                            songwriter[countOfAuthor - 1].n = countOfSongs;
                            songwriter[countOfAuthor - 1].songs = songs;
                            cout << "Ââåäèòå èìÿ àâòîðà: ";
                            getline(cin, songwriter[countOfAuthor - 1].songwriter_sName);
                            cout << "Ââåäèòå íàçâàíèå ïåñíè: ";
                            getline(cin, songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].nameOfSong);
                            cout << "\n Èçâåñòåí ëè âàì ãîä âûïóñêà ýòîé ïåñíè?\n1.) Äà\n2.) Íåò\n";
                            int tmpOption3 = CheckForCorrect(3);
                            if (tmpOption3 == 1)
                            {
                                songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].yearIsKnown = true;
                                cin >> songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].yearOfRelease;
                                cin.ignore();
                                system("cls");
                            }
                            else
                            {
                                songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].yearIsKnown = false;
                                system("cls");
                            }

                            int countOfStrings = 1;

                            while (!fileIn.eof())
                            {
                                string line;
                                getline(fileIn, line);
                                if (line == "")
                                {
                                    songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong += "\n";
                                }
                                line += "\n";
                                songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong += line;
                                ++countOfStrings;
                            }
                            songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong[songwriter[countOfAuthor - 1].songs[songwriter[countOfAuthor - 1].n - 1].lyricOfSong.length() - 1] = '\0';
                            fileIn.close();
                            cout << "Ãîòîâî!\n";
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
                    
                }

            }


        }
        else if (option == 3)
        {

        }

    }

    delete[] songwriter;
    return 0;
    system("pause");
}