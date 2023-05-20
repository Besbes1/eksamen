#include <stdio.h>
#include <stdlib.h>
struct charNode{
    char c;
    struct charNode* next;
};
struct stringNode{
    struct charNode *header;
    struct stringNode *next;
};
struct charNode globalStr[12]={{'J', &globalStr[1]},{'u', &globalStr[2]},
                               {'s', &globalStr[3]}, {'t', &globalStr[4]},
                               {' ', &globalStr[5]}, {'i', &globalStr[6]},
                               {'n', &globalStr[7]}, {' ', &globalStr[8]},
                               {'c', &globalStr[9]}, {'a', &globalStr[10]},
                               {'s', &globalStr[11]}, {'e', NULL}};
//Reads a string from the keyboard using the function getchar(),
// Saves the string in a linked list,
// and returns the header to the linked list.
struct charNode* initializeStringAsLinkedList(){
//Missing code 1
    struct charNode* head = NULL;
    struct charNode* current = NULL;
    char input;

//input a string:
    printf("Input a string: ");

    while ((input = getchar()) != '\n') {
        struct charNode* newNode = (struct charNode*)malloc(sizeof(struct charNode));
        newNode->c = input;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
        }else {
            current->next = newNode;
            current = newNode;
        }
    }
    return head;
}

//Prints on the screen the string saved in the linked list
void showString(struct charNode* string){
    struct charNode* current=string;
    while(current){
        printf("%c",current->c);
        current=current->next;
    }
    printf("\n");
}
//Returns the number of words in a string (that is represented as a
// linked list). The words are separated by one or more space characters ' '.
int numberOfWords(struct charNode* string){
//Missing code 2
    int count = 0;
    struct charNode* current = string;
    int isWord = 0;

    while (current) {
        if (current->c != ' ' && !isWord) {
            count++;
            isWord = 1;
        } else if (current->c == ' ') {
            isWord = 0;
        }

        current = current->next;
    }
    return count;
}

//Replaces in place (in the existing linked list representing the string)
// a character from the input string located at position pos with the
// argument letter
void replaceLetterAtPos(struct charNode* string, unsigned int pos, char
letter){
//Missing code 3
    struct charNode* current = string;
    unsigned int index = 0;

    while (current && index < pos) {
        current = current->next;
        index++;

    }

    if (current) {
        current->c = letter;
    }
}
//Gets as input a string represented as a linked list and creates a new // string represented as a linked list that contains the same text as the // original string, but where all lower case letters are converted // to upper case letters. struct charNode* stringToUpperCase(struct charNode* string) { //Missing code 4 } //Split the input string into several strings using a separator character // which is given as argument. The separator is omitted from the new strings // The new strings are organized into a linked list, where each element of // the linked list has the type "struct stringNode" and it's member variable // header points to the start of a string (represented as a linked list with // elements of type "struct charNode"). //The function returns the header of the list that points at the strings. struct stringNode* split(struct charNode* string, char separator){ //Missing code 5 } //Prints on the screen all the strings saved in a list of strings. void showListOfStrings(struct stringNode* strings){ struct stringNode* current=strings; while(current){ showString(current->header); current=current->next; } } int main(){ struct charNode* string; string = &globalStr[0]; //Uncomment next line after implementing the function //string = initializeStringAsLinkedList(); struct charNode string2=NULL, *string3=NULL; struct stringNode strings=NULL; showString(string); printf("The string has %d words\n", numberOfWords(string)); replaceLetterAtPos(string,0,'5'); replaceLetterAtPos(string,3,'D'); replaceLetterAtPos(string,4,'O'); replaceLetterAtPos(string,5,' '); replaceLetterAtPos(string,6,' '); replaceLetterAtPos(string,7,' '); showString(string); printf("The string has %d words\n", numberOfWords(string)); string2= stringToUpperCase(string); showString(string2); strings= split(string,' '); showListOfStrings(strings); }
// string represented as a linked list that contains the same text as the // original string, but where all lower case letters are converted // to upper case letters.
// original string, but where all lower case letters are converted
// to upper case letters.
struct charNode* stringToUpperCase(struct charNode* string) { //Missing code 4 }
//Missing code 4
    struct charNode *newString = NULL;
    struct charNode *current = string;

    while (current) {
        struct charNode *newNode = (struct charNode *) malloc(sizeof(struct charNode));
        if (current->c >= 'a' && current->c <= 'z') {
            newNode->c = current->c - 32; // convert to upper case
        } else {
            newNode->c = current->c;
        }
        newNode->next = NULL;

        if (newString == NULL) {
            newString = newNode;
            current = current->next;
        } else {
            struct charNode *temp = newString;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            current = current->next;
        }

    }

    return newString;
}

//Split the input string into several strings using a separator character
// which is given as argument. The separator is omitted from the new strings
// The new strings are organized into a linked list, where each element of
// the linked list has the type "struct stringNode" and it's member variable
// header points to the start of a string (represented as a linked list with
// elements of type "struct charNode").
//The function returns the header of the list that points at the strings.
struct stringNode *split(struct charNode *string, char separator) {
    struct stringNode *header = NULL;
    struct stringNode *current = NULL;
    struct charNode *tempString = NULL;
    struct charNode *currentString = NULL;

    struct charNode *currentChar = string;
    while (currentChar) {
        if (currentChar->c == separator) {
            if (tempString != NULL) {
                struct stringNode *newNode = (struct stringNode *) malloc(sizeof(struct stringNode));
                newNode->header = tempString;
                newNode->next = NULL;

                if (header == NULL) {
                    header = newNode;
                    current = newNode;
                } else {
                    current->next = newNode;
                    current = newNode;
                }
                tempString = NULL;
                currentString = NULL;
            }
        } else {
            struct charNode *newNode = (struct charNode *) malloc(sizeof(struct charNode));
            newNode->c = currentChar->c;
            newNode->next = NULL;

            if (tempString == NULL) {
                tempString = newNode;
                currentString = newNode;
            } else {
                currentString->next = newNode;
                currentString = newNode;
            }
        }
        currentChar = currentChar->next;
    }
    if (tempString != NULL) {
        struct stringNode *newNode = (struct stringNode *) malloc(sizeof(struct stringNode));
        newNode->header = tempString;
        newNode->next = NULL;

        if (header == NULL) {
            header = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    return header;
}



//Prints on the screen all the strings saved in a list of strings.
void showListOfStrings(struct stringNode *strings) {
    struct stringNode *current = strings;
    while (current) {
        showString(current->header);
        current = current->next;
    }
}

int main() {
    struct charNode *string;
    string = &globalStr[0];
    //Uncomment next line after implementing the function
    string = initializeStringAsLinkedList();
    struct charNode *string2 = NULL, *string3 = NULL;
    struct stringNode *strings = NULL;
    showString(string);
    printf("The string has %d words\n", numberOfWords(string));
    replaceLetterAtPos(string, 0, '5');
    replaceLetterAtPos(string, 3, 'D');
    replaceLetterAtPos(string, 4, 'O');
    replaceLetterAtPos(string, 5, ' ');
    replaceLetterAtPos(string, 6, ' ');
    replaceLetterAtPos(string, 7, ' ');
    showString(string);
    printf("The string has %d words\n", numberOfWords(string));
    string2 = stringToUpperCase(string);
    showString(string2);
    strings = split(string, ' ');
    strings = split(string, ' ');
}