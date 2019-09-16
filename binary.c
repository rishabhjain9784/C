#include<stdio.h>
int binarySearch(int arr[],int l,int r,int x) 
{ 
	while (l<=r) 
	{ 
		int m=l+(r-l)/2; 
		if(arr[m]==x) 
		return m; 
		if(arr[m]<x) 
		l=m+1; 
		else
		r=m-1; 
	} 
	return -1; 
} 
int main() 
{ 
	int arr[]={10,20,30,40,50,60}; 
	int n=sizeof(arr)/sizeof(arr[0]); 
	int x= 30;
	int e=binarySearch(arr,0,n-1,x);  
	if(e==-1)
	printf("\nelement is not present in an array\n");
	else
	printf("\nelement found at %d in array",e);
	return 0; 
} 
