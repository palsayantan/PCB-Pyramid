/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest
 *************************************************************/
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WS2812FX.h>

#define LED_COUNT 40
#define LED_PIN 2

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "********************************";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Sayantan";
char pass[] = "sayantan";

WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800);

int fxSpeed = 1000;
int fxBrigheness = 50;

int r = 0;
int g = 0;
int b = 0;

//int effect;

BLYNK_WRITE(V0)
{
  r = param[0].asInt();
  g = param[1].asInt();
  b = param[2].asInt();
  ws2812fx.setColor(g, r, b);
  ws2812fx.setMode(FX_MODE_STATIC);
}

BLYNK_WRITE(V1)
{
  fxSpeed = param.asInt();
  ws2812fx.setSpeed(fxSpeed);
}
BLYNK_WRITE(V2)
{
  fxBrigheness = param.asInt();
  ws2812fx.setBrightness(fxBrigheness);
}
BLYNK_WRITE(V3)
{
  int next = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (next > 0) {
    ws2812fx.clear();
    ws2812fx.setMode((ws2812fx.getMode() + 1) % ws2812fx.getModeCount());
  }
}
BLYNK_WRITE(V4)
{
  int n = param.asInt();
  Serial.println(n);
  effects(n);
  
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  ws2812fx.init();
  ws2812fx.setBrightness(50);
  ws2812fx.setSpeed(1000);
  ws2812fx.setColor(0x000000);
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.start();
  Serial.println("start");
}

void loop()
{
  Blynk.run();
  ws2812fx.service();
}

void effects(int effect) {
  if (effect == 1) {
    ws2812fx.clear();
    for(int i=0;i<5;i++){
    colorWipe(ws2812fx.Color(g, r, b));
  }
  }
  if (effect == 2) {
    ws2812fx.clear();
    for(int i=0;i<5;i++){
    boxWipe(ws2812fx.Color(g, r, b));
  }
  }
  if (effect == 3) {
    ws2812fx.clear();
    for(int i=0;i<5;i++){
    lineWipe(ws2812fx.Color(g, r, b));
  }
  }
  if (effect == 4) {
    ws2812fx.clear();
    for(int i=0;i<5;i++){
    reverseLineWipe(ws2812fx.Color(g, r, b));
  }
  }
  if (effect == 5) {
    ws2812fx.clear();
    for(int i=0;i<5;i++){
    faceWipe(ws2812fx.Color(g, r, b));
  }
  }
  if (effect == 6) {
    ws2812fx.clear();
    for(int i=0;i<5;i++){
    vLineWipe(ws2812fx.Color(g, r, b));
  }
  }
  if (effect == 7) {
    ws2812fx.clear();
    for(int i=0;i<5;i++){
    triangleWipe(ws2812fx.Color(g, r, b));
  }
  }
  if (effect == 8) {
    ws2812fx.clear();
    for(int i=0;i<5;i++){
    triWipe(ws2812fx.Color(g, r, b));
  }
  }
  if (effect == 9) {
    ws2812fx.clear();
    for(int i=0;i<5;i++){
    vLnWipe(ws2812fx.Color(g, r, b));
  }
  }
}

void colorWipe(uint32_t color) {
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 4; i++) {
      ws2812fx.setPixelColor(j * 10 + i, color);
      ws2812fx.show();
      delay(50);
    }
  }
  for (int j = 0; j < 4; j++) {
    for (int i = 6; i > 3; i--) {
      ws2812fx.setPixelColor(j * 10 + i, color);
      ws2812fx.show();
      delay(50);
    }
  }
  for (int j = 0; j < 4; j++) {
    for (int i = 7; i < 9; i++) {
      ws2812fx.setPixelColor(j * 10 + i, color);
      ws2812fx.show();
      delay(50);
    }
  }
  for (int j = 0; j < 4; j++) {
    for (int i = 9; i > 8; i--) {
      ws2812fx.setPixelColor(j * 10 + i, color);
      ws2812fx.show();
      delay(50);
    }
  }
}

void lineWipe(uint32_t color) {
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 0, color);
    ws2812fx.setPixelColor(i * 10 + 1, color);
    ws2812fx.setPixelColor(i * 10 + 2, color);
    ws2812fx.setPixelColor(i * 10 + 3, color);
  }
  ws2812fx.show();
  delay(200);
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 4, color);
    ws2812fx.setPixelColor(i * 10 + 5, color);
    ws2812fx.setPixelColor(i * 10 + 6, color);
  }
  ws2812fx.show();
  delay(200);
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 7, color);
    ws2812fx.setPixelColor(i * 10 + 8, color);
  }
  ws2812fx.show();
  delay(200);
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 9, color);
  }
  ws2812fx.show();
  delay(200);
}

