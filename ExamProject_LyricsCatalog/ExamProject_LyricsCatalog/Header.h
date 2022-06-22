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


int CheckForCorrect(int endOfRange);
int MainMenu();
int InputTextMenu();
void ShowListOfSongs(const Songs* obj, int countOfAllSongs);
Songs* InputTextFromKeyboard(Songs* obj, int& countOfAllSongs);
void InputTextFromFile(Songs* obj, ifstream& fileIn, int& countOfAllSongs);
Songs* AddSong(Songs* obj, int countOfAllSongs);
//int ShowListOfAuthors(const Songwriter* obj, int countOfAuthor);


#endif // !LYRICS
