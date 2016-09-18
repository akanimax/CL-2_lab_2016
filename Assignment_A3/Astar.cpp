#include<stdio.h>
#include<stdlib.h>

int arr[3][3],swappos[3][3],currentboard[3][3];
int chkvar=1,chkcount;
int totmoves;
int findmoves();
void display();
int findbestmove();
int returngoalstate(int);
int swap();
int stoporcontinue();

int main()
{
	int i,j,num;
	printf("\n Please enter Initial Condition (row-wise): ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{			scanf("%d",&arr[i][j]);
		}
	}
	printf("\nInitial State\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(arr[i][j]==0)
			{
				printf("   ");
			}
			else
			{
				printf("%d  ",arr[i][j]);
			}
		}
		printf("\n");
	}
	num=swap();
	if(num==1)
	{
		printf("\nSuccess");
		printf("\n\nTotal Number of Moves : %d\n\n",totmoves);
	}

	return 0;
}
int swap()
{
	int temp,i,j,flag;

     repeat:
	flag=stoporcontinue();
	if(flag==1)
	{
		return 1;
	}
	findbestmove();
	goto repeat;
}

int findmoves()
{
	int i,j,swapcount=0,blanki,blankj;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			swappos[i][j]=99;
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(arr[i][j]==0)
			{
				blanki=i;
				blankj=j;
				break;
			}
		}
	}
	i=blanki;
	j=blankj;
	if(i-1>=0)
	{
		swappos[i-1][j]=1;
	}
	if(i+1<=2)
	{
		swappos[i+1][j]=1;
	}
	if(j-1>=0)
	{
		swappos[i][j-1]=1;
	}
	if(j+1<=2)
	{
		swappos[i][j+1]=1;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(swappos[i][j]==1)
			{
				swapcount++;
			}
		}
	}
	return swapcount;

}
int findbestmove()
{
	int i,j,k,l,count=-1,gs,max=-1,min=999,h=0,temparr[3][3];
	int swapi,swapj,blanki,blankj,temp;
	findmoves();
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(arr[i][j]==0)
			{
				blanki=i;
				blankj=j;
				break;
			}
		}
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(swappos[i][j]==1)
			{
				for(k=0;k<3;k++)
				{
					for(l=0;l<3;l++)
					{
						if(k==i && l==j)
						{
							temparr[k][l]=0;
						}
						else if(arr[k][l]==0)
						{
							temparr[k][l]=arr[i][j];
						}
						else
						{
							temparr[k][l]=arr[k][l];
						}
					}
				}
				/**********/
				for(k=0;k<3;k++)
				{
					for(l=0;l<3;l++)
					{
						count++;
						gs=returngoalstate(temparr[k][l]);
						currentboard[k][l]=abs(gs-count);
					 }
				}
				count=-1;
				for(k=0;k<3;k++)
				{
					for(l=0;l<3;l++)
					{
						if(currentboard[k][l]!=0)
						{
							h++;
						}
					}
				}

				/**********/

				swappos[i][j]=h+totmoves;
				h=0;
			}
		}
	}

	count=-1;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(swappos[i][j]!=99)
			{
				if(min>swappos[i][j])
				{
					min=swappos[i][j];
					swapi=i;
					swapj=j;
				}
			}
		}
	}

	temp=arr[swapi][swapj];
	arr[swapi][swapj]=arr[blanki][blankj];
	arr[blanki][blankj]=temp;
	totmoves++;

	display();
	

}
void display()
{
	int i,j;

	
	printf("\nStep %d\n",totmoves);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(arr[i][j]==0)
			{
				printf("   ");
			}
			else
			{
				printf("%d  ",arr[i][j]);
			}
		}
		printf("\n");
	}
}
int returngoalstate(int num)
{
	if(num==1)
	{
		return 0;
	}
	else if(num==2)
	{
		return 1;
	}
	else if(num==3)
	{
		return 2;
	}
	else if(num==4)
	{
		return 3;
	}
	else if(num==5)
	{
		return 4;
	}
	else if(num==6)
	{
		return 5;
	}
	else if(num==7)
	{
		return 6;
	}
	else if(num==8)
	{
		return 7;
	}
	else if(num==0)
	{
		return 8;
	}


}

int stoporcontinue()
{
	int i,j,count=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			count++;
			if(arr[i][j]!=0)
			{
			if(count!=arr[i][j])
			{
				return 0;
			}
			}
		}
	}
	if(count==9)
	{
		return 1;
	}

}
