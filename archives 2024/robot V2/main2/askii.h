#ifndef askii_h
#define askii_h

const byte nothing[8] PROGMEM = {B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
const byte arrow[8] PROGMEM  = {B00011000,B00111100,B01111110,B11111111,B00011000,B00011000,B00011000,B00011000};
const byte lettres[36][8] PROGMEM= {
  {
    B00000000,
    B11111100,
    B00010010,
    B00010001,
    B00010010,
    B11111100,
    B00000000,
    B00000000
  },{
    B00000000,
    B11111111,
    B10001001,
    B10001001,
    B10001001,
    B01110110,
    B00000000,
    B00000000
  },{
    B00000000,
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B01000010,
    B00000000,
    B00000000
  },{
    B00000000,
    B11111111,
    B10000001,
    B10000001,
    B10000001,
    B01111110,
    B00000000,
    B00000000
  },{
    B00000000,
    B11111111,
    B10001001,
    B10001001,
    B10001001,
    B10000001,
    B00000000,
    B00000000
  },{
    B00000000,
    B11111111,
    B00001001,
    B00001001,
    B00001001,
    B00000001,
    B00000000,
    B00000000
  },{
    B00000000,
    B01111110,
    B10000001,
    B10010001,
    B10010001,
    B01110000,
    B00000000,
    B00000000
  },{
    B00000000,
    B11111111,
    B00001000,
    B00001000,
    B00001000,
    B11111111,
    B00000000,
    B00000000
  },{
    B00000000,
    B10000001,
    B10000001,
    B11111111,
    B10000001,
    B10000001,
    B00000000,
    B00000000
  },{
    B00000000,
    B01100000,
    B10000000,
    B10000000,
    B10000000,
    B01111111,
    B00000000,
    B00000000
  },{
    B00000000,
    B11111111,
    B00011000,
    B00100100,
    B01000010,
    B10000001,
    B00000000,
    B00000000
  },{
    B00000000,
    B11111111,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B00000000,
    B00000000
  },{
    B00000000,
    B11111111,
    B00000010,
    B00000100,
    B00000010,
    B11111111,
    B00000000,
    B00000000
  },{
    B00000000,
    B11111111,
    B00000110,
    B00011000,
    B01100000,
    B11111111,
    B00000000,
    B00000000
  },{
    B00000000,
    B01111110,
    B10000001,
    B10000001,
    B10000001,
    B01111110,
    B00000000,
    B00000000
  },{
    B00000000,
    B11111111,
    B00001001,
    B00001001,
    B00001001,
    B00000110,
    B00000000,
    B00000000
  },{
    B00000000,
    B01111110,
    B10000001,
    B10100001,
    B11000001,
    B11111110,
    B00000000,
    B00000000
  },{
    B00000000,
    B11111111,
    B00001001,
    B00011001,
    B00101001,
    B11000110,
    B00000000,
    B00000000
  },{
    B00000000,
    B01000110,
    B10001001,
    B10001001,
    B10010001,
    B01100110,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000001,
    B00000001,
    B11111111,
    B00000001,
    B00000001,
    B00000000,
    B00000000
  },{
    B00000000,
    B01111111,
    B10000000,
    B10000000,
    B10000000,
    B01111111,
    B00000000,
    B00000000
  },{
    B00000000,
    B00111111,
    B01000000,
    B10000000,
    B01000000,
    B00111111,
    B00000000,
    B00000000
  },{
    B00000000,
    B11111111,
    B01000000,
    B00100000,
    B01000000,
    B11111111,
    B00000000,
    B00000000
  },{
    B00000000,
    B11100011,
    B00010100,
    B00001000,
    B00010100,
    B11100011,
    B00000000,
    B00000000
  },{
    B00000000,
    B00000011,
    B00000100,
    B11111000,
    B00000100,
    B00000011,
    B00000000,
    B00000000
  },{
    B00000000,
    B11000001,
    B10110001,
    B10001001,
    B10000101,
    B10000011,
    B00000000,
    B00000000
  },{ 
    B00000000, 
    B01111110, 
    B10000001, 
    B10000001, 
    B10000001, 
    B10000001, 
    B01111110, 
    B00000000 
  },{
    B00000000,
    B00000000,
    B10000000,
    B10000001,
    B11111111,
    B10000000,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B01110000,
    B10001001,
    B10001001,
    B10001001,
    B10001001,
    B00000110,
    B00000000
  },
  {
    B00000000,
    B10000001,
    B10001001,
    B10001001,
    B10001001,
    B10001001,
    B01110110,
    B00000000
  },
  {
    B00000000,
    B00001111,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B11111111,
    B00000000
  },
  {
    B00000000,
    B00000110,
    B10001001,
    B10001001,
    B10001001,
    B10001001,
    B01110000,
    B00000000
  },
  {
    B00000000,
    B01110110,
    B10001001,
    B10001001,
    B10001001,
    B10001001,
    B01110000,
    B00000000
  },
  {
    B00000000,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B11111110,
    B00000000
  },
  {
    B00000000,
    B01110110,
    B10001001,
    B10001001,
    B10001001,
    B10001001,
    B01110110,
    B00000000
  },
  {
    B00000000,
    B00000110,
    B10001001,
    B10001001,
    B10001001,
    B10001001,
    B01110110,
    B00000000
  }
};
const char inclued_char[36]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};

