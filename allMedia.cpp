//ALL MEDIA PARENT CLASS

#include <iostream>
#include <cstring>
#include "allMedia.h"

using namespace std;
//defining my parent class:
class Media {
public:
  int year;
  char title[50];



  virtual void printInfo () {
    cout << "Title and year!" << endl;
  }

};


