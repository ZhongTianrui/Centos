#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include"RingQueue.hpp"

using namespace std;

void* producter(void* arg)
{
  RingQueue<int>* p = (RingQueue<int>*) arg;
  srand(time(NULL));
  while(1)
  {
    int data = rand()%100;
    p->Push(data);
    cout<<"product data: "<<data<<endl;
    sleep(1);
  }
}
void* consumer(void* arg)
{
  RingQueue<int>* p = (RingQueue<int>*) arg;
  int data;
  while(1)
  {
    p->Pop(data);
    cout<<"consumer data: "<<data<<endl;
    sleep(1);
  }
}
int main()
{
  pthread_t tid1,tid2;
  RingQueue<int> p;

  pthread_create(&tid2,NULL,consumer,&p);
  pthread_create(&tid1,NULL,producter,&p);

  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  return 0;
}
