// music header file

#ifndef MUSIC_H
#define MUSIC_H

#include "allMedia.h"
#include <cstring>

using namespace std;

class music : public Media {
 private:
  char artist[50];
  int duration;
  char publisher[50];

 public:
  music(const char* title, const char* artist, int duration, int year, const char* publisher);

  ~music();

  //defining THE methods

  const char* getArtist() const;
  int getDuration() const;
  const char* getPublisher() const;

  void printInfo() const override;

  int getType() const override; // return 2 for music
};

#endif			   
