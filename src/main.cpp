#include <iostream>

#include "base64.h"

using std::cout;
using std::endl;

int main()
{
  // Simply using the Thomas Hobbes's Leviathan example from Wikipedia to do basic testing
  /*
  cout << "TQ== : " << base64encode("M") << endl;
  cout << "TWE= : " << base64encode("Ma") << endl;
  cout << "TWFu : " << base64encode("Man") << endl;
  cout << "TWFuIA== : " << base64encode("Man ") << endl;
  cout << "TWFuIGk= : " << base64encode("Man i") << endl;
  cout << "TWFuIGlz : " << base64encode("Man is") << endl;
  */

  cout << base64decode("TWFu") << endl;

  return 0;
}

