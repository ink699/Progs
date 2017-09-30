#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
using namespace std;

int main()
{
    int a = open("42.txt", O_WRONLY);
    int b = 0;
    cout << "First " << a << endl;
    for(;;)
    {
      b = 0;
    }
}
