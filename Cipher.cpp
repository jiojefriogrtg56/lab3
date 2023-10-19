﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void decryption(int q, int r, int* closeKey) 
{
    int index = 7, counter = 0, counterAnswere = 0;
    int n1 = 1, quanity = 2, i = 0;
    int cipher[100] = { 0 }, result[100];
    int binaryIndexs[8] = { 0 };
    int resultAnswere[100] = { 0 };
    while (r * n1 % q != 1) n1++;
    printf("Введите количество символов: %d\n", quanity);
    printf("Введите числа для расшифровки: %d\n", cipher[0]=(103));
    printf("%d\n", cipher[1] = (111));
    for (i = 0; i < quanity; i++) 
    {
        result[i] = cipher[i] * n1 % q;
        counter = 0; index = 7; memset(binaryIndexs, 0, sizeof binaryIndexs);
        while (result[i] > 0) 
        {
            while (closeKey[index] > result[i]) index--;
            result[i] -= closeKey[index];
            binaryIndexs[counter] = 7 - index;
            resultAnswere[counterAnswere] += pow(2, binaryIndexs[counter]);
            index = 7; counter++;
        }
        printf("%c", char(resultAnswere[counterAnswere]));
        counterAnswere++;
    }
}

void encryption(int* openKey) 
{
    int result = 0;
    char binaryWord[1000] = { 0 }, word[] = "hi";
    printf("\nВведите текст: %s\n", word);
    for (int i = 0; word[i] != '\0'; i++) {
        result = 0;
        for (int b = 7, v = 0; b >= 0; --b, v++) binaryWord[v] = (word[i] & (1 << b)) ? '1' : '0';
        for (int j = 0; j < 8; j++)  if (binaryWord[j] == '1') result += openKey[j];
        printf("Зашифрованный текст: %d\n", result);
    }
}

void createKeys(int* closeKey, int q, int r, int* openKey) 
{
    printf("Приватный ключ: ");
    for (int i = 0; i < 8; i++) printf("%d, ", closeKey[i]);

    printf("\nПубличный ключ: ");
    for (int i = 0; i < 8; i++)
    {
        openKey[i] = closeKey[i] * r % q;
        printf("%d, ", openKey[i]);
    }
}

int main(void)
{
    setlocale(LC_ALL, "Russian");
    int  q = 271, r = 17;
    int closeKey[8] = { 1, 2, 4, 8, 16, 32, 64, 128 }, openKey[8] = { 0 };
    createKeys(closeKey, q, r, openKey);
    encryption(openKey);
    decryption(q, r, closeKey);
    return 0;
}
