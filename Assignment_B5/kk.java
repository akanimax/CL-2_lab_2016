/*
Assignment No: 9(Group B)
Assignment Name: Implement k-means for clustering data of children belonging to different age groups to perform some specific activities. Formulate the Feature vector for following parameters:
i. height
ii. weight
iii. age
iv. IQ
Formulate the data for 40 children to form 3 clusters.
Class: BE			Div: B
Roll No.: 56		Batch: Q4
*/

import java.io.*;
import java.lang.*;
class kk
{
public static void main(String args[])
{
int N=40;
int arr[]={2,4,10,12,3,20,30,11,25,56,76,45,35,65,2,34,12,21,34,65,45,34,23,12,65,45,34,78,67,54,32,12,66,99,76,56,45,78,67,56};
int i,m1,m2,m3,a,b,c,n=0;
boolean flag=true;
float sum1=0,sum2=0, sum3=0;
a=arr[0];b=arr[1]; c=arr[2];
m1=a; m2=b; m3=c;
int cluster1[]=new int[40],cluster2[]=new int[40],cluster3[]=new int[40];
for(i=0;i<40;i++)
    System.out.print(arr[i]+ "\t");
System.out.println();

do
{
 n++;
 int k=0,j=0, l=0;
 for(i=0;i<40;i++)
 {
    if(Math.abs(arr[i]-m1)<=Math.abs(arr[i]-m2))
    {   cluster1[k]=arr[i];
        k++;
    }
    else if (Math.abs(arr[i]-m2)<=Math.abs(arr[i]-m3))
    {   cluster2[j]=arr[i];
        j++;
    }
    else
    {
	cluster3[l]=arr[i];
	l++;
    }
 }
    System.out.println();
    for(i=0;i<40;i++)
        sum1=sum1+cluster1[i];
    for(i=0;i<40;i++)
        sum2=sum1+cluster2[i];
    for(i=0;i<40;i++)
        sum3=sum1+cluster3[i];
    a=m1;
    b=m2;
    c=m3;	
    m1=Math.round(sum1/k);
    m2=Math.round(sum2/j);
    m3=Math.round(sum3/l);
    if(m1==a && m2==b && m3==c)
        flag=false;
    else
        flag=true;

    System.out.println("\nAfter iteration "+ n +" , cluster 1 :\n");    
    for(i=0;i<40;i++)
        System.out.print(cluster1[i]+ "\t");

    System.out.println("\n");
    System.out.println("\nAfter iteration "+ n +" , cluster 2 :\n");
    for(i=0;i<40;i++)
        System.out.print(cluster2[i]+ "\t");

    System.out.println("\n");
    System.out.println("\nAfter iteration "+ n +" , cluster 3 :\n");
    for(i=0;i<40;i++)
        System.out.print(cluster3[i]+ "\t");

}while(flag==false);

    System.out.println("\nFinal cluster 1 :\n");            
    for(i=0;i<40;i++) 
       System.out.print(cluster1[i]+ "\t");

	System.out.println("\n");

    System.out.println("\nFinal cluster 2 :\n");
    for(i=0;i<40;i++)
        System.out.print(cluster2[i]+ "\t");

		System.out.println("\n");

    System.out.println("\nFinal cluster 3 :\n");
    for(i=0;i<40;i++)
        System.out.print(cluster3[i]+ "\t");

		System.out.println("\n");

 }
}
