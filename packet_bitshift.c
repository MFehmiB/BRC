#include <stdio.h>
#include <string.h>

char *buffer, *dest;
int main(int argc, char const *argv[]) {
  /* code */

  buffer = malloc(strlen(argv[1])+3);
  //dest = buffer;
  char *packet;
  int newResult;
  if (strlen(argv[1]) < 18) {
    /* code */
    printUsage();
    return 0;
  }
  packet = argv[1];
  newResult =  *argv[2] -48;
  printf("%s\n", packet);
  printf("%i\n", newResult);
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
