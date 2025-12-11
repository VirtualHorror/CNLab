// Write a program for implementing the error detection technique for data transfer in unreliable
network code using CRC (16-bits) Technique.
#include <stdio.h>
#include <string.h>

char data[100], div[20], rem[20], crc[100];

void xor_op(int len) {
    for (int i = 0; i < len; i++)
        rem[i] = (rem[i] == div[i]) ? '0' : '1';
}

void divide(int dlen, int divlen) {
    for (int i = 0; i < divlen; i++)
        rem[i] = crc[i];
    for (int i = 0; i <= dlen - divlen;) {
        if (rem[0] == '1')
            xor_op(divlen);
        for (int j = 0; j < divlen - 1; j++)
            rem[j] = rem[j + 1];
        rem[divlen - 1] = crc[i + divlen];
        i++;
    }
}

int main() {
    printf("Enter data: ");
    scanf("%s", data);
    strcpy(div, "10001000000100001");
    int dlen = strlen(data), divlen = strlen(div);
    strcpy(crc, data);
    for (int i = 0; i < divlen - 1; i++)
        strcat(crc, "0");
    divide(dlen + divlen - 1, divlen);
    for (int i = 0; i < divlen - 1; i++)
        crc[dlen + i] = rem[i];
    printf("Transmitted data: %s\n", crc);
    printf("Enter received data: ");
    scanf("%s", crc);
    divide(strlen(crc), divlen);
    int err = 0;
    for (int i = 0; i < divlen - 1; i++)
        if (rem[i] == '1') err = 1;
    if (err)
        printf("Error detected\n");
    else
        printf("No error\n");
    return 0;
}
