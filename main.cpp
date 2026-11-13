//the main file

#include <iostream>
#include "allMedia.h"
#include "movies.h"
#include "music.h"
#include "videoGames.h"
#include <cstring>
#include <vector>

using namespace std;

void addMedia(vector<Media*>& database);
void searchMedia(const vector<Media*>& database);
void deleteMedia(vector<Media*>& database);

int main () {

  vector <Media*> database;
  
  char user_input[50];
  //char media_type[50];

  bool running = true;

  while(running == true) {
  
    cout << "What would you like to do? (ADD, SEARCH, DELETE, or QUIT): ";
    cin >> user_input;

    if(strcmp(user_input, "ADD") == 0) {
      cout << "You are adding now..." << endl;
      addMedia(database);
    } else if(strcmp(user_input, "SEARCH") == 0) {
      cout << "You are searching now.." << endl;
      searchMedia(database);
    } else if(strcmp(user_input, "DELETE") == 0) {
      cout << "You are now deleting.." << endl;
      deleteMedia(database);
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
    //cin.get(director, 50);
    cin.ignore(1000, '\n');
    

    cout << "Enter the movie's rating (out of 5: ";
    cin >> rating;

    cout << "Enter the duration (in mins): ";
    cin >> duration;

    database.push_back(new movies (title, director, duration, year, rating));
    cout << "Movie added successfully! Total number of items in database: " << database.size() << endl;

    // IF ITS MUSIC INSTEAD
  } else if(strcmp(media_type, "Music") == 0) {
    char artist[50];
    int duration;
    char publisher[50];

    cout << "Enter the artist's name: ";
    cin >> artist;
    //cin.get(artist, 50);
    cin.ignore(1000, '\n');

    cout << "Enter the duration (in mins): ";
    cin >> duration;

    cout << "Enter the publisher: ";
    cin >> publisher;
    //cin.get(publisher, 50);
    cin.ignore(1000, '\n');

    database.push_back(new music (title, artist, duration, year, publisher));
    cout << "Song added successfully! Total number of items in database: " << database.size() << endl;


  //IF ITS VIDEO GAMES INSTEAD

  } else if(strcmp(media_type, "VideoGames") == 0) {
  
    char publisher[50];
    float rating;
    
    cout << "Enter the rating (out of 10): ";
    cin >> rating;

    cout << "Enter the publisher: ";
    
    cin.getline(publisher, 50);
    cin.ignore(1000, '\n');

    database.push_back(new games (title, rating, year, publisher));
    cout << "Video Game added successfully! Total number of items in database: " << database.size() << endl;
  }

					 
}

//finding media function - to use in search and delete function

vector<int> findMedia(const vector<Media*>& database) {
  //searching
  char searchType[10]; //user will be asked to search with either title or year
  cout << "What would you like to search with? (title, year): ";
  cin >> searchType;
  cin.ignore(1000, '\n');

  vector<int> matching; 

  if(strcmp(searchType, "title") == 0) {
    char searchTitle[50]; //what title they are looking for

    cout << "Enter the title you are looking for: ";
    cin >> searchTitle;
    cin.ignore(1000,'\n');

    for(size_t i = 0; i < database.size(); i++) {
      if(strcmp(database[i]->getTitle(), searchTitle) == 0) {
	matching.push_back(i);
      }
    }
  } else if(strcmp(searchType, "year") == 0) {
    int searchYear;

    cout <<"Enter the year you are looking for: ";
    cin >> searchYear;

    for(size_t i = 0; i < database.size(); i++) {
      if(database[i]->getYear() == searchYear) {
	matching.push_back(i);
      }
    }

  }

  return matching;
}

//search function

void searchMedia(const vector <Media*>& database) {
//checking if its empty
  if(database.empty()) {
    cout << "Database is empty. Nothing to search! Try adding something" << endl;
    return;
  }

  vector <int> matches = findMedia(database);

  if(matches.empty()) {
    cout << "No matching items in the database!" << endl;
    return;
  }

  cout << "----------Search Results----------" << endl;
  for(size_t i = 0; i < matches.size(); i++) {
    int index = matches[i];

    cout << "Index " << i << endl;
    database[index]->printInfo();
    cout << " -----------------------------" << endl;
    
  }
  
}

//delete function 

void deleteMedia(vector<Media*>& database) {
//checking if its empty
  if(database.empty()) {
    cout << "Database is empty. Nothing to search! Try adding something" << endl;
    return;
  }

  vector <int> matches = findMedia(database);
  if(matches.empty()) {
    cout << "No matching items in the database!" << endl;
    return;
  }
  
  cout << "----------Items to delete----------" << endl;
  for(size_t i = 0; i < matches.size(); i++) {
    int index = matches[i];

    cout << "Index " << i << endl;
    database[index]->printInfo();
    cout << " -----------------------------" << endl;
    
  }

  //confirm if you wanna delete

  char user_confirm[10];

  cout << "Are you sure you want to delete those items (yes/no)" << endl;

  cin >> user_confirm;
  cin.ignore(1000, '\n');

  if(strcmp(user_confirm, "yes") == 0) {

    //safely deleting highest index to lowest index 
    for(int i = matches.size() - 1; i >=0; i--) {
      int targetIndex = matches[i];

      delete database[targetIndex];

      database.erase(database.begin() + targetIndex);
    
    }

    cout << "Successfully deleted the items!" << endl;
  } else {

    cout << "Deletion Canceled" << endl;

  }
  
}
