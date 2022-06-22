#pragma once
#ifndef LYRICS
#include <fstream>
#include <string>
using std::string;
using std::ofstream;
using std::ifstream;

int countOfAllSongs = 1;

struct Songs
{
	string songwriter_sName;
	string nameOfSong;
	string lyricOfSong;
	bool yearIsKnown;
	bool wordIsHere = false;
	int yearOfRelease;
};


int CheckForCorrect(int endOfRange);
int MainMenu();
int InputTextMenu();
void ShowListOfSongs(const Songs* obj);
void InputTextFromKeyboard(Songs* obj);
void InputTextFromFile(Songs* obj, ifstream& fileIn);
Songs* AddSong(Songs* obj);
//int ShowListOfAuthors(const Songwriter* obj, int countOfAuthor);


#endif // !LYRICS
