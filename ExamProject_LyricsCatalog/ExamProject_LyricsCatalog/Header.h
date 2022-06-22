#pragma once
#ifndef LYRICS
#include <string>
using std::string;

int countOfAllSongs = 1;

struct Songs
{
	string songwriter_sName;
	string nameOfSong;
	string lyricOfSong;
	bool yearIsKnown;
	bool wordIsHere;
	int yearOfRelease;
};


int CheckForCorrect(int endOfRange);
int MainMenu();
int InputTextMenu();
void ShowListOfSongs(const Songs* obj);
Songs* AddSong(Songs* obj);
//int ShowListOfAuthors(const Songwriter* obj, int countOfAuthor);


#endif // !LYRICS