const byte animation_demarage_part1[16][8] PROGMEM= {
  {B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000},
{B10000001,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000},
{B11000011,
B10000001,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000},
{B11100111,
B11000011,
B10000001,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000},
{B11100111,
B11000011,
B10000001,
B10000001,
B00000000,
B00011000,
B00011000,
B00000000},
{B11000011,
B10000001,
B10000001,
B00000000,
B00011000,
B00100100,
B00100100,
B00011000},
{B11000011,
B10000001,
B00000000,
B00011000,
B00100100,
B01000010,
B01000010,
B00100100},
{B10000001,
B00000000,
B00111100,
B01000010,
B10000001,
B10000001,
B10000001,
B10000001},
{B00000000,
B00111100,
B01000010,
B10000001,
B00011000,
B00011000,
B00011000,
B00000000},
{B00111100,
B01000010,
B10000001,
B00011000,
B00100100,
B00111100,
B00100100,
B00011000},
{B01000010,
B10000001,
B00000000,
B00111100,
B01000010,
B01011010,
B01000010,
B00111100},
{B10000001,
B01000010,
B00000000,
B10011001,
B10100101,
B00111100,
B00100100,
B00011000},
{B10100101,
B01000010,
B00000000,
B00011000,
B00011000,
B10011001,
B10011001,
B00011000},
{B10000001,
B01000010,
B00000000,
B10011001,
B10100101,
B00111100,
B00100100,
B00011000},
{B01000010,
B10000001,
B00000000,
B00111100,
B01000010,
B01011010,
B01000010,
B00111100}
};

const byte animation_demarage_part2[16][8] PROGMEM= {
  {B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000},
{B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000},
{B00000000,
B00000000,
B00000000,
B10000001,
B10000001,
B00000000,
B00000000,
B00000000},
{B00000000,
B00000000,
B10000001,
B11000011,
B11000011,
B10000001,
B00000000,
B00000000},
{B10000001,
B10000001,
B11000011,
B11100111,
B11100111,
B11000011,
B10000001,
B10000001},
{B00000000,
B10000001,
B10000001,
B11000011,
B11000011,
B10000001,
B10000001,
B00000000},
{B00011000,
B00000000,
B00000000,
B10000001,
B10000001,
B00000000,
B00000000,
B00011000},
{B01000010,
B00111100,
B00000000,
B10000001,
B10000001,
B00000000,
B00111100,
B01000010},
{B10000001,
B01000010,
B00111100,
B00000000,
B00000000,
B00111100,
B01000010,
B10000001},
{B00000000,
B10000001,
B01000010,
B00111100,
B00111100,
B01000010,
B10000001,
B00000000},
{B00000000,
B00000000,
B10000000,
B01000001,
B01000001,
B10000000,
B00000000,
B00000000},
{B00000000,
B00000000,
B01000000,
B10000001,
B10000001,
B01000000,
B00000000,
B00000000},
{B00000000,
B00000000,
B01000000,
B10000001,
B10000001,
B01000000,
B00000000,
B00000000},
{B00000000,
B00000000,
B01000000,
B10000001,
B10000001,
B01000000,
B00000000,
B00000000},
{B00000000,
B00000000,
B01000000,
B10000001,
B10000001,
B01000000,
B00000000,
B00000000}
};

const byte animation_demarage_part3[16][8] PROGMEM= {
  {B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000},
{B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B10000001},
{B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B10000001,
B11000011},
{B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B10000001,
B11000011,
B11100111},
{B00000000,
B00011000,
B00011000,
B00000000,
B10000001,
B10000001,
B11000011,
B11100111},
{B00011000,
B00100100,
B00100100,
B00011000,
B00000000,
B10000001,
B10000001,
B11000011},
{B00100100,
B01000010,
B01000010,
B00100100,
B00011000,
B00000000,
B10000001,
B11000011},
{B10000001,
B10000001,
B10000001,
B10000001,
B01000010,
B00111100,
B00000000,
B10000001},
{B00000000,
B00011000,
B00011000,
B00011000,
B10000001,
B01000010,
B00111100,
B00000000},
{B00011000,
B00100100,
B00111100,
B00100100,
B00011000,
B10000001,
B01000010,
B00111100},
{B00111100,
B01000010,
B01011010,
B01000010,
B00111100,
B00000000,
B10000001,
B01000010},
{B00011000,
B00100100,
B00111100,
B10100101,
B10011001,
B00000000,
B01000010,
B10000001},
{B00011000,
B10011001,
B10011001,
B00011000,
B00011000,
B00000000,
B01000010,
B10100101},
{B00011000,
B00100100,
B00111100,
B10100101,
B10011001,
B00000000,
B01000010,
B10000001},
{B00111100,
B01000010,
B01011010,
B01000010,
B00111100,
B00000000,
B10000001,
B01000010}
};


#endif
