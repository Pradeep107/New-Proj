#include <stdio.h>
//#include<conio.h>
#include <stdlib.h>
  struct hash *ht = NULL;
  int eCount = 0,ccount=0;
  char l[100];
  struct node {
	int key;
	struct node *next;
 };
  struct hash {
	struct node *head;
	int count;
  };
  struct node * createNode(int key)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->key = key;
	newnode->next = NULL;
	return newnode;
  }
void insert(int key) {
	int Index = key % eCount;
	struct node *newnode =  createNode(key);
		if (!ht[Index].head)
		{
		ht[Index].head = newnode;
		ht[Index].count = 1;
		return;
	}
	newnode->next = (ht[Index].head);
	ht[Index].head = newnode;
	ht[Index].count++;
	return;
  }

  void display() {
	struct node *myNode;
	int i;
	for (i = 0; i < eCount; i++) {
		if (ht[i].count == 0)
			continue;
		myNode = ht[i].head;
		if (!myNode)
			continue;
		printf("\n\nData at index %d in Hash Table:\n", i);
		printf("key \n");
		printf("------\n");
		ccount=0;
		while (myNode != NULL) {
			printf("%-12d", myNode->key);
			ccount++;
			myNode = myNode->next;
		}
		printf("\nlenght of chain : %d",ccount);
		l[i]=ccount;
	}
	return;
  }
int main() {
	int n,x=1, key, ele,i,j,temp;

	printf("Enter the number of elements:");
	scanf("%d", &n);
	eCount = n;
	ht = (struct hash *)calloc(n, sizeof (struct hash));
	while (x==1) {
printf("Enter the key value:");
scanf("%d", &key);
insert(key);
scanf("%d",&x);
	}
display();
for(i=0;i<strlen(l);i++)
{
	for(j=i+1;j<strlen(l);j++)
	{
		if(l[i]>l[j])
		temp=(int)l[i];
		
	}
}
printf("\nthe longest chain in the chaining is %d\n",temp);
}

