#include <stdio.h>

#define NBINS 128
#define BINMAPSHIFT      5
#define BITSPERMAP       (1U << BINMAPSHIFT) // Bit: 10 0000 每个Map共32个bit
#define BINMAPSIZE       (NBINS / BITSPERMAP) // 128/32 = 4  即表示128个bin需要4个binmap,分别为binmap[0] binmap[1] binmap[2] binmap[3],每个binmap包含32个bin

/*
binmap[0] 00 0000 ~  01 1111  0-31
binmap[1] 10 0000 ~  11 1111  32-63
binmap[2] 20 0000 ~ 101 1111  64-95
binmap[3] 30 0000 ~ 111 1111  96-127
*/

/* i即传入的NBINS,取值范围在0～127,通过向右移5位可获得其在binmap中的index,具体实现见idx2block(i)
  ┊将10 0000 - 1可得到 1 1111 & i 即掩码i仅保留i的后5位,取值范围为0-1 1111即1-31表示当前b在binmap中的偏移
  ┊再将1向左偏移此数,如101 0011 & 001 1111得到1 0011即19为i在binmap中的偏移值,最终得到0000 0000 0000 1000 0000 0000 0000 0000*/

#define idx2block(i)     ((i) >> BINMAPSHIFT)
#define idx2bit(i)       ((1U << ((i) & ((1U << BINMAPSHIFT) - 1))))

/* m为mstat结构体*/
#define mark_bin(m, i)    ((m)->binmap[idx2block (i)] |= idx2bit (i))// 将binmap中当前位置置1
#define unmark_bin(m, i)  ((m)->binmap[idx2block (i)] &= ~(idx2bit (i)))// 将binmap中当前位置置0
#define get_binmap(m, i)  ((m).binmap[idx2block (i)] & idx2bit (i))

typedef struct malloc_state                                                                         
{  
  /* Bitmap of bins */
  unsigned int binmap[BINMAPSIZE];
} mstat;

int main()
{
  mstat ms = {
    .binmap = {15,31,65,127}
  };
  
  printf("idx2block:%x\n",idx2block(34));
  printf("index:%x\n",idx2bit(34));
  printf("idx2bit_map:%x\n",ms.binmap[idx2block(34)]);
  printf("get_binmap:%x\n",get_binmap(ms,34));
  return 0;
}