void boxWipe(uint32_t color) {
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 0, color);
    ws2812fx.setPixelColor(i * 10 + 1, color);
    ws2812fx.setPixelColor(i * 10 + 2, color);
    ws2812fx.setPixelColor(i * 10 + 3, color);
  }
  ws2812fx.show();
  delay(200);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 4, color);
    ws2812fx.setPixelColor(i * 10 + 5, color);
    ws2812fx.setPixelColor(i * 10 + 6, color);
  }
  ws2812fx.show();
  delay(200);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 7, color);
    ws2812fx.setPixelColor(i * 10 + 8, color);
  }
  ws2812fx.show();
  delay(200);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 9, color);
  }
  ws2812fx.show();
  delay(200);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 7, color);
    ws2812fx.setPixelColor(i * 10 + 8, color);
  }
  ws2812fx.show();
  delay(200);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 4, color);
    ws2812fx.setPixelColor(i * 10 + 5, color);
    ws2812fx.setPixelColor(i * 10 + 6, color);
  }
  ws2812fx.show();
  delay(200);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 0, color);
    ws2812fx.setPixelColor(i * 10 + 1, color);
    ws2812fx.setPixelColor(i * 10 + 2, color);
    ws2812fx.setPixelColor(i * 10 + 3, color);
  }
  ws2812fx.show();
  delay(200);
  ws2812fx.clear();
}


void reverseLineWipe(uint32_t color) {
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 9, color);
  }
  ws2812fx.show();
  delay(200);
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 7, color);
    ws2812fx.setPixelColor(i * 10 + 8, color);
  }
  ws2812fx.show();
  delay(200);
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 4, color);
    ws2812fx.setPixelColor(i * 10 + 5, color);
    ws2812fx.setPixelColor(i * 10 + 6, color);
  }
  ws2812fx.show();
  delay(200);
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 0, color);
    ws2812fx.setPixelColor(i * 10 + 1, color);
    ws2812fx.setPixelColor(i * 10 + 2, color);
    ws2812fx.setPixelColor(i * 10 + 3, color);
  }
  ws2812fx.show();
  delay(200);
}

void faceWipe(uint32_t color) {
  for (int j = 0; j < 4; j++) {
    for (int i = 0; i < 10; i++) {
      ws2812fx.setPixelColor(j * 10 + i, color);
    }
    ws2812fx.show();
    delay(200);
  }
}

void triangleWipe(uint32_t color) {
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 1, color);
    ws2812fx.setPixelColor(i * 10 + 2, color);
    ws2812fx.setPixelColor(i * 10 + 5, color);
  }
  ws2812fx.show();
  delay(250);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 0, color);
    ws2812fx.setPixelColor(i * 10 + 3, color);
    ws2812fx.setPixelColor(i * 10 + 4, color);
    ws2812fx.setPixelColor(i * 10 + 6, color);
    ws2812fx.setPixelColor(i * 10 + 7, color);
    ws2812fx.setPixelColor(i * 10 + 8, color);
    ws2812fx.setPixelColor(i * 10 + 9, color);
  }
  ws2812fx.show();
  delay(250);
  ws2812fx.clear();
}


void vLnWipe(uint32_t color) {
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 0, color);
    ws2812fx.setPixelColor(i * 10 + 6, color);
    ws2812fx.setPixelColor(i * 10 + 7, color);
    ws2812fx.setPixelColor(i * 10 + 9, color);
  }
  ws2812fx.show();
  delay(200);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 1, color);
    ws2812fx.setPixelColor(i * 10 + 5, color);
    ws2812fx.setPixelColor(i * 10 + 8, color);
  }
  ws2812fx.show();
  delay(200);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 2, color);
    ws2812fx.setPixelColor(i * 10 + 4, color);
  }
  ws2812fx.show();
  delay(200);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 3, color);
  }
  ws2812fx.show();
  delay(200);
  ws2812fx.clear();
}

void triWipe(uint32_t color) {
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 7, color);
    ws2812fx.setPixelColor(i * 10 + 8, color);
    ws2812fx.setPixelColor(i * 10 + 9, color);
  }
  ws2812fx.show();
  delay(150);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 8, color);
    ws2812fx.setPixelColor(i * 10 + 4, color);
    ws2812fx.setPixelColor(i * 10 + 5, color);
  }
  ws2812fx.show();
  delay(150);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 4, color);
    ws2812fx.setPixelColor(i * 10 + 2, color);
    ws2812fx.setPixelColor(i * 10 + 3, color);
  }
  ws2812fx.show();
  delay(150);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 1, color);
    ws2812fx.setPixelColor(i * 10 + 0, color);
    ws2812fx.setPixelColor(i * 10 + 6, color);
  }
  ws2812fx.show();
  delay(150);
  ws2812fx.clear();
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 7, color);
    ws2812fx.setPixelColor(i * 10 + 6, color);
    ws2812fx.setPixelColor(i * 10 + 5, color);
  }
  ws2812fx.show();
  delay(150);
  ws2812fx.clear();
}


void vLineWipe(uint32_t color) {
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 3, color);
  }
  ws2812fx.show();
  delay(150);
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 2, color);
    ws2812fx.setPixelColor(i * 10 + 4, color);
  }
  ws2812fx.show();
  delay(150);
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 1, color);
    ws2812fx.setPixelColor(i * 10 + 5, color);
    ws2812fx.setPixelColor(i * 10 + 8, color);
  }
  ws2812fx.show();
  delay(150);
  for (int i = 0; i < 4; i++) {
    ws2812fx.setPixelColor(i * 10 + 0, color);
    ws2812fx.setPixelColor(i * 10 + 6, color);
    ws2812fx.setPixelColor(i * 10 + 7, color);
    ws2812fx.setPixelColor(i * 10 + 9, color);
  }
  ws2812fx.show();
  delay(150);
}
