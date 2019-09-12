#include "bit_opt.h"
#include "stdio.h"

//typedef volatile unsigned char  vu8;
//typedef volatile unsigned short vu16;
//typedef volatile unsigned long  vu32;

//#define BIT_8(adr)  (*((vu8  *) (adr)))
//#define BIT_16(adr) (*((vu16 *) (adr)))
//#define BIT_32(adr) (*((vu32 *) (adr)))

//-------------------------bit0-bit1-bit2-bit3-bit4-bit5-bit6-bit7
unsigned char bit_site[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; 

/*清除某一位*/
void clearByteBit(unsigned char *byte,unsigned char n)
{
   *byte^=(*byte&(bit_site[n])) ^ 0x00;
}
/*强制设置某一位*/
void setByteBit(unsigned char *byte,unsigned char n,unsigned char value)
{
   *byte^=(*byte&(bit_site[n])) ^ (value<<n);
}
/*读取某一位*/
unsigned char readByteBit(unsigned char byte,unsigned char n)
{
   return (((byte>>n)&(0x01))==1);
}
/*取反某一位*/
void cpByteBit(unsigned char *byte,unsigned char n)
{
   unsigned char rxbit=readByteBit(*byte,n);
   setByteBit(byte,n,((~rxbit)&0x01));
}

/*显示一字节位*/
void showByteBit(unsigned char byte)
{
   unsigned char i=0;
   for(i=0;i<8;i++)
   {
     printf("%d",readByteBit(byte,7-i));
   }
}
