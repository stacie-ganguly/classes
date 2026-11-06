//media header file

#ifndef ALLMEDIA_H
#define ALLMEDIA_H

#include <cstring>

using namespace std;

//defining the prent class
class Media {
 protected:
  char title[50];
  int year;

 public:

  Media(const char* t, int y);

  virtual ~Media();

  const char* getTitle() const;
  int getYear() const;

  virtual void printInfo() const;
  virtual int getType() const;
};

#endif
