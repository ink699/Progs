#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#define last 255
#define send 1
#define recieve 0

int main()
{
  char* c;
  char path[] = "filemsg.cpp";
  int id = 0, len = 0;
  key_t key;
  string filename;
  cin >> filename;
  ofstream out(filename);
  struct mymsgbuf
  {
    long type;
    char text [1];
  } mybuf;
  if((key = ftok(path, 0)) < 0)
  {
    exit(-1);
  }
  if((id = msgget(key, 0666 | IPC_CREAT)) < 0)
  {
    exit (-1);
  }
  for(;;)
  {
    if((len = msgrcv(id, &mybuf, 100, 0, 0)) < 0)
    {
      msgctl(id, IPC_RMID, NULL);
      exit(-1);
    }
    if(mybuf.type == last)
    {
      out << endl;
      msgctl(id, IPC_RMID, NULL);
      exit(-1);
    }
    out << (mybuf.text)[0];
  }
  msgctl(id, IPC_RMID, NULL);;
  return 0;
}
