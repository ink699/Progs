#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fcntl.h>
using namespace std;

int main()
{
    int b = open("ex1.cpp", O_WRONLY);
    int a = open("42.txt", O_WRONLY);
    cout << "Second " << a << endl;
    for(;;)
    {
      b = 0;
    }
}
