// This program read arrays RGB values that are stored in txt files from an SD card
// and display an image column by column on an RGB LED strip. The LED pattern simulate 
// a 2D image when recorded with a long exposure photo.
// Written by Thanky To
// For more detailed instructions and examples, please visit https://github.com/ThankyTo/Light-Painting-Stick/

#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <SD.h>

//User's defined parameters can be modified here
int NUMBER_OF_FILES = 10;
int NUMBER_OF_LEDS = 60;


int delayTime = 50;
int fileNumber = 0;

//Pin declearation
int TRIGGER = 4;
int SELECT = 5;
int LED_PIN = 6;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMBER_OF_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(TRIGGER, INPUT);
  pinMode(SELECT, INPUT);
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  strip.begin();
  displayNothing();
}

void loop() {
  
  while (digitalRead(TRIGGER) == LOW && digitalRead(SELECT) == LOW) {
    //waits
  }

  // Pressing the SELECT button will increment the curent file number to read. 
  // If the last file is reached, the selection is wrap back to file 0.
  if (digitalRead(SELECT) == HIGH) {
    //increment file number
    fileNumber++;
    if (fileNumber >= NUMBER_OF_FILES) {
      fileNumber = 0;
    }
    Serial.println(fileNumber);
    displayFileNumber(fileNumber);
    delay(500);
    displayNothing();
  }

  // Pressing trigger will display the current file on the LED strip.
  else if (digitalRead(TRIGGER) == HIGH) {
    String fileName = String(fileNumber) + ".txt";
    displayFile(fileName);
    displayNothing();
  }
}

// This function takes a file name, open the txt file of RGB values, 
// then display them on to the RGB LED strip, column by column, to simulate a 2D image.
// If the file doesn't open, an error message will be printed on serial.
void displayFile(String fileName) {
  File myFile = SD.open(fileName);
  if (myFile) {
    Serial.print(fileName);
    Serial.println();

    // read from the file until there's nothing else in it:

    while (myFile.available()) {
      int i;
      for (i = 0; i < NUMBER_OF_LEDS && myFile.available(); i++) {
        int r = myFile.parseInt();
        int g = myFile.parseInt();
        int b = myFile.parseInt();
        strip.setPixelColor(i,r,g,b);
      }
      strip.show();
      delay(delayTime);
    }

    // close the file:
    myFile.close();
  } else {
    Serial.print("error opening ");
  }
}

// This function turns off all the LEDs on the LED strip
void displayNothing() {
  int i;
  for (i = 0; i < NUMBER_OF_LEDS; i++) {
    strip.setPixelColor(i,0,0,0);
  }
  strip.show();
}

// This function takes the file number, convert it to binary 
// and display the value on to the LED strip.
// Red is 0 and white is 1.
void displayFileNumber(int fileNum) {
  int i;
  for(i = 0; fileNum > 0 &&  i < NUMBER_OF_LEDS; i++){
    int LED = fileNum % 2;
    if(LED)
      strip.setPixelColor(i,255,0,0);
    else
      strip.setPixelColor(i,50,50,50);
    fileNum = fileNum/2;
  }
  strip.show();
}


