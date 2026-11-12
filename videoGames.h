// video games header file

#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

#include "allMedia.h"
#include <cstring>

using namespace std;

class games : public Media {
 private:
  char publisher[50];
  float rating; //out of 10

 public:
  games(const char* title, float rating, int year, const char* publisher);

  ~games();

  //defining the methods

  const char* getPublisher() const;
  float getRating() const;

  void printInfo() const override;

  int getType() const override; //return 1 for video games

};

#endif
