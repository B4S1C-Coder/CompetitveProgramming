#include <stdio.h>
#include <stdlib.h>

int* combineIntArray(const int* arr1, const int arr1size,
	const int* arr2, const int arr2size) {
	int* combinedArray = (int*)malloc((arr1size + arr2size)*sizeof(int));
	int i, j;
	for (i = 0; i < arr1size; i++) {
		combinedArray[i] = arr1[i];
	}
	for (j = 0; j < arr2size; j++) {
		combinedArray[i + j] = arr2[j];
	}
	return combinedArray;
}

void insertElementAtIndex(int* arr, const int arrSize,
	const int elementToInsert, const int insertionIndex) {

	if (insertionIndex >= arrSize) { return; }

	int i = arrSize - 2;
	while (1) {
		arr[i + 1] = arr[i];
		if (i == insertionIndex) {
			arr[i] = elementToInsert;
			break;
		}
		i--;
	}
}

void bubbleSortAscending(int* arr, const int arrSize) {
	int temp;
	for (int j = 0; j < arrSize - 1; j++) {
		for (int i = 0; i < arrSize - j - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				// swap
				// printf("swapping %d and %d\n", arr[i], arr[i+ 1]);
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				continue;
			}
		}
	}
}

int binarySearch_iterative(const int* arr, const int arrSize,
	const int target) {
	int low = 0;
	int high = arrSize - 1;
	int mid;

	while (low <= high) {
		mid = (low + high)/2;

		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] > target) {
			high = mid - 1;
			continue;
		} else {
			low = mid + 1;
			continue;
		}
	}

	return -1;
}

int binarySearch_recursive(const int* arr, int low, int high,
	const int target) {
	if (high >= low) {
		int mid = (low+ high)/2;

		if (arr[mid] == target) {
			return mid;
		}

		if (arr[mid] > target) {
			return binarySearch_recursive(arr, low, mid - 1, target);
		}

		return binarySearch_recursive(arr, mid + 1, high, target);
	}
	return -1;
}

void printArray(const int* arr, const int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		printf("%d    ", arr[i]);
	}
	printf("\n");
}

int main() {
	int i;
	int a[4] = {1,2,3,4};
	int b[3] = {5,6,7};

	int* c = combineIntArray(a, 4, b, 3);

	printArray(c, 7);

	int x[5] = {1,2,3,4};

	insertElementAtIndex(x, 5, -69, 1);

	printArray(x, 5);

	int y[9] = {10, -69, 34546, 565, -67, 353, 12, 56, 8};
	bubbleSortAscending(y, 9);

	printArray(y, 9);

	printf("%d\n", binarySearch_iterative(y, 9, 12));
	printf("%d\n", binarySearch_recursive(y, 0, 9 - 1, 12));

	return 0;
}