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
  int i = 0, len = 0;
  cout << sizeof(string) << endl;
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
  for (;;)
  {
    mybuf.type = send;
    getline(cin, mybuf.text);
    cout << mybuf.text << endl;
    len = (mybuf.text).size() + 1;
    cout << len << endl;
    if(mybuf.text == "Exit")
    {
      mybuf.type = last;
      mybuf.text = "";
      if (msgsnd(id, (struct msgbuf *) &mybuf, 0, 0) < 0)
      {
        cout << "Fatal error" << endl;
        exit(-1);
      }
      msgctl(id, IPC_RMID, NULL);;
      exit(-1);
    }
    if (msgsnd(id, &mybuf, sizeof(mybuf.text), 0) < 0)
    {
      msgctl(id, IPC_RMID, NULL);
      exit(-1);
    }
  }
  return 0;
}
