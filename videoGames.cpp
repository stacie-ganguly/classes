//video games child class

#include "videoGames.h"
#include <iostream>

using namespace std;

games::games(const char title[50], float rating, int year, const char publsiher[50]): Media(title,year) {
  strcpy(this->publisher, publisher);
  this-> rating = rating;
}

games::~games() {}

const char* games::getPublisher() const {
  return publisher;
}

float games::getRating() const {
  return rating;
}

int games::getType() const {
  return 1;
}

void games::printInfo() const {
  Media::printInfo();
  cout << "Rating: " << rating << endl;
  cout << "Publisher: " << publisher << endl;
}
  
