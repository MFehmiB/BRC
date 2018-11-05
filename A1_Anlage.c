void print_bin(unsigned char paket) {
    /* Byte (in Form von char buffer) als binärzahl auf der Konsole ausgeben */
    for (int i = 0; i < 8; i++) {
        printf("%d", (paket << i & 0x80) != 0);
    }
    printf("\n");
}
