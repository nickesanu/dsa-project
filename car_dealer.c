#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list_1
{
	char brand[20];
	int year;
	int price;
    struct list_1 *next;
};
typedef struct list_1 node;
node *first=NULL, *last=NULL,*search;
void afisare();
void introducere(char brand1[],int year1, int price1);
int main()
{
	int price1,year1,ok,year2;
	long price2=999999;
	char brand1[20], answer[5], wish[20];
    while(1)
	{
	printf("\nBrand of the car:"); 
	scanf("%s",&brand1);
	printf("\nYear of fabrication:"); 
	scanf("%d",&year1);
	printf("\nPrice of the car:"); 
	scanf("%d",&price1);
    introducere(brand1,year1,price1);
    printf("\nWould you like to add another car?(yes/no)\n ");
	scanf("%s", &answer);
    if(strcmp(answer,"no")==0)
            break;
	}
    afisare();
	printf("\nType the brand of the car you would like to purchase:\n");
	scanf("%s",&wish);
	search=first;
	while(search!=NULL)//The search criteria is the newest car available. If more cars were produced in the same year, we choose the cheapest
	{
		if(strcmp(search->brand,wish)==0)
		{
		if(search->year>year2)
		{
			year2=search->year;
			price2=search->price;
			ok=1;
		}
		else if(search->year==year2)
		{
		if(search->price<price2)price2=search->price;
		}
		}
		search=search->next;
	}
	if(ok==0)
	printf("We don't own this brand of car");
	else {
		printf("%s\t",wish);
		printf("%d\t",year2);
		printf("%d\n",price2);
	}
    return 0;
}
void introducere(char brand1[],int year1,int price1)
{
  node *temp_node;
  temp_node=(node*)malloc(sizeof(node)); 
  temp_node->price=price1;
  temp_node->year=year1;
  strcpy(temp_node->brand,brand1);
  temp_node->next=NULL;
    if(first==NULL)
    {
        first=temp_node;
        last=temp_node;
    }
    else
    {
        last->next=temp_node;
        last=temp_node;
    }
}
void afisare()
{
printf("\nYour list of cars is:\n") ;
node *list_cars;
list_cars=first;
while(list_cars!=NULL)
{
printf("%s\t",list_cars->brand);
printf("%d\t",list_cars->year);
printf("%d\n",list_cars->price);
list_cars=list_cars->next;
}
}
