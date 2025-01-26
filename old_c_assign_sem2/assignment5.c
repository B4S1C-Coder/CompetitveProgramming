#include <stdio.h>
#include <limits.h> // needed for ques8 INT_MAX and INT_MIN

void ques1() {
	int arrSize;

	printf("Array size: ");
	scanf("%d", &arrSize);

	float myArr[arrSize];

	printf("Enter %d elements: ", arrSize);
	for (int i = 0; i < arrSize; i++) {
		scanf("%f", &myArr[i]);
	}

	float reverseArr[arrSize];

	for (int j = arrSize - 1; j > -1; j--) {
		reverseArr[arrSize - 1 - j] = myArr[j];
	}

	printf("\nReversed array: ");
	for (int k = 0; k < arrSize; k++) {
		printf("%f, ", reverseArr[k]);
	}
}

void ques2() {
	int arrSize;

	printf("Array size: ");
	scanf("%d", &arrSize);

	float myArr[arrSize];

	printf("Enter %d elements: ", arrSize);
	for (int i = 0; i < arrSize; i++) {
		scanf("%f", &myArr[i]);
	}

	int indexPos;
	printf("Enter the index position to insert: ");
	scanf("%d", &indexPos);

	// check if index is valid
	if (indexPos < arrSize) {
		float toInsert;

		printf("Enter element to insert: ");
		scanf("%f", &toInsert);

		// new array will contain one element more than the original
		float newArr[arrSize + 1];
		short reachedIndex = 0;

		for (int j = 0; j < arrSize + 1; j++) {
			if (j == indexPos) {
				reachedIndex = 1;
				newArr[j] = toInsert;
				continue;
			}
			if (reachedIndex) {
				newArr[j] = myArr[j - 1];
				continue;
			} else {
				newArr[j] = myArr[j];
				continue;
			}
		}

		printf("Array after insertion: ");

		for (int k = 0; k < arrSize + 1; k++) {
			printf("%f, ", newArr[k]);
		}

	} else {
		printf("Invalid index");
	}
}

void ques3() {
	int arrSize;
	printf("Array Size: ");
	scanf("%d", &arrSize);

	float myArr[arrSize];
	int i = 0;

	for (i = 0; i < arrSize; i++) {
		scanf("%f", &myArr[i]);
	}

	float elementToDelete;
	printf("Specify element to delete: ");
	scanf("%f", &elementToDelete);

	// Simple approach: Make a new array without the elementToDelete.
	float newArr[arrSize];
	int indexTracker = 0;

	for (i = 0; i < arrSize; i++) {
		if (myArr[i] == elementToDelete) {
			continue;
		}
		newArr[indexTracker] = myArr[i];
		indexTracker++;
	}

	// print the new array
	printf("New Array: ");

	for (i = 0; i < arrSize; i++) {
		printf("%f\t", newArr[i]);
	}

	printf("\n");

	// Alternate Apporach: modify the original array itself
	// Below doesn't work for every case and is memory UNSAFE
	int eTDCounter = 0;
	for (i = 0; i < arrSize; i++) {
		if (myArr[i] != elementToDelete) { continue; }

		eTDCounter += 1;

		for (int j = i + 1; j < (arrSize - i); j++) {
			if (myArr[j] != elementToDelete) { break; }
			myArr[j] = 0;
			eTDCounter += 1;
		}

		myArr[i] = myArr[i + eTDCounter];
		myArr[i + eTDCounter] = 0;
		i += eTDCounter;
	}

	// print the new array
	printf("Modified Array: ");

	for (i = 0; i < arrSize; i++) {
		printf("%f\t", myArr[i]);
	}

	printf("\n");	
}

void ques4() {
	// Linear search
	int arrSize;
	printf("Enter array size: ");
	scanf("%d", &arrSize);

	float myArr[arrSize];
	printf("Enter the array (space separated): ");

	for (int i = 0; i < arrSize; i++) {
		scanf("%f", &myArr[i]);
	}

	float elementToSearch;
	printf("Enter element to search: ");
	scanf("%f", &elementToSearch);

	int occurences = 0;

	// You can also break the loop at first occurence
	for (int j = 0; j < arrSize; j++) {
		if (myArr[j] != elementToSearch) { continue; }
		printf("Element found at index: %d\n", j);
		occurences += 1;
	}

	printf("Total %d occurences of element %f\n", occurences, elementToSearch);

}

