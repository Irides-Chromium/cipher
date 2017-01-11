#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// 1. Give a password of length => [8, 64]
// 2. Randomly determine methods to use
//      Methods:
//      1. Bitwise XOR
//      2. Bitwise IOR
//      3. ADD
//      4. SUB
//      5. circulate
//      6. switching
//      7. random distribution (and add an order)
// 3. Compress the methods and orders into bytes, distribute randomly
// 4. Encrypt and compress the data
// Usable chars:
//
// 032      161  ¡
// 033  !   162  ¢
// 034  "   163  £
// 035  #   164  ¤
// 036  $   165  ¥
// 037  %   166  ¦
// 038  &   167  §
// 039  '   168  ¨
// 040  (   169  ©
// 041  )   170  ª
// 042  *   171  «
// 043  +   172  ¬
// 044  ,   174  ®
// 045  -   175  ¯
// 046  .   176  °
// 047  /   177  ±
// 048  0   178  ²
// 049  1   179  ³
// 050  2   180  ´
// 051  3   181  µ
// 052  4   182  ¶
// 053  5   183  ·
// 054  6   184  ¸
// 055  7   185  ¹
// 056  8   186  º
// 057  9   187  »
// 058  :   188  ¼
// 059  ;   189  ½
// 060  <   190  ¾
// 061  =   191  ¿
// 062  >   192  À
// 063  ?   193  Á
// 064  @   194  Â
// 065  A   195  Ã
// 066  B   196  Ä
// 067  C   197  Å
// 068  D   198  Æ
// 069  E   199  Ç
// 070  F   200  È
// 071  G   201  É
// 072  H   202  Ê
// 073  I   203  Ë
// 074  J   204  Ì
// 075  K   205  Í
// 076  L   206  Î
// 077  M   207  Ï
// 078  N   208  Ð
// 079  O   209  Ñ
// 080  P   210  Ò
// 081  Q   211  Ó
// 082  R   212  Ô
// 083  S   213  Õ
// 084  T   214  Ö
// 085  U   215  ×
// 086  V   216  Ø
// 087  W   217  Ù
// 088  X   218  Ú
// 089  Y   219  Û
// 090  Z   220  Ü
// 091  [   221  Ý
// 092  \   222  Þ
// 093  ]   223  ß
// 094  ^   224  à
// 095  _   225  á
// 096  `   226  â
// 097  a   227  ã
// 098  b   228  ä
// 099  c   229  å
// 100  d   230  æ
// 101  e   231  ç
// 102  f   232  è
// 103  g   233  é
// 104  h   234  ê
// 105  i   235  ë
// 106  j   236  ì
// 107  k   237  í
// 108  l   238  î
// 109  m   239  ï
// 110  n   240  ð
// 111  o   241  ñ
// 112  p   242  ò
// 113  q   243  ó
// 114  r   244  ô
// 115  s   245  õ
// 116  t   246  ö
// 117  u   247  ÷
// 118  v   248  ø
// 119  w   249  ù
// 120  x   250  ú
// 121  y   251  û
// 122  z   252  ü
// 123  {   253  ý
// 124  |   254  þ
// 125  }   255  ÿ
// 126  ~   256  Ā
// 32-126 161-256 !173 => 190 0xbe

int mbout(int ch) {
    //short ch = (short) atoi(argv[1]);
    int diff = ch - 128;
    putchar('\xC2' + (int) diff / 64);
    putchar('\x80' + fmod(diff, 64));
    return 0;
}