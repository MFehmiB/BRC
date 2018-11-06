#include <stdio.h>
#include <string.h>

int printUsage() {
  printf("Please enter two parameters: Firstly, your datapacket in single qoutes \'\'. \n"
  "Secondly, the test results you want to write in your datapacket as an int.\n\n"
  "Your datapacket should look like this: \n"
        "Inf-ITS*SS18?!!!Doe \n"
  "7 chars lecture code; 1 char exam number; 4-6 chars term; 1 char exampoints; \n"
  "3 chars student number; 2 or more chars; \n"
  "exam number, points and student number are ASCII-encoded, which means they will \n"
  "be shown as chars according to their corresponding ASCII symbol(s). \n");
	return 0;
}

void print_bin(unsigned char paket) {
	/* Byte (in Form von char buffer) als binärzahl auf der Konsole ausgeben */
	for (int i = 0; i < 8; i++) {
		printf("%d", (paket << i & 0x80) != 0);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	char* packet;
	int newResult;
	char byteToChange;
	char newASCIIResult;

	//Check if the packetsize is smaller than 18 byte (a char in C is always 1byte)
	if (argc == 3) {
		if (strlen(argv[1]) >= 18) {
	  	packet = argv[1];
			byteToChange = packet[12];
		} else {
			printf("Your Packet must be at least 18 Characters long! See usage:\n");
			printUsage();
			return 0;
		}

		//check if newResult is between 0-50
		if (sscanf(argv[2], "%i", &newResult) == 1) {
			if (newResult <= 50 && newResult >= 0) {
			} else {
				printf("Your Result must be between 0 - 50! See usage:\n");
				printUsage();
				return 0;
			}
		} else {
			return -1;
		}
		printf("original:");
		print_bin(byteToChange);
		//bitshift to get points and also gets rid of flags
		byteToChange = byteToChange>>2;
		printf("points: %d\n", byteToChange);
		newResult = newResult<<2;
		//add flags
		newResult = newResult+3;
		printf("modifiziert:");
		print_bin(newResult);
		packet[12] = newResult;
		printf("new packet name: %s", packet);
  	return 0;
	} else {
		printf("Argument is missing! See usage:\n")
		printUsage();
		return 0;
	}
}
