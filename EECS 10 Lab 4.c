// Written by Casey Sharp
// EECS 10 Lab 4

#include <stdio.h>
#include <math.h>

int count = 0;
int array[100];
int *s;
float *m;

void input()
{ // Receives the inputs from the user and puts them into an array
    int j;
    printf("To stop adding integers type any single letter\n");
    
    printf("Input integers: ");
    for(int i = 0; i < 100; i++){
        if(scanf("%i", &j) <= 0){
            break;
        } else {
        array[i] = j;
        count++;
        }
    }
    printf("The input values are: ");
    for(int i = 0; i < count; i++){
	    printf("%i ", array[i]);
	}
	printf("\n");
}

void sort(int inputArray[], int count)
{ // Sorts the inputs from the user and sorts them in decending order
    int max, max_index;
    
    for(int i = 0; i < count; i++){
        max = inputArray[i];
        for(int j = i; j < count; j++){
            if(max <= inputArray[j]){
                max = inputArray[j];
                max_index = j;
            }
        }
        inputArray[max_index] = inputArray[i];
        inputArray[i] = max;
    }
    printf("Sorted numbers: ");
    for(int i = 0; i < count; i++){
	    printf("%i ", inputArray[i]);
	}
	printf("\n");
	s = &inputArray[0];
}

void mean(int inputArray[], int count)
{ // Finds the mean of all the data input by the user
    float sum = 0;
    float mean;
    
    for(int i = 0; i < count; i++){
        sum += inputArray[i];
    }
    
    mean = sum/count;
    printf("The mean of the data is %.3f\n", mean);
    m = &mean;
}

void median(int count)
{ // Finds the median of the data input by the user
    float median;
    int sortedArray[100];
    for(int i = 0; i < count; i++)
    {
        sortedArray[i] = *s;
        s++;
    }
    if(count % 2 == 0){
        median = (sortedArray[count/2 - 1] + sortedArray[count/2]) / 2;
    } else{
        median = sortedArray[count/2];
    }
    
    printf("The median of the data is %.3f\n", median);
}

void standardDev(int inputArray[], int count)
{ // Finds the standard deviation of the data input by the user 
    double mean = *m;
    double sum = 0;
    for(int i = 0; i < count; i++){
        sum += pow((inputArray[i] - mean), 2);
    }
    double standD = sqrt(sum/count);
    
    printf("The standard deviation of the data is %.3f", standD);
}

int main(){
    input();
    sort(array, count);
    mean(array, count);
    median(count);
    standardDev(array, count);
}

