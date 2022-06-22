#pragma once
#ifndef LYRICS

struct Song
{
	char songwriter_sName[50];
	char nameOfSong[50];
	char lyricOfSong[10000];
	bool yearIsKnown;
	bool wordIsHere;
	int yearOfRelease;
};


int CheckForCorrect(int endOfRange);
int ShowListOfSongs(const Songwriter* obj, int countOfAuthor);
int ShowListOfAuthors(const Songwriter* obj, int countOfAuthor);
Songwriter* AddAuthor(Songwriter* obj, int countOfAuthor);


#endif // !LYRICS
