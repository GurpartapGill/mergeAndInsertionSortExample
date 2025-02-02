/*
//Header Files
#include <stdio.h>
#include<string.h>

//Function Decalaration
void insertionSort(int[], int, int);
void  mergeSort(int[], int, int);
void merge(int[], int, int, int);
void printSortedList(int[], int);

int count = 0; //Global variable to find out comparisions.

//Beginning of Main Function
int main(void) {
	int numbers[18];
	int low = 0, key = 0;
	int high = 18, size = 18 -1;
	FILE *f ; //Pointer object of file type

	//Opening file in a reading mode
	f=fopen("numbers.txt", "r");

	if(f == NULL) {
		printf("Error in opening the file");
	}
	else {
		//For loop to fetch data from the file and store numbers into an array
		printf("The numbers read from the file are: ");
		for (int i=0; i<18; i++) {
			//Storing numbers into array called numbers.
			fscanf(f, "%d", &numbers[i]); 
			printf("%d ", numbers[i]);
		}
		
		printf("\n\n");

		printf("The elements in the sorted order with insertion sort in descending order are: ");
		insertionSort(numbers, key, size);	//Calling of Insertion Sort function
		printSortedList(numbers, size);

		printf("The elements in the sorted order with merge sort in descending order are:");
		count = 0; //Reseting counter variable to 0 for the Merge Sort comparisions
		mergeSort(numbers, low, high-1);	//Calling of Merge Sort function
		printSortedList(numbers, high);
	}

	//Closing file
	fclose(f);
	return 0;
}

//Body of insertion sort
void insertionSort(int array[], int key, int size) {
	int i = 0;
	for(int j=1; j<size; j++) {
		key = array[j];
		i = j - 1;
		while (i>=0 && array[i] < key) {	//Comparing elements to sort them
			array[i + 1] = array[i];
			i = i - 1;
			count ++;
		}
		array[i + 1] = key;
	}	
}

//Body of merge sort function
void mergeSort(int A[], int lo, int hi) {
	if(lo < hi) {
		int mid = (lo + hi)/2;
		mergeSort(A, lo, mid);
		mergeSort(A, mid+1, hi);
		merge(A, lo, mid, hi);
	}
}

//Body of merge function to sort the numbers
void merge(int a[], int lo, int mid, int hi) {
	int temp[18];
	int i, j, k;
	i = lo;
	j = mid+1, k=0;
	while(i<=mid && j<=hi) {
		if(a[i] > a[j]) {	//Comparing numbers to sort them
			temp[k] = a[i];
			i++;
			count ++;
		}
		else {
			temp[k] = a[j];
			j++;
		}
		k++;
	}
	while(i <= mid) {
		temp[k] = a[i];
		k++;
		i++;
	}
	while(j <= hi) {
		temp[k] = a[j];
		k++;
		j++;
	}
	for(i=lo, j=0; i<=hi; i++, j++) {
		a[i] = temp[j];
	}
}

//Printing function to print the sorted elements after removing the duplicate values
void printSortedList(int array[], int size) {
	for(int i=0; i<size; i++) {
		for(int j=i+1; j<size; j++) {
			if (array[i] == array[j]) { //Check for duplicate values
				for(int k=j; k<size; k++) {
					array[k] = array[k+1]; 
				}
				size --;
				j --;
			}
		}
		printf("%d ", array[i]);
	}
	printf("\nThe number of comparisons: %d", count); //Printing the number of comparision for sorting the list
	printf("\n\n");
}
*/
