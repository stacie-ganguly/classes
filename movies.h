//movie header file

#ifndef MOVIES_H
#define MOVIES_H

#include "allMedia.h"
#include <cstring>

using namespace std;

class movies : public Media {

private:
  char director[50];
  int duration;
  float rating; // out of 5

public:
  movies(const char* title, const char* director, int duration, int year, float rating);

  ~movies();

  //defining the getting methods

  const char* getDirector() const;
  int getDuration() const;
  float getRating() const;

  //

  void printInfo() const override;

  int getType() const override; //return 3 for movie
};

#endif
