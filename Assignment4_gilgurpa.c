
#include<stdio.h>
#include<string.h>

void insertionSort(int[], int);
void merge(int[], int, int, int);
void mergeSort(int[], int, int);
void print(int[], int);
int comparisions = 0; //counter to check the number of comparisions.

int main()
{
	char file [20]; //to store the filename
	FILE * fp; //pointer to iterate through the file
	int numLines = 18; //denotes the total number of lines or the number of elements in the file
	int size = numLines-1;
	int hi = size;
	int lo = 0;
	int numbers[numLines]; //array storing the numbers retrieved from the file
	
	strcpy(file, "numbers.txt");//assigning the filename to the variable 'file'

	fp = fopen(file, "r"); //creating a file object

	if(fp == NULL)
	{
		printf("\nFile not found\n"); //display this msg if file doesnot exist
	}
	else
	{
		printf("The numbers read from the file are: \n");

		for(int i = 0; i<numLines; i++)
		{
			fscanf(fp,"%d",&numbers[i]);//assigning values to array
			printf("%d ",numbers[i]);//printing the original order of numbers stored in the array
		}

		fclose(fp);
	}
	
	printf("\n\nThe elements in the sorted order with insertion sort in descending order are:\n");
	insertionSort(numbers, size); //calling insertion sort method
	print(numbers, size); //calling the print method
	printf("The number of comparisions: %d\n\n", comparisions);
	
	comparisions = 0;//assigning the value back to 0 for merge sort

	printf("The elements in the sorted order with merge sort in descending order are:\n");
	mergeSort(numbers, lo, hi);//calling the merge sort method
	print(numbers, numLines);
	printf("The number of comparisions: %d\n\n", comparisions);
	
	return 0;
}

void insertionSort(int A[], int size)
{
	int i, j, key;

	for(j=1; j<size; j++)
	{
		key = A[j];
		i = j-1;

		while(i>=0 && A[i]<key) //comparision happens in this loop
		{
			A[i+1] = A[i];
			i--;
			comparisions++;
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
	int temp[hi+1];
	int i, j, k;
	
	i=lo;
	j=mid+1;
	k=0;

	while(i<=mid && j<=hi) //this loop compares and sorts the nubers accordingly.
	{
		comparisions++;

		if(A[i]>A[j])
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
}

void print(int A[], int size)
{
	for(int i=0; i<size; i++) 
	{
		for(int j=i+1; j<size; j++) 
		{
			if (A[i] == A[j]) //checks for duplicacy
			{ 				 //if duplicate values are present, only one of thevalue is considered
							//and the index as well as the values of other follwing numbers is adjusted accordingly
				for(int k=j; k<size; k++) 
				{
					A[k] = A[k+1]; 
				}
				size --; //since we remove one duplicate value, size of array is reduced
				j --;
			}
		}
		printf("%d ", A[i]);
	}
	printf("\n");
}

