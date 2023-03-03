/*  Mak Mckinney, Josiah Roark
	CS202
	Last Updated: 12/07/2022

	C++ Program to create a playlist
	*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;


struct Song{
	string songName, artist;
};

	
struct Node{
	Node (Song);
	Song song;
	Node *next;

};         


//table base containing songs  
class Playlist { 
	private: 
		Node *head;
		Node *newNode(Song);
		int count;
		string name =""; 
		int songs;

	public:
		Song song;
		
		Playlist();
		~Playlist();
		
		Node *add(string, string); 
		int empty();
		
		Node *getHead();
		
		void print(); 
		
		string getName();
		
		void setName(string);
		void rmNode(string, string);
		int getSongs();
};
