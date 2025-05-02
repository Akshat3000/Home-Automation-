/*
  The following variables are automatically generated and updated when changes are made to the Thing

  CloudSwitch balcony_LED;
  CloudSwitch fan;
  CloudSwitch white_LED;
  CloudSwitch yellow_LED;
*/

#include "thingProperties.h"
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 4;

int i = 3;
int temp = i;

IRsend irsend(kIrLed);

// The following raw data was collected using AC's remote blasted on an IR Receiver and decoded to give these results;
// In layman language is the POWER ON CODE FOR THE AC in my room :

uint16_t rawDataON[211] = {3298, 3342,  400, 1268,  376, 446,  374, 1272,  402, 1268,  376,
                           444,  378, 446,  432, 1242,  404, 416,  378, 1270,  430, 392,  432, 1240,  376, 446,  432,
                           1214,  434, 1238,  404, 1242,  434, 416,  404, 416,  406, 1240,  432, 392,  432, 414,  406,
                           1240,  434, 1210,  436, 414,  404, 1240,  432, 1216,  432, 416,  404, 416,  432, 1214,  430,
                           416,  406, 418,  402, 418,  434, 1210,  434, 1240,  402, 1242,  430, 1240,  406, 1238,  434,
                           390,  432, 414,  404, 418,  406, 414,  434, 392,  430, 1240,  404, 1242,  432, 388,  432,
                           392,  430, 416,  406, 1238,  432, 388,  432, 1240,  406, 1240,  432, 1240,  406, 1240,
                           430, 1212,  432, 416,  406, 416,  432, 390,  434, 388,  434, 416,  404, 418,  402, 418,
                           434, 390,  434, 390,  430, 420,  404, 416,  402, 420,  432, 390,  432, 418,  404, 418,  402,
                           420,  430, 390,  432, 390,  434, 416,  404, 418,  404, 418,  430, 392,  434, 392,  430, 418,
                           404, 418,  434, 390,  430, 392,  432, 418,  404, 420,  374, 446,  432, 392,  432, 390,  430,
                           418,  402, 420,  404, 414,  434, 390,  432, 416,  406, 1240,  434, 1214,  430, 416,  404,
                           420,  404, 416,  432, 394,  430, 390,  432, 1242,  402, 1242,  430, 420,  404, 418,  402,
                           1242,  430, 480,  344, 416,  404
                          };

// POWER OFF CODE FOR THE AC in my room :

uint16_t rawDataOFF[211] = {3266, 3346,  396, 1278,  368, 452,  370, 1274,  396, 1276,  372,
                            450,  372, 450,  396, 1278,  368, 452,  372, 1278,  392, 430,  392, 1252,  394, 428,  446,
                            1198,  450, 1222,  424, 1222,  448, 400,  424, 398,  366, 1280,  394, 428,  424, 452,  340,
                            1302,  398, 1248,  400, 452,  372, 1270,  402, 1246,  398, 448,  376, 448,  402, 1244,  400,
                            446,  372, 452,  370, 450,  400, 1246,  400, 1272,  374, 1272,  402, 1270,  374, 1274,  398,
                            424,  400, 452,  368, 452,  370, 452,  398, 424,  398, 1272,  374, 1272,  398, 428,  394,
                            424,  398, 452,  368, 1274,  402, 426,  396, 1272,  372, 1270,  398, 1274,  386, 1258,  400,
                            1246,  400, 450,  396, 426,  396, 424,  400, 420,  402, 450,  370, 450,  372, 450,  400,
                            426,  396, 424,  398, 450,  370, 452,  396, 424,  400, 422,  424, 426,  396, 428,  370, 448,
                            426, 396,  400, 426,  396, 450,  370, 452,  374, 450,  400, 422,  424, 398,  400, 448,  398,
                            424,  402, 420,  398, 430,  396, 448,  398, 428,  396, 424,  416, 406,  398, 424,  426, 426,
                            368, 452,  396, 424,  398, 424,  418, 430,  370, 452,  372, 1276,  396, 424,  426, 422,  372,
                            452,  398, 424,  400, 422,  424, 1248,  372, 452,  396, 428,  398, 420,  400, 1276,  370,
                            448,  424, 404,  418
                           };


int yellow = 2;
int white = 5;
int fan_ = 14;
int balcony = 12;
int tube = 13;

void setup() {
  pinMode(yellow, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(fan_, OUTPUT);
  pinMode(balcony, OUTPUT);
  pinMode(tube, OUTPUT);
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  irsend.begin();
#if ESP8266
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
#else  // ESP8266
  Serial.begin(115200, SERIAL_8N1);
#endif  // ESP8266
}

void loop() {
  ArduinoCloud.update();

}

/*
  Since YellowLED is READ_WRITE variable, onYellowLEDChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onYellowLEDChange()  {
  if (yellow_LED)
    digitalWrite(yellow, LOW);
  else
    digitalWrite(yellow, HIGH);
}

/*
  Since BalconyLED is READ_WRITE variable, onBalconyLEDChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBalconyLEDChange()  {
  if (balcony_LED)
    digitalWrite(balcony, LOW);
  else
    digitalWrite(balcony, HIGH);
}

/*
  Since Fan is READ_WRITE variable, onFanChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onFanChange()  {
  if (fan)
    digitalWrite(fan_, LOW);
  else
    digitalWrite(fan_, HIGH);
}

/*
  Since WhiteLED is READ_WRITE variable, onWhiteLEDChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onWhiteLEDChange()  {
  if (white_LED)
    digitalWrite(white, LOW);
  else
    digitalWrite(white, HIGH);
}


void onACChange()  {
  if (aC)
  {
    while (i)
    {
      irsend.sendRaw(rawDataON, 211, 38);  // Send a raw data capture at 38kHz.
      delay(500);
      i = i - 1;
    }
    i = temp;
  }
  else
  {
    while (i)
    {
      irsend.sendRaw(rawDataOFF, 211, 38);  // Send a raw data capture at 38kHz.
      delay(500);
      i = i - 1;
    }
    i = temp;
  }
}
