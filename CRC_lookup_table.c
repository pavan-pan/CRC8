#include <stdio.h>

//Generates the lookup table and Calculates the CRC using the lookup table
typedef unsigned char uint8_t;
uint8_t lookup[256] = {0};


void generate_lookup ()
{
    uint8_t generator = 0xD5;
    uint8_t currbyte = 0;

    for (int dividend = 0; dividend < 256; dividend++)
    {
        currbyte = dividend;

        for (uint8_t bit = 0; bit < 8 ; bit++)
        {
            if ((currbyte & 0x80) != 0)
            {
                currbyte <<=1;
                currbyte ^= generator;
            }
            else

            {
                currbyte <<= 1;
            }

        }
        lookup[dividend] = currbyte;

    }
}

int main()
{
    uint8_t crc = 0;
    uint8_t data = 0;
    uint8_t arr[5] = {0x12, 0x23, 0x34, 0x45, 0x56};
    for (int i = 0; i < 5; i++)
    {
        data = (uint8_t) (arr[i] ^ crc);
        crc = (uint8_t)(lookup[data]);
    }
    printf ("CRC calculated : %x", crc);
}
