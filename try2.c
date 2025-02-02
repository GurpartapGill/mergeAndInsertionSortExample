/*
#include<stdio.h>
#define MAX 18
int f[MAX];
void insertionSort(int[]);
void merge(int[], int, int, int);
void mergeSort(int[], int, int);
void removeDuplicate(int[], int);

int main()
{
	FILE * fp;
	
	int i=0;
	fp = fopen("numbers.txt","r");
	if(fp==NULL)
		printf("File not exist");
	else{
		
		do
		{
			fscanf(fp,"%d",&f[i]);  // This will read the file and store the numbers into array
			i++;
		}while(!feof(fp));
		fclose(fp);
	}

	
	printf("The numbers read from the file are: ");

	for(int i = 0;i<sizeof(f)/sizeof(int);i++)
	{
		printf("%d ",f[i]);
	}
	
	printf("\n\n\n\nThe elements in the sorted order with insertion sort in descending order are: \n\n");

	insertionSort(f);
	removeDuplicate(f,17);

	printf("\n\nThe elements in the sorted order with merge sort in descending order are: ");

	mergeSort(f,0,17);
	printf("\n\n"); //added this
	
	removeDuplicate(f,18);

	
	printf("\n\n"); //added this

	return 0;
}

void insertionSort(int A[])
{
	int i, j, key;

	for(j=1; j<MAX-1; j++)
	{
		key = A[j];
		i = j-1;

		while(i>=0 && A[i]<key) // sign change kia
		{
			A[i+1] = A[i];
			i--;
		}

		A[i+1] = key;
	}
}
void mergeSort(int A[], int lo, int hi)
{
	if(lo<hi)
	{
		int mid = (lo+hi)/2;
		mergeSort(A,lo,mid);
		mergeSort(A,mid+1,hi);
		merge(A,lo,mid,hi);
	}
}

void merge(int A[], int lo, int mid, int hi)
{
	int temp[20];
	int i, j, k;

	i=lo;
	j=mid+1;
	k=0;

	while(i<=mid && j<=hi)
	{
		if(A[i]>A[j]) // sign change kia
		{
			temp[k] = A[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = A[j];
			j++;
			k++;
		}
	}

	while(i<=mid)
	{
		temp[k] = A[i];
		i++;
		k++;
	}

	while(j<=hi)
	{
		temp[k] = A[j];
		j++;
		k++;
	}

	for(i=lo, j=0; i<=hi; i++, j++)
	{
		A[i] = temp[j];
	}

	//printf("\n");
}

void removeDuplicate(int f[], int len)
{
	int c, d;

	//int len = sizeof(f)/sizeof(int);

	//

	//printf("\n\n\nTHE SIZE IS %d\n\n\n", len);

	//int len = MAX;
	for( c=0; c <len;c++)
	{
		for( d=c+1; d <len;d++)  //change of d+1 and d<size...
		{
			if(f[c]==f[d]) //change of array name a , b to f
			{
				for(int e=d; e<len; e++) 
				{
					f[e] = f[e+1]; 
				}
				len --; //since we remove one duplicate value, size of array is reduced
				d --;
			}
		}

		printf("%d ", f[c]);
	}
}
