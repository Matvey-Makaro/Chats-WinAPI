#include "server.h"

#include <iostream>
using namespace std;

int main()
{
  Server s(8888);
  s.run();

  return 0;
}