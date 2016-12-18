#include<string.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct house
{
	char beverage[100];
	char color[100];
	char nationality[100];
	char pet[100];
	char cigar[100];
	int left;
	int right;
	int used;
}abc;


int search(struct house** h, int par)
{	int i=0;
	char a[100];
	switch(par)
	{
		case 1:
			printf("Enter bev: ");
			scanf("%s",a);
			for(i=0;i<5;i++)
			{
				if(strcmp(h[i]->beverage,a)==0)
					break;
			}
			if(i==5)
			{
			int j;
			for(j=0;j<5;j++)
				if(h[j]->used == 0){
					h[j]->used = 1;
					strcpy(h[j]->beverage,a);
					return j;
				}
			if(j==5)
				return -1;
			}else
			return i;	
		break;
		case 2:
			printf("Enter col: ");
			scanf("%s",a);
			for(i=0;i<5;i++)
			{
				if(strcmp(h[i]->color,a)==0)
					break;
			}
			if(i==5)
			{
			int j;
			for(j=0;j<5;j++)
				if(h[j]->used == 0){
					h[j]->used = 1;
					strcpy(h[j]->color,a);
					return j;
				}
			if(j==5)
				return -1;
			}else
			return i;	
		break;
		case 3:
		printf("Enter nationality: ");
			scanf("%s",a);
			for(i=0;i<5;i++)
			{
				if(strcmp(h[i]->nationality,a)==0)
					break;
			}
			if(i==5)
			{
			int j;
			for(j=0;j<5;j++)
				if(h[j]->used == 0){
					h[j]->used = 1;
					strcpy(h[j]->nationality,a);
					return j;
				}
			if(j==5)
				return -1;
			}else
			return i;	
		break;
		case 4:
		printf("Enter pet: ");
			scanf("%s",a);
			for(i=0;i<5;i++)
			{
				if(strcmp(h[i]->pet,a)==0)
					break;
			}
			if(i==5)
			{
			int j;
			for(j=0;j<5;j++)
				if(h[j]->used == 0){
					h[j]->used = 1;
					strcpy(h[j]->pet,a);
					return j;
				}
			if(j==5)
				return -1;
			}else
			return i;			
			
		break;
		case 5:
		printf("Enter cigar: ");
			scanf("%s",a);
			for(i=0;i<5;i++)
			{
				if(strcmp(h[i]->cigar,a)==0)
					break;
			}
			if(i==5)
			{
			int j;
			for(j=0;j<5;j++)
				if(h[j]->used == 0){
					h[j]->used = 1;
					strcpy(h[j]->cigar,a);
					return j;
				}
			if(j==5)
				return -1;
			}
			else
			return i;			
			
		break;
		
	}
	
}


				

int main()
{
	abc** h=(abc**)malloc(sizeof(abc*)*5);
	int i;
	for( i=0;i<5;i++)
	{
		h[i]=(abc*)malloc(sizeof(abc));
	}

	for(i=0;i<5;i++)
	{
		h[i]->used=0;
		h[i]->left = -1;
		h[i]->right = -1;
	}
	int ch;
	char a[100];
	while(1)
	{       int par;
		printf("Search by? ");
		scanf("%d",&par);
		int o,new,i;
		if(par==-1)
			ch=8;
		else
		{
		
		printf("Enter choice:\n1.Add nationality\n2.Add beverage\n3.Add pet\n4.Add color\n5.Add cigar\n6.Add left house\n7.Add right house\n");
		 		
		scanf("%d",&ch);
		if(ch==6 || ch ==7);
		else{
		if(par==6){
			printf("Enter index: ");
			scanf("%d",&i);
			if(h[i]->used==0)
				h[i]->used=1;
		}
		else{
		i = search(h,par);}
		if(i==-1)
		{
			printf("ALL OUT!!!\n");
			ch=8;
		}
		else
		{printf("Added value: ");
		scanf("%s",a);}
		}
		}
		
		
		switch(ch)
		{
			case 1:
				strcpy(h[i]->nationality,a);
				break;
			case 2: strcpy(h[i]->beverage,a);
				break;
			case 3:
				strcpy(h[i]->pet,a);
				break;
			case 4:
				strcpy(h[i]->color,a);
				break;
			case 5:
				strcpy(h[i]->cigar,a);
				break;					
			case 6:
				printf("Parameter, original: ");
				scanf("%d",&o);
				printf("Parameter, new: ");
				scanf("%d",&new);
				if(o==6){
					printf("Index: ");
					scanf("%d",&o);
					}
				else
				o = search(h,o);
				if(new==6){
					printf("Index: ");
					scanf("%d",&new);
					}
				else
				new = search(h,new);
				h[o]->left = new;
				h[new]->right=o;
				break;
			case 7:
				printf("Parameter, original: ");
				scanf("%d",&o);
				printf("Parameter, new: ");
				scanf("%d",&new);
				if(o==6){
					printf("Index: ");
					scanf("%d",&o);
					}
				else
				o = search(h,o);
				if(new==6){
					printf("Index: ");
					scanf("%d",&new);
					}
				else
				new = search(h,new);
				h[o]->right = new;
				h[new]->left=o;
				break;
			case 8: 
				;
				int j;
				for(j=0;j<5;j++)
				{
					if(h[j]->used == 1)
						printf("________________\nIndex: %d \nLeft: %d Right: %d\n\n\n",j,h[j]->left,h[j]->right);
				}
				for(j=0;j<5;j++)
				{
					if(h[j]->used == 1){
						printf("Index %d\n",j);
						printf("Beverage: %s\n",h[j]->beverage);
						printf("Color: %s\n",h[j]->color);
						printf("Nationality: %s\n",h[j]->nationality);
						printf("Pet: %s\n",h[j]->pet);
						printf("Cigar: %s\n\n\n",h[j]->cigar);
					}
				}
				break;
			}
		}
}

