#ifndef QUEUEP_H
#define QUEUEP_H

#endif // QUEUEP_H
#define PRIORITES 5
#include <stdlib.h>


 static int ItemMessage, MAX_MESSAGE;

typedef struct Message
{
 char _Data;
 unsigned int _Priority;
struct Message *NextMessage, *FirstMessage, *Previous, *LastMessage;
}Message; Message *first, *Item, *Last, *PriorityNumbers[PRIORITES];




void AddMessageToQueue(char Data, unsigned int Priority)
{
    unsigned int i = 0;
 Message *newmessage = (Message*)malloc(sizeof(Message));

 newmessage->_Data = Data;
 newmessage->_Priority = Priority;
if(ItemMessage >= MAX_MESSAGE )
{
   i=PRIORITES;
    while(PriorityNumbers[i-1]==NULL){i=i-1;}
    Last = PriorityNumbers[i-1];
    Item = PriorityNumbers[i-1]->Previous;
   if(PriorityNumbers[i-1]->Previous != NULL)
   {

       PriorityNumbers[i-1] = PriorityNumbers[i-1]->Previous;
       PriorityNumbers[i-1]->NextMessage = NULL;
       free(Last);


   }
   else
   {
      PriorityNumbers[i-1] = NULL;
      i=i-1;
     while(PriorityNumbers[i-1]==NULL){i=i-1;}
    // printf("%d%c",i,PriorityNumbers[i-1]->_Data);
     PriorityNumbers[i-1]->NextMessage = NULL;

      free(Last);



   }

       ItemMessage=ItemMessage-1;

i = 0;
}

if(ItemMessage==0)
 {
     first = newmessage;
     PriorityNumbers[Priority-1] = newmessage;
     PriorityNumbers[Priority-1] ->FirstMessage = newmessage;
     PriorityNumbers[Priority-1] ->Previous =  NULL;
     PriorityNumbers[Priority-1] ->LastMessage = newmessage;
     PriorityNumbers[Priority-1] ->NextMessage = NULL;
     ItemMessage = 1;
 }
 else
  {

   if(PriorityNumbers[Priority-1]!=NULL)
   {

       newmessage->NextMessage = PriorityNumbers[Priority-1]->NextMessage;
       newmessage->FirstMessage = PriorityNumbers[Priority-1]->FirstMessage;
       newmessage->Previous = PriorityNumbers[Priority-1];
       newmessage->LastMessage = PriorityNumbers[Priority-1]->LastMessage;
       PriorityNumbers[Priority-1]->NextMessage = newmessage;
       PriorityNumbers[Priority-1] = newmessage;

   }
   else
   {

       PriorityNumbers[Priority-1] = newmessage;
       PriorityNumbers[Priority-1] ->FirstMessage = newmessage;
       PriorityNumbers[Priority-1]->Previous =  NULL;
       PriorityNumbers[Priority-1]->LastMessage  = newmessage;
       PriorityNumbers[Priority-1]->NextMessage = NULL;


      Item =NULL;


        while(i < PRIORITES)
       {
        if(PriorityNumbers[i]!=NULL)
        {

          if(Item == NULL){  Item = PriorityNumbers[i];first =PriorityNumbers[i]->LastMessage/*printf("%c%d\n\n",PriorityNumbers[i]->_Data,i)*/;}
          else
          {

           Item->NextMessage= PriorityNumbers[i]->FirstMessage;
           Item = PriorityNumbers[i];
          }
        }
        i=i+1;
       }
   }

ItemMessage = ItemMessage + 1;
 }




}


Message GetMessageFromQueue()
{ Message m,*T;
  ItemMessage = ItemMessage - 1;
  T = first;
  m = *first;
  first = first->NextMessage;
  free(T);

   return m;
}
