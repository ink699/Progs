#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

#define last 255
#define send 1
#define recieve 0

int main()
{
  int id;
  char path[] = "ms1.cpp";
  key_t key;
  int i = 0, len = 0, maxlen = 1000;
  struct mymsgbuf
  {
    long type;
    string text;
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
    (mybuf.text).resize(maxlen);
    cout << "aaa" << endl;
    if((len = msgrcv(id, &mybuf, maxlen, 0, 0)) < 0)
    {
      exit(-1);
    }
    cout << len << endl;
    cout << len << endl;
    /*if(mybuf.type == last)
    {
      msgctl(id, IPC_RMID, NULL);
      exit(-1);
    }*/
    cout << len << endl;
    cout << ((mymsgbuf) mybuf).text << endl;
  }
  return 0;
}
