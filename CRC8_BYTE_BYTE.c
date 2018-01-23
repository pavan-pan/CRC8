#include <stdio.h>

// This program calculates the CRC 8 without using lookup table

typedef unsigned char uint8_t;

uint8_t CRC_calc( uint8_t *arr, uint8_t size)
{
    uint8_t crc = 0;
    const uint8_t generator = 0xD5;//Polynomial

    for (int j = 0; j < size; j++)
    {
        crc ^= arr[j];

        //For each bit of the byte check for the MSB bit, if it is 1 then left shift the CRC and XOR with the polynomial
        //otherwise just left shift the variable
        for (int i = 0; i < 8; i++)
        {
            if ((crc & 0x80) != 0)
            {
                crc = (uint8_t)((crc << 1 ^ generator));
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    printf ("CRC calculated : %x\n", crc);
    return crc;
}

int main()
{
    uint8_t arr[5] = {0x12, 0x23, 0x34, 0x56, 0x78};
    CRC_calc(arr, 1);
    return 0;
}
