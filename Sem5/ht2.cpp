#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
#include <string>

class dpipe
{
protected:
  int txd[2];//parent - r, child - w
  int rxd[2];//parent - w, child - r
  int cpid = 0;
  int ppid = 0;
public:

}
