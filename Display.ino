unsigned long delayTime=200;  // Delay between Frames


// Put values in arrays
byte byte_cane[] =
{
   B00000000,  // ikonka laski
   B00001111,
   B00001100,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00011000
};

byte byte_smile[] =
{
  B00000000,  // usmiech
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B01000010,
  B01111110,
  B00000000
};

byte byte_smile2[] =
{
  B00000000,  // usmiech 2
  B00000000,
  B00000000,
  B01100110,
  B00000000,
  B00000000,
  B01111110,
  B00000000
};

byte byte_turnOFF[] =
{
  B00000000, // wylaczenie
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte byte_BT1[] =
{
  B00000000, // B
  B00011000,
  B00010100,
  B00011000,
  B00011000,
  B00010100,
  B00011000,
  B00000000
};

byte byte_BT2[] =
{
  B01000010, // BT2
  B01011010,
  B00110100,
  B00011000,
  B00011000,
  B00110100,
  B01011010,
  B01000010
};

byte byte_fow[]
{
  B00011000, // BT2
  B00111100,
  B01111110,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000
};

byte byte_right[]
{
  B00000000, // BT2
  B00000100,
  B00000110,
  B11111111,
  B11111111,
  B00000110,
  B00000100,
  B00000000
};

byte byte_left[]
{
  B00000000,
  B00100000, // BT2
  B01100000,
  B11111111,
  B11111111,
  B01100000,
  B00100000,
  B00000000
};

byte byte_upleft[]{
  B01110000,
  B11100000,
  B11110000,
  B10111000,
  B00011100,
  B00001110,
  B00000111,
  B00000010
};

byte byte_upright[]{
  B00001110,
  B00000111,
  B00001111,
  B00011101,
  B00111000,
  B01110000,
  B11100000,
  B01000000
};

byte byte_downleft[]{
  B00000010,
  B00000111,
  B00001110,
  B00011100,
  B10111000,
  B11110000,
  B11100000,
  B01110000
};

byte byte_downright[]{
  B01000000,
  B11100000,
  B01110000,
  B00111000,
  B00011101,
  B00001111,
  B00000111,
  B00001110
};

byte heart1a[] =
{
   B00000000,
   B00000000,  // First frame of invader #1
   B01100110,
   B01111110,
   B00111100,
   B00011000,
   B00000000,
   B00000000
};

byte heart1b[] =
{
   B00000000,
   B01000010,  // First frame of invader #1
   B11100111,
   B11111111,
   B01111110,
   B00111100,
   B00011000,
   B00000000
};

byte byte_offHeart[]{

   B00000000,
   B01000010,  // First frame of invader #1
   B10100101,
   B10011001,
   B01000010,
   B00100100,
   B00011000,
   B00000000
};
byte byte_smallheart[]{

   B00000000,
   B00000000,  // First frame of invader #1
   B00000000,
   B00100100,
   B00111100,
   B00011000,
   B00000000,
   B00000000
};

void show_heartoff(){
  show(byte_offHeart);
  delay(100);
};

void show_beat(){
  int DALAYS = 150;
  show(byte_smallheart);
  delay(100);
  show(heart1a);
  delay(DALAYS);
  show(heart1b);
  delay(DALAYS);
  show(byte_offHeart);
  delay(50);
  
  
};

/*
 * Odpowiada za wyświetlanie danych po kolei
 * param toshow[] bitowa tablica potrzebna do wyświetlania dancyh na 8x8
 */
void show(byte toshow[])
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,toshow[i]);
  }
}


/*
 * Brak połączenia z BT
 */
void bt_msg(){
  int DELAYS = 100;
  show(byte_BT1);
  delay(DELAYS);
  show(byte_BT2);
  delay(DELAYS);

  show(byte_turnOFF);
}

/*
 * wiadomosc powitalna
 */
void welcome_msg()
{
  int DELAYS = 500;
  show(byte_cane);
  delay(2*DELAYS);

  show(byte_smile2);
  delay(DELAYS);
  show(byte_smile);
  delay(DELAYS);
  show(byte_turnOFF);

}

