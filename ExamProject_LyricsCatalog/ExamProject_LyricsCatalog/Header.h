#pragma once
#ifndef LYRICS
#include <fstream>
#include <string>
using std::string;
using std::ofstream;
using std::ifstream;

struct Songs
{
	string songwriter_sName;
	string nameOfSong;
	string lyricOfSong;
	bool yearIsKnown;
	bool wordIsHere = false;
	string yearOfRelease;
};

struct SongsChar
{
	char songwriter_sName[100];
	char nameOfSong[200];
	char lyricOfSong[12000];
	bool yearIsKnown;
	bool wordIsHere = false;
	char yearOfRelease[10];
};



int CheckForCorrect(int endOfRange);
int MainMenu();
void InputText(Songs* obj, int countOfAllSongs);
int InputTextMenu();
int ChangeTextMenu();
int ShowListOfSongs(const Songs* obj, int countOfAllSongs);
Songs* InputTextFromKeyboard(Songs* obj, int& countOfAllSongs);
Songs* InputTextFromFile(Songs* obj, ifstream& fileIn, int& countOfAllSongs);
Songs* AddSong(Songs* obj, int countOfAllSongs);
//int ShowListOfAuthors(const Songwriter* obj, int countOfAuthor);


#endif // !LYRICS
