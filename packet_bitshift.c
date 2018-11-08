#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
  /* code */
  char *buffer, *dest;

  //buffer = malloc(strlen(argv[1])+3);
  //dest = buffer;
  char *packet;
  char original;
  int newResult;
  packet = argv[1];
  newResult = ((int) *argv[2]) -48;
  original = packet[12];

  // Abfangen falscher Eingaben
  if (argc < 3) {
    /* code */
    printUsage();
    return 0;
  }
  if (strlen(argv[1]) < 18) {
    /* code */
    printUsage();
    return 0;
  }
  if (newResult > 50 || newResult < 0) {
    /* code */
    printf("Results range from 0 to 50 points. Enter a number between 0 and 50\n");
    printUsage();
  }

  //printf("%s\n", original);
  printf("%s\n", packet);
  printf("%i\n", newResult);

  //free(buffer);
  return 0;
}

void printUsage(/* arguments */) {
  /* code */
  printf("This is a program to hack the results of your exam. (My teacher made me write it.)\n"
  "Please enter two parameters: Firstly, your datapacket in single qoutes \'\'. \n"
  "Secondly, the test results you want to write in your datapacket as an int.\n\n"

  "Your datapacket should look like this: \n"
        "Inf-ITS*SS18?!!!Doe \n"
  "7 chars lecture code; 1 char exam number; 4-6 chars term; 1 char exampoints; \n"
  "3 chars student number; 2 or more chars; \n"
  "exam number, points and student number are ASCII-encoded, which means they will \n"
  "be shown as chars according to their corresponding ASCII symbol(s). \n");
}

void print_bin(unsigned char paket) {
    /* Byte (in Form von char buffer) als binärzahl auf der Konsole ausgeben */
    for (int i = 0; i < 8; i++) {
        printf("%d", (paket << i & 0x80) != 0);
    }
    printf("\n");
}
