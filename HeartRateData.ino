// Put values in arrays

int hrdelay = 1200;
byte hr50[] =
{
  B11100110,
  B10001001,
  B11101001,
  B00101001,
  B11100110,
  B00000000,
  B00000000,
  B00000000
};

byte hr60[] =
{
  B11100110,  //
  B10001001,
  B11101001,
  B10101001,
  B11100110,
  B00000000,
  B00000000,
  B00000000
};

byte hr70[] =
{
  B11100110,  //
  B00101001,
  B01001001,
  B01001001,
  B01000110,
  B00000000,
  B00000000,
  B00000000
};

byte hr80[] =
{
  B01100110,  //
  B10011001,
  B01101001,
  B10011001,
  B01100110,
  B00000000,
  B00000000,
  B00000000
};

byte hr90[] =
{
  B01100110,  //
  B10011001,
  B01111001,
  B00011001,
  B01100110,
  B00000000,
  B00000000,
  B00000000
};

byte hr100[] =
{
  B11000000,
  B01001111,
  B01001001,
  B01001111,
  B00000000,
  B00001111,
  B00001001,
  B00001111
};

byte hr110[] =
{
  B11000110,
  B01000010,
  B01000010,
  B01000010,
  B00000000,
  B00001111,
  B00001001,
  B00001111
};

byte hr120[] =
{
  B01001110,
  B01000010,
  B01000100,
  B01001111,
  B00000000,
  B00001111,
  B00001001,
  B00001111
};

byte hr130[] =
{
  B01001110,
  B01000011,
  B01000011,
  B01001110,
  B00000000,
  B00001111,
  B00001001,
  B00001111
};

byte hr140[] =
{
  B01001000,
  B01001010,
  B01001111,
  B01000010,
  B00000000,
  B00001111,
  B00001001,
  B00001111
};

byte hr150[] =
{
  B01001110,
  B0100100,
  B01001111,
  B01000001,
  B00001111,
  B00001111,
  B00001001,
  B00001111
};
/*
void showhr40(hr40){
  showhr(hr40)
  delay(hrdelay)
}
*/
void showhr50(){
  showhr(hr50);
  delay(hrdelay);
}

void showhr60(){
  showhr(hr60);
  delay(hrdelay);
}

void showhr70(){
  showhr(hr70);
  delay(hrdelay);
}

void showhr80(){
  showhr(hr80);
  delay(hrdelay);
}

void showhr90(){
  showhr(hr90);
  delay(hrdelay);
}

void showhr100(){
  showhr(hr100);
  delay(hrdelay);
}

void showhr110(){
  showhr(hr110);
  delay(hrdelay);
}

void showhr120(){
  showhr(hr120);
  delay(hrdelay);
}


void showhr130(){
  showhr(hr130);
  delay(hrdelay);
}

void showhr140(){
  showhr(hr140);
  delay(hrdelay);
}

void showhr150(){
  showhr(hr150);
  delay(hrdelay);
}


/*
 * Odpowiada za wyświetlanie danych po kolei
 * param toshow[] bitowa tablica potrzebna do wyświetlania dancyh na 8x8
 */
void showhr(byte toshow[])
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0, i, toshow[i]);
  }
}

