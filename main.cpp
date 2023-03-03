/*  Mak Mckinney, Josiah Roark
 *  CS202
 *  12/03/2022
 *	last updated 12/7/2022
 *
 * C++ Program to replicate basic Spotify Playlist creation using a LinkedList
 */

#include "playlist.h"

using namespace std;

/* Menu Driver for Program*/
void printCommands(){
	cout << "P key             Create a new playlist.\n";
	cout << "N key             Rename an existing playlist.\n";
	cout << "A key             Add a song to an existing playlist.\n";
	cout << "D key             Delete a song from an existing playlist.\n";
	cout << "S key             Print the songs in the playlist.\n";
	cout << "Q key             Quit.\n";
	cout << "? key             Print Help with Commands.\n";
}

int main (int argc, char *argv[]){
	char command;

	string input;

	Playlist *p1 = new Playlist; 
	p1 -> setName("My Playlist");
	int lists = 0;

	printCommands(); 

	while (true){
		cout << "> ";
	
		cin.clear();
		cin >> command;

		/* Create a New Playlist */
		if (command =='P')  lists++;


		/*Rename Playlist*/
		else if (command == 'N' && lists > 0){
			cout << "Enter new playlist name: \n>";
			
			cin.clear();
			cin.ignore(); 
		
			getline(cin, input); 
			p1->setName(input);
		}


		/*Add new Song*/
		else if (command =='A' && lists > 0){ 
			cin.clear();
			Song s;
			cout << "Song Name: \n>";
			cin.ignore(); 
			getline(cin, input); 
			s.songName = input;
			cin.clear();
			cout << "Song Artist: \n>";
			getline(cin, input); 
			s.artist = input;
			p1->add(s.songName, s.artist);
		}

		/*delete song*/
		else if (command == 'D' && lists > 0){
				cin.clear();
				Song song;
				cout << "Enter song name: \n>";
				cin.ignore(); 
				getline(cin, input); 
				song.songName = input;
				cin.clear(); 
				cout << "Enter artist:\n>"; 
				getline(cin, input); 
				song.artist = input;
				cin.clear();
				p1->rmNode(song.songName, song.artist); 
				
		}

		//quit
		else if (command == 'Q') return 0;

		//"play" playlist
		else if (command == 'S'){
			if (p1->getSongs() > 0) p1->print();
			else cout << "This playlist is empty and cannot be played.\n";
		}

		//reprint commands
		else if (command == '?') cout << "Commands are case sensitive. Try to match input completely.\nBe sure that you have created the playlist before referencing it.\n";


		else cout << "Command not recognized. Attempt again.\n";
	}


	return 1;

}
