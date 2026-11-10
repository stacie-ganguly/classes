//ACTUAL music class

#include <iostream>
#include "music.h"

using namespace std;

music::music(const char title[50], const char artist[50], int duration, int year, const char publisher[50]): Media(title, year) {
  strcpy(this->artist, artist);
  strcpy(this->publisher, publisher);
  this-> duration = duration;
}

music::~music() {}

const char* music::getArtist() const {
  return artist;
}

int music::getDuration() const {
  return duration;
}

const char* music::getPublisher() const {
  return publisher;
}

int music::getType() const {
  return 2;
}
