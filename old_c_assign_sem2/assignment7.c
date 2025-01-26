#include <stdio.h>
#include <string.h>

void ques1() {
    char namesArray[3][20];
    unsigned short rollNosArray[3];
    unsigned short marksArray[3];
    char temp;

    for (int i = 0; i < 3; i++) {
        printf("Enter Student Name [%d of 3]: ", i + 1);
        //fgets(namesArray[i], 20*sizeof(char), stdin);
        scanf("%s", namesArray[i]);
        //scanf("%c", temp); // To ignore the newline character present in the input buffer
        printf("Enter Student Roll No. [+ve int]: ");
        scanf("%hd", &rollNosArray[i]);
        printf("Enter Student Marks [+ve int]: ");
        scanf("%hd", &marksArray[i]);
        //scanf("%c", temp); // To ignore the newline character present in the input buffer
    }
    
    printf("\nNAME    |    ROLL NO    | MARKS\n");
    printf("---------------------------------\n");
    for (int j = 0; j < 3; j++) {
        printf("%s      |", namesArray[j]);
        printf("    %hd  |", rollNosArray[j]);
        printf("    %hd  \n", marksArray[j]);
    }
}

struct Student {
    char name[20];
    unsigned short rollNo;
    unsigned short marks;
};

// Ques 5 done in this function
void printStudent(struct Student* student) {
    printf("Name: %s, Roll No: %hd, Marks: %hd\n", student->name, student->rollNo, student->marks);
}

struct Student createDefualtStudent() {
    struct Student student = {"defaultStudent", 42, 69};
    return student;
}

void ques6() {
    struct Student defaultStudent = createDefualtStudent();
    printStudent(&defaultStudent);
}

void ques2() {
    struct Student students[3];

    for (int i = 0; i < 3; i++) {
        printf("Enter name [%d of 3]: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter roll no [%d of 3]: ", i + 1);
        scanf("%hd", &students[i].rollNo);
        printf("Enter marks [%d of 3]: ", i + 1);
        scanf("%hd", &students[i].marks);
    }

    for (int j = 0; j < 3; j++) {
        printStudent(&students[j]);
    }
}

struct Payload {
    char typeLoad[20];
    float weightTons;
};

struct Missile {
    char missileName[20];
    char missileClass[5];
    int rangeKm;
    int stages;
    int terminalVelocityMach;
    char launchPlatforms[3][10];
    char triadCompatible[3];
    int numPayloads;
    struct Payload payload;
    int destructionRadiusKM;
};

void ques3AndQues4andQues7() {
    struct Payload nuclearWarHead = {"NUKE WARHEAD", 4};
    struct Payload conventional = {"CONVENTIONAL", 2};

    struct Missile AgniV = {
            "Agni Five",
            "ICBM",
            8000,
            3,
            24,
            {"Land"},
            "No",
            12,
            nuclearWarHead,
            10000
    };

    struct Missile anotherAgniV = AgniV;

    struct Missile Pralay = {
            "Pralay",
            "SAM",
            500,
            1,
            5,
            {"Land", "Air", "Sea"},
            "Yes",
            1,
            conventional,
            300
    };

    Pralay.numPayloads = AgniV.numPayloads;

    struct Missile temp;

    temp = anotherAgniV;
    anotherAgniV = Pralay;
    Pralay = temp;

    printf("Finished successfully. I was too lazy to print everything.\n");
}

union saddaUnion {
    int saddeNumber;
    float saddaFloat;
    char saddi4EelementDiCharArray[4];
};

void ques8() {
    union saddaUnion pindDaUnion;
    printf("Sadda union kinna vada ae? --> %ld\n", sizeof(pindDaUnion));

    pindDaUnion.saddeNumber = 69;
    printf("%d\n", pindDaUnion.saddeNumber);
    printf("%s\n", pindDaUnion.saddi4EelementDiCharArray);
}


int main() {
    ques8();
}