void ques5() {
	// Array Input
	int arrSize;
	printf("Enter array size: ");
	scanf("%d", &arrSize);

	float myArr[arrSize], temp;
	int i = 0;

	printf("Enter the array (space separated): ");
	for (i = 0; i < arrSize; i++) {
		scanf("%f", &myArr[i]);
	}

	// Bubble sort to sort the array in ascending order
	for (i = 0; i < arrSize; i++) {
		// Loop for one pass
		// Since the last elements i elements are already sorted
		for (int j = 0; j < arrSize - i - 1; j++) {
			if (myArr[j] > myArr[j + 1]) {
				// swap the elements
				temp = myArr[j];
				myArr[j] = myArr[j + 1];
				myArr[j + 1] = temp;
			}
		}
	}

	printf("[DEBUG] Sorted array: ");
	for (i = 0; i < arrSize; i++) {
		printf("%f\t", myArr[i]);
	}

	// Binary Search
	float elementToSearch;
	printf("\nEnter element to search: ");
	scanf("%f", &elementToSearch);

	int low = 0, high = arrSize -1, mid;

	while (low <= high) {
		mid = (low + high)/2;

		if (myArr[mid] < elementToSearch) {
			// work on right half
			low = mid + 1;
		} else if (myArr[mid] > elementToSearch) {
			// work on left half
			high = mid - 1;
		} else {
			printf("Element found at index: %d\n", mid);
			break;
		}
	}
}

void ques6() {
	int arrSize;
	printf("Enter array size: ");
	scanf("%d", &arrSize);

	float myArr[arrSize], sum = 0;

	// here we are calculating sum in the input loop itself
	// you can make a separate loop for it if you want
	printf("Enter the array (space separated): ");
	for (int i = 0; i < arrSize; i++) {
		scanf("%f", &myArr[i]);
		sum += myArr[i];
	}

	printf("Sum: %f, Mean: %f\n", sum, sum/(float)arrSize);
}

void ques7() {
	int arrSize1;
	printf("Enter first array size: ");
	scanf("%d", &arrSize1);

	float myArr1[arrSize1];

	printf("Enter first array (space separated): ");

	int i;
	for (i = 0; i < arrSize1; i++) {
		scanf("%f", &myArr1[i]);
	}

	int arrSize2;
	printf("Enter second array size: ");
	scanf("%d", &arrSize2);

	float myArr2[arrSize2];

	printf("Enter second array (space separated): ");
	for(i = 0; i < arrSize2; i++) {
		scanf("%f", &myArr2[i]);
	}

	float mergedArray[arrSize1 + arrSize2];

	for (i = 0; i < arrSize1; i++) {
		mergedArray[i] = myArr1[i];
	}

	for (i = 0; i < arrSize2; i++) {
		mergedArray[arrSize1 + i] = myArr2[i];
	}

	printf("Merged Array: ");
	// print merged array
	for (i = 0; i < (arrSize1 + arrSize2); i++) {
		printf("%f  ", mergedArray[i]);
	}
	printf("\n");
}
// we will be using the limits header for INT_MAX and INT_MIN
// you could choose them arbitrarily also as per your needs
void ques8() {
	int arrSize;
	printf("Enter array size: ");
	scanf("%d", &arrSize);

	int myArr[arrSize];
	printf("Enter the array: ");
	int i;

	for (i = 0; i < arrSize; i++) {
		scanf("%d", &myArr[i]);
	}

	int max = INT_MIN, min = INT_MAX;

	for (i = 0; i < arrSize; i++) {
		if (myArr[i] > max) {
			max = myArr[i];
		}
		if (myArr[i] < min) {
			min = myArr[i];
		}
	}

	printf("Max: %d, Min: %d\n", max, min);
}

int main() {
	ques8();
	return 0;
}