//ACTUAL movie class

#include "movies.h"
#include <iostream>

using namespace std;

movies::movies(const char title[50], const char director[50], int duration, int year, float rating): Media(title, year) {
  strcpy(this->director, director);
  this-> duration = duration;
  this-> rating = rating;
}

movies::~movies() {}

const char* movies::getDirector() const {
  return director;
}

int movies::getDuration() const {
  return duration;
}

float movies::getRating() const {
  return rating;
}

int movies::getType() const {
  return 3;
}


void movies::printInfo() const {
  Media::printInfo();
  cout << "Director: " << director << endl;
  cout << "Duration: " << duration << endl;
  cout << "Rating: " << rating << endl;
}

			      
			  
