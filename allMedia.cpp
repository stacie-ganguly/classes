//ALL MEDIA cpp file

#include <iostream>
#include <cstring>
#include "allMedia.h"

using namespace std;

Media::Media(const char* t, int y) {
  strcpy(title, t);
  year = y;
}

Media::~Media() {}

const char* Media::getTitle() const {
  return title;
}

int Media::getYear() const {
  return year;
}

int Media::getType() const {
  return 0; //the default one
}
void Media::printInfo() const {
  cout << "Tile: " << title << endl;
  cout << "Year Released: " << year << endl;
}

