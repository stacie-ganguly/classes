//ACTUAL movie class

#include "movies.h"
#include <iostream.

using namespace std;

movies(char title[50], char director[50], int duration, int year, float rating);

movies::~movies() {}

char movies::getDirctor() const {
  return director;
}

int movies::getDuration() const {
  return duration
}

float movies::getRating() const {
  return rating;
}

int movies::getType() const {
  return 3;
}


void movies::printInfo() const {
  allMedia::printInfo();
  cout << "Director: " << director << endl;
  cout << "Duration: " << duration << endl;
  cout << "Rating: " << rating << endl;
}

			      
			  
