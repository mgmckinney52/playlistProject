/* Mak Mckinney, Josiah Roark
 * CS202
 * Last Updated: 12/06/2022
 */
#include "playlist.h"
// other includes in .h file. Primarily Mak's idea

Node::Node(Song s){
	song = s;
	next = NULL;
}

Playlist::Playlist(){
	head = NULL;
	count = 0;// thus is what we iterate to track songs in the playlist
}

//deconstructor 
Playlist::~Playlist(){
	if (!empty()){ 
		Node *p = head; 

		while (p != NULL){
			Node *next = p -> next; 
			delete p;
			p = next; 
		}
	}
}

Node *Playlist::newNode(Song s){
	Node *node = new Node(s);
	node -> next = NULL; // so for now, the next node is null. but it cant stay that way right?

	count++; // new songs raise the counter
	return node; 
}


Node *Playlist::add(string s, string a){ // here we go
	Song temp;
	Song song;
	
	temp.songName = s;
	temp.artist = a;
	
	song = temp;

	Node *node = newNode(song);
	
	if (empty() == true){
		head = node;
		
	}
	else {
		Node *temp = head; 
		while (temp -> next != NULL){
			temp = temp->next; 
		}
		temp->next = node;
	}
	songs++;
	return node;
}

int Playlist::empty(){
	if (head != NULL){ // the head will not be NULL if any nodes have been made, right?
		return false;
	}
	else {
		return true;
	}
}

/*Inspired by GeeksForGeeks*/
void Playlist::rmNode(string s, string a){
	
	if (empty() == false){
		songs--;
		Song tempS;
		tempS.artist = a;
		tempS.songName = s;

		//cout << a;
		//cout << s;
		Node *p = head;
		
		Node *temp = NULL; 

		//first element contains key
		if (p != NULL && (a == p->song.artist) && (s == p->song.songName)){
			temp = p->next; 
			delete p; 
			return;
		}

		//if there is more to find
		while (p != NULL && (a != p->song.artist || s != p->song.songName)){
		    temp = p;
			p = p->next;
		}

		//song not in playlist to delete
		if (p == NULL){ 
			return;
		}

		temp->next = p->next;

		delete p; 
	}

}


Node *Playlist::getHead() {
	return head;
}

void Playlist::setName(string s){
	name = s;
}

string Playlist::getName(){
	return name;
}	

int Playlist::getSongs(){return songs;}

/*To give user ability to "play" through the playlist*/
void Playlist::print(){
	string name; 
	string artist; 
	
	if (empty() == false){
		
		cout << getName() << "\n";
		
		Node *crown = head; 
		while (crown != NULL){
			name = crown->song.songName;
			artist = crown->song.artist;
			
			std::cout << name << " " << artist << "\n";
			name.clear(); 
			artist.clear();
			crown  = crown -> next;
		}
		if (getSongs() != 1) cout << "Your playlist contains " << getSongs() << " songs.\n";
		else cout << "Your playlist contains 1 song.\n";
	}

	else if (empty() == true) { 
		cout << getName() << " contains no songs\n";
	}
}
