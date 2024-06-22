#include <stdio.h>
#include <string.h>

void reversePrintWords(char* sentence) {
    int length = strlen(sentence);
    int start = 0;

    // Reverse each word in the sentence
    for (int i = 0; i <= length; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            int end = i - 1;
            while (start < end) {
                char temp = sentence[start];
                sentence[start] = sentence[end];
                sentence[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }

    // Reverse the whole sentence
    for (int i = 0; i < length / 2; i++) {
        char temp = sentence[i];
        sentence[i] = sentence[length - i - 1];
        sentence[length - i - 1] = temp;
    }

    // Print the reversed sentence
    printf("Reversed sentence : %s\n", sentence);
}

int main() {
    char sentence[] = "This is a sample sentence.";

    printf(" sentence reversed : %s\n", sentence);

    reversePrintWords(sentence);

    return 0;
}

