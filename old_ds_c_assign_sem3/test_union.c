#include <stdio.h>

typedef union nodeData {
	int data_i;
	char* data_cp;
	char data_c;
	float data_f;
	double data_d;
} nodeData;

typedef struct carrier {
	union nodeData data;
} carrier;

int main() {

	carrier myObj;
	nodeData data = {69};
	myObj.data = data;

	printf("%d\n", myObj.data);

	return 0;
}