unsigned long delayTime = 200; // Delay between Frames


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

byte byte_upleft[] {
  B01110000,
  B11100000,
  B11110000,
  B10111000,
  B00011100,
  B00001110,
  B00000111,
  B00000010
};

byte byte_upright[] {
  B00001110,
  B00000111,
  B00001111,
  B00011101,
  B00111000,
  B01110000,
  B11100000,
  B01000000
};

byte byte_downleft[] {
  B00000010,
  B00000111,
  B00001110,
  B00011100,
  B10111000,
  B11110000,
  B11100000,
  B01110000
};

byte byte_downright[] {
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

byte byte_offHeart[] {

  B00000000,
  B01000010,  // First frame of invader #1
  B10100101,
  B10011001,
  B01000010,
  B00100100,
  B00011000,
  B00000000
};
byte byte_smallheart[] {

  B00000000,
  B00000000,  // First frame of invader #1
  B00000000,
  B00100100,
  B00111100,
  B00011000,
  B00000000,
  B00000000
};

byte liczba[] {
  B11100110,
  B00100010,  // 71
  B01000010,
  B01000111,
  B00000000,
  B00100100,
  B00111100,
  B00011000
};

void liczbaanim(){
  show(liczba);
};

byte kwiatLotosu[] {
  B00000000,
  B00011000,  // 71
  B00111100,
  B00111100,
  B00011000,
  B00011000,
  B11011011,
  B11111111
};

byte poop[] {
  B01000001,
  B10011010,  // 71
  B10111100,
  B00111100,
  B01111110,
  B01011010,
  B11100111,
  B11111111
};

byte poop2[] {
  B11000001,
  B01011001,  // 71
  B01111100,
  B00111100,
  B01111110,
  B01011010,
  B11100111,
  B11111111
};

byte msg[] {
  B00000000,
  B11111111,
  B11000011,
  B10111101,
  B10000001,
  B10000001,
  B10000001,
  B11111111
};

byte msg2[] {
  B00000000,
  B00000000,
  B11111111,
  B11000011,
  B10111101,
  B10000001,
  B10000001,
  B11111111
};

byte msg3[] {
  B00000000,
  B00000000,
  B00000000,
  B11111111,
  B11000011,
  B10111101,
  B10000001,
  B11111111
};

byte msg4[] {
  B10100111,
  B11100110,
  B10100111,
  B11111111,
  B11000011,
  B10111101,
  B10000001,
  B11111111
};

byte msg5[] {
  B10100111,
  B11100110,
  B10100111,
  B00000000,
  B00000000,
  B10000111,
  B10000111,
  B11100100
};

/* animacja jesli osoba zle sie poczuje */
void helpanim() {
  show(msg);
  delay(300);
  show(msg2);
  delay(300);
  show(msg3);
  //delay(300);
  //show(msg4);
  delay(400);
  show(msg5);
  delay(1500);
};

byte load1[] {
  B00000000,
  B01100000,
  B00111110,
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B10000000
};

byte load2[] {
  B00000000,
  B01100000,
  B00111110,
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B11100000
};

byte load3[] {
  B00000000,
  B01100000,
  B00111110,
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B11111100
};

byte load4[] {
  B00000000,
  B01100000,
  B00111110,
  B00011000,
  B00011000,
  B00011000,
  B00000000,
  B11111111
};

void welcomeload() {
  show(load1);
  delay(400);
  show(load2);
  delay(300);
  show(load3);
  delay(600);
  show(load4);
  delay(300);
}

byte phone1[] {
  B00000000,
  B01100000,
  B01011110,
  B01000010,
  B01000010,
  B01000010,
  B01011010,
  B01111110
};

byte phone2[] {
  B01110000,
  B10001000,
  B10001000,
  B01111000,
  B00011000,
  B00001100,
  B00000110,
  B00000000
};

byte okay[]{
  B00000000,
  B00000011,
  B00000011,
  B00000110,
  B11000110,
  B01101100,
  B00111000,
  B00000000
};

byte nookay[]{
  B00000000,
  B11000011,
  B01100011,
  B00110110,
  B00011110,
  B00001110,
  B00011011,
  B00110001
};

void phoneanim() {
  for (int i = 0; i < 2; i++) {
    show(phone1);
    delay(600);
    show(phone2);
    delay(600);
  }
  //show(okay);
  //delay(800);
};

void showOK() {
    show(phone1);
    delay(400);
    show(okay);
    delay(800);
    turnallOFF(); 
};

void phoneanimbad() {
  for (int i = 0; i < 2; i++) {
    show(phone1);
    delay(600);
    show(phone2);
    delay(600);
  }
  show(nookay);
  delay(800);
};

byte gps1[]{
  B00110000,
  B11011011,
  B00001100,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte gps2[]{
  B00110000,
  B11011011,
  B00001100,
  B00000000,
  B00011000,
  B00000000,
  B00000000,
  B00000000
};

byte gps3[]{
  B00110000,
  B11011011,
  B00001100,
  B00000000,
  B00011000,
  B00111100,
  B00000000,
  B00000000
};

byte gps4[]{
  B00110000,
  B11011011,
  B00001100,
  B00000000,
  B00011000,
  B00111100,
  B01111110,
  B00000000
};


void gpsanim(){
  for (int i = 0; i < 2; i++) {
    show(gps1);
    delay(300);
    show(gps2);
    delay(300);
    show(gps3);
    delay(300);
    show(gps4);
    delay(300);
    show(gps3);
    delay(300);
    show(gps2);
    delay(300);
    show(gps1);
    delay(300);
  }
  show(okay);
  delay(800);
};
void show_heartoff() {
  show(byte_offHeart);
  delay(100);
};

void poopanim() {
  show(poop);
  delay(200);
  show(poop2);
  delay(400);
};
void show_beat() {
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
void dollewo() {
  show(byte_downleft);
}

void lewo(){
  show(byte_left);
}

void goralewo() {
  show(byte_upleft);
}

void przod() {
  show(byte_fow);
}

void goraprawo() {
  show(byte_upright);
}

void prawo() {
  show(byte_right);
}

void dolprawo() {
  show(byte_downright);
}

void turnallOFF(){
  show(byte_turnOFF);
}
/*
 * Odpowiada za wyświetlanie danych po kolei
 * param toshow[] bitowa tablica potrzebna do wyświetlania dancyh na 8x8
 */
void show(byte toshow[])
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0, i, toshow[i]);
  }
}


/*
 * Brak połączenia z BT
 */
void bt_msg() {
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
  delay(2 * DELAYS);

  show(byte_smile2);
  delay(DELAYS);
  show(byte_smile);
  delay(DELAYS);
  show(byte_turnOFF);

}
