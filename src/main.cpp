#include <iostream>
#include <vector>

#include "base64.h"

using std::cout;
using std::endl;

int main(int argc, char** argv)
{
  // TBD: Support command line args?
  cout << "Encode\n";

  // Simply using the Thomas Hobbes's Leviathan example from Wikipedia to do basic testing
  cout << "'TQ==' : " << base64encode("M") << endl;
  cout << "'TWE=' : " << base64encode("Ma") << endl;
  cout << "'TWFu' : " << base64encode("Man") << endl;
  cout << "'TWFuIA==' : " << base64encode("Man ") << endl;
  cout << "'TWFuIGk=' : " << base64encode("Man i") << endl;
  cout << "'TWFuIGlz' : " << base64encode("Man is") << endl;

  cout << "Decode\n";

  cout << "'M' : " << base64decode("TQ==") << endl;
  cout << "'Ma' : " << base64decode("TWE=") << endl;
  cout << "'Man' : " << base64decode("TWFu") << endl;
  cout << "'Man ' : " << base64decode("TWFuIA==") << endl;
  cout << "'Man i' : " << base64decode("TWFuIGk=") << endl;
  cout << "'Man is' : " << base64decode("TWFuIGlz") << endl;

  return 0;
}
