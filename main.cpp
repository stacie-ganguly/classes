//the main file

#include <iostream>
#include "allMedia.h"
#include "movies.h"
#include <cstring>
#include <vector>

using namespace std;

void addMedia(vector<Media*>& database);

int main () {

  vector <Media*> database;
  
  char user_input[50];
  //char media_type[50];

  bool running = true;

  while(running == true) {
  
    cout << "What would you like to do? (ADD, SEARCH, DELETE): ";
    cin >> user_input;

    if(strcmp(user_input, "ADD") == 0) {
      cout << "You are adding now..." << endl;
      addMedia(database);
    }

  }

  return 0;
}

//my main functions

//defining the ADD function

void addMedia(vector<Media*>& database) {
  char media_type[50];
  
  cout << "What type of media are you adding to the database? (Movies, Music, VideoGames): ";
  cin >> media_type;
  cin.ignore(1000,'\n');

  char title[50];
  int year;

  cout << "Enter the title: ";
  cin.get(title, 50);
  cin.ignore(1000, '\n');
  
  
  cout << "Enter the year it was made: ";
  cin >> year;

  //IF ITS MOVIES
  if(strcmp(media_type, "Movies") == 0) {
    char director[50];
    float rating;
    int duration;

    cout << "Enter the director's name; ";
    cin >> director;
    cin.get(director, 50);
    cin.ignore(1000, '\n');
    

    cout << "Enter the movie's rating (out of 5: ";
    cin >> rating;

    cout << "Enter the duration (in mins): ";
    cin >> duration;

    database.push_back(new movies (title, director, duration, year, rating));
    cout << "Movie added successfully!" << endl;

  } else if(strcmp(media_type, "Music") == 0) {
    char artist[50];
    int duration;
    char publisher[50];

    cout << "Enter the artist's name: ";
    cin >> artist;
    cin.get(artist, 50);
    cin.ignore(1000, '\n');

    cout << "Enter the duration (in mins): ";
    cin >> duration;

    cout << "Enter the publisher: ";
    cin >> publisher;
    cin.get(publisher, 50);
    cin.ignore(1000, '\n');

    database.push_back(new music (title, artist, duration, year, publisher));
    cout << "Song added successfully!" << endl;
  }

					 
}
