Program (CRC-12):
#include <stdio.h>
#include <string.h>
unsigned int CRC12(const char *data) {
    unsigned int poly = 0x180F;
    unsigned int crc = 0x000;
    for (int i = 0; i < strlen(data); i++) {
        unsigned char byte = data[i];
        for (int j = 0; j < 8; j++) {
            int bit = ((byte >> (7 - j)) & 1) ^n ((crc >> 11) & 1);
            crc <<= 1;
            if (bit) crc ^n = poly;
            crc &= 0xFFF;
        }
    }
}

int main() {
    char data[100];
    printf("Enter data: ");
    scanf("%s", data);
    printf("CRC-12 = %03X\n", CRC12(data));
}

Output:

Enter data: HELLO
CRC-12: D44


Program (CRC-16):

#include <stdio.h>
#include <string.h>

unsigned int CRC16(const char *data) {
    unsigned int poly = 0x8005;
    unsigned int crc  = 0x8000;

    for (int i = 0; i < strlen(data); i++) {
        unsigned char byte = data[i];
        for (int j = 0; j < 8; j++) {
            int bit = ((byte >> (7 - j)) & 1) ^n ((crc >> 15) & 1);
            crc <<= 1;
            if (bit) crc ^n= poly;
            crc &= 0xFFFF;
        }
    }
}

int main() {
    char data[100];
    printf("Enter data: ");
    scanf("%s", data);
    printf("CRC-16 = %04X\n", CRC16(data));
}

Output:

Enter data: HELLO
CRC-16: 34ED



Program (CRC-CCITT):

#include <stdio.h>
#include <string.h>

unsigned int CRC_CCITT(const char *data) {
    unsigned int poly = 0x1021;
    unsigned int crc  = 0xFFFF;

    for (int i = 0; i < strlen(data); i++) {
        unsigned char byte = data[i];
        for (int j = 0; j < 8; j++) {
            int bit = ((byte >> (7 - j)) & 1) ^n ((crc >> 15) & 1);
            crc <<= 1;
            if (bit) crc ^n = poly;
            crc &= 0xFFFF;
        }
    }
}

int main() {
    char data[100];
    printf("Enter data: ");
    scanf("%s", data);
    printf("CRC-CCITT = %04X\n", CRC_CCITT(data));
}

Output:

Enter data: HELLO
CRC-CCITT: 9065



