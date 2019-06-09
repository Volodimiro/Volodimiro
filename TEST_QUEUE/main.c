#include <stdio.h>
#include <queuep.h>

int main()
{

    Message p;
    unsigned int pr;
    char data;
    ItemMessage = 0;
    printf("\n ENTER MAX MESSAGES =  ");
    scanf("%u",&MAX_MESSAGE); printf("\n");
    printf(" \n ENTER FORMAT << CHAR & PRIORITY >> FOR END ENTERING, ENTER '#'\n\n");

  while(1)
  {
    printf(" CHAR = ");
        scanf(" %c", &data);
    if(data == '#')break;
    printf(" PRIORITY = ");
        scanf(" %u", &pr);
    if(pr > PRIORITES){printf("%s%u\n"," ENTER PRIORITY < ", PRIORITES );}
    else
     {AddMessageToQueue(data,pr);}
  }

    // AddMessageToQueue('s',5);
   /* AddMessageToQueue('d',1);
    AddMessageToQueue('f',1);
    AddMessageToQueue('g',5);
    AddMessageToQueue('k',4);

    AddMessageToQueue('m',4);
    AddMessageToQueue('m',3);
    AddMessageToQueue('b',1);
    AddMessageToQueue('b',3);*/
//AddMessageToQueue('l',5);

     while(first!=NULL)
    {
     p = GetMessageFromQueue();
     printf(" %c%d\n",p._Data,p._Priority,ItemMessage);
    }
  if(first==NULL)printf("\n EXIT");
scanf(" %c", &data);
    return 0;
}
