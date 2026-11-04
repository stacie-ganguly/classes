//the main file

#include <iostream>
#include "allMedia.h"
#include "movies.h"
#include <cstring>
#include <vector>

using namespace std;

int main () {

  vector <allMedia*> database;
  
  char user_input[50];
  //char media_type[50];

  
  cout << "What would you like to do? (ADD, SEARCH, DELETE): ";
  cin >> user_input;

  if(strcmp(user_input, "ADD") == 0) {
    cout << "You are adding now..." << endl;

    }
  }

  return 0;
}

//my main functions

//defining the ADD function

void addMedia(vector<allMedia*>& database) {
  char media_type[50];
  
  cout << "What type of media are you adding to the database? (Movies, Music, VideoGames): ";
  cin >> media_input;

  char title[50];
  int year;

  cout << "Enter the title: ";
  cin >> title;
  cin.ignore();
  getline(cin, title);
  
  cout << "Enter the year it was made: ";
  cin >> year;
  
  if(strcmp(media_input, "Movies") == 0) {
    char director[50];
    float rating;
    int duration;

    cout << "Enter the director's name; ";
    cin >> director;
    cin.ignore();
    getline(cin, director);

    cout << "Enter the movie's rating (out of 5: ";
    cin >> rating;

    cout << "Enter the duration (in mins): ";
    cin >> duration;

    database.push_back(new movies title, director, duration, year, rating);
    cout << "Movie added successfully!" << endl;

    
    
  }

					 
}
