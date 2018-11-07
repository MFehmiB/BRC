default: packet_bitshift.o
	gcc -o default packet_bitshift.o

packet_bitshift.o:
	gcc -c packet_bitshift.c

clean:
	rm *.o default
