#include <Wire.h>
#include <Servo.h>

#define FLAME_PIN 2
#define BUZZER_PIN 3
#define RELAY_PIN 7
#define SERVO_PIN 9
#define MQ2_PIN A0

#define OLED_ADDR 0x3C
#define SMOKE_THRESHOLD 400

Servo myServo;

bool previousFire = false;
bool previousSmoke = false;

// ---------- OLED COMMAND ----------
void oledCommand(byte cmd) {
  Wire.beginTransmission(OLED_ADDR);
  Wire.write(0x00);
  Wire.write(cmd);
  Wire.endTransmission();
}

// ---------- OLED DATA ----------
void oledData(byte data) {
  Wire.beginTransmission(OLED_ADDR);
  Wire.write(0x40);
  Wire.write(data);
  Wire.endTransmission();
}

// ---------- OLED INITIALIZATION ----------
void oledInit() {
  delay(100);

  oledCommand(0xAE);
  oledCommand(0xD5);
  oledCommand(0x80);
  oledCommand(0xA8);
  oledCommand(0x3F);
  oledCommand(0xD3);
  oledCommand(0x00);
  oledCommand(0x40);
  oledCommand(0x8D);
  oledCommand(0x14);
  oledCommand(0x20);
  oledCommand(0x02);
  oledCommand(0xA1);
  oledCommand(0xC8);
  oledCommand(0xDA);
  oledCommand(0x12);
  oledCommand(0x81);
  oledCommand(0xCF);
  oledCommand(0xD9);
  oledCommand(0xF1);
  oledCommand(0xDB);
  oledCommand(0x40);
  oledCommand(0xA4);
  oledCommand(0xA6);
  oledCommand(0xAF);
}

// ---------- CLEAR OLED ----------
void oledClear() {
  for (byte page = 0; page < 8; page++) {
    oledCommand(0xB0 + page);
    oledCommand(0x00);
    oledCommand(0x10);

    for (byte i = 0; i < 128; i++) {
      oledData(0x00);
    }
  }
}

// ---------- FONT A-Z ----------
const byte font[26][5] = {
  {0x7E,0x11,0x11,0x11,0x7E},
  {0x7F,0x49,0x49,0x49,0x36},
  {0x3E,0x41,0x41,0x41,0x22},
  {0x7F,0x41,0x41,0x22,0x1C},
  {0x7F,0x49,0x49,0x49,0x41},
  {0x7F,0x09,0x09,0x09,0x01},
  {0x3E,0x41,0x49,0x49,0x7A},
  {0x7F,0x08,0x08,0x08,0x7F},
  {0x00,0x41,0x7F,0x41,0x00},
  {0x20,0x40,0x41,0x3F,0x01},
  {0x7F,0x08,0x14,0x22,0x41},
  {0x7F,0x40,0x40,0x40,0x40},
  {0x7F,0x02,0x0C,0x02,0x7F},
  {0x7F,0x04,0x08,0x10,0x7F},
  {0x3E,0x41,0x41,0x41,0x3E},
  {0x7F,0x09,0x09,0x09,0x06},
  {0x3E,0x41,0x51,0x21,0x5E},
  {0x7F,0x09,0x19,0x29,0x46},
  {0x46,0x49,0x49,0x49,0x31},
  {0x01,0x01,0x7F,0x01,0x01},
  {0x3F,0x40,0x40,0x40,0x3F},
  {0x1F,0x20,0x40,0x20,0x1F},
  {0x3F,0x40,0x38,0x40,0x3F},
  {0x63,0x14,0x08,0x14,0x63},
  {0x07,0x08,0x70,0x08,0x07},
  {0x61,0x51,0x49,0x45,0x43}
};

// ---------- PRINT CHARACTER ----------
void oledChar(char c, byte scale) {
  if (c == ' ') {
    for (byte i = 0; i < 6 * scale; i++) {
      oledData(0x00);
    }
    return;
  }

  if (c < 'A' || c > 'Z') {
    return;
  }

  byte index = c - 'A';

  for (byte col = 0; col < 5; col++) {
    byte line = font[index][col];

    for (byte s = 0; s < scale; s++) {
      oledData(line);
    }
  }

  for (byte s = 0; s < scale; s++) {
    oledData(0x00);
  }
}

// ---------- PRINT TEXT ----------
void oledText(const char* text, byte page, byte scale) {
  oledCommand(0xB0 + page);
  oledCommand(0x00);
  oledCommand(0x10);

  while (*text) {
    oledChar(*text, scale);
    text++;
  }
}

// ---------- STARTUP SCREEN ----------
void showStartup() {
  oledClear();

  oledText("DEVELOPED", 0, 1);
  oledText("BY", 1, 1);
  oledText("RITIK", 3, 2);
  oledText("PRAJAPAT", 6, 1);

  delay(3000);
  oledClear();
}

// ---------- SETUP ----------
void setup() {
  pinMode(FLAME_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Active-LOW relay: HIGH means OFF
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(BUZZER_PIN, LOW);

  myServo.attach(SERVO_PIN);
  myServo.write(0);

  Wire.begin();
  oledInit();

  showStartup();
}

// ---------- MAIN LOOP ----------
void loop() {
  int flame = digitalRead(FLAME_PIN);
  int smoke = analogRead(MQ2_PIN);

  // Flame sensor: LOW means fire detected
  bool fireDetected = (flame == LOW);

  // MQ-2: reading above threshold means smoke detected
  bool smokeDetected = (smoke > SMOKE_THRESHOLD);

  // Fire: buzzer ON
  digitalWrite(
    BUZZER_PIN,
    fireDetected ? HIGH : LOW
  );

  // Fire: servo moves to 90 degrees
  myServo.write(fireDetected ? 90 : 0);

  // Smoke: active-LOW relay ON
  digitalWrite(
    RELAY_PIN,
    smokeDetected ? LOW : HIGH
  );

  // Update OLED only when status changes
  if (fireDetected != previousFire ||
      smokeDetected != previousSmoke) {

    oledClear();

    if (fireDetected && smokeDetected) {
      oledText("SMOKE", 0, 1);
      oledText("DETECT", 1, 1);
      oledText("FIRE", 3, 2);
      oledText("DETECT", 6, 1);
    }
    else if (fireDetected) {
      oledText("FIRE", 2, 2);
      oledText("ALERT", 5, 1);
    }
    else if (smokeDetected) {
      oledText("SMOKE", 2, 1);
      oledText("ALERT", 4, 1);
    }
    else {
      oledText("SAFE", 3, 2);
    }

    previousFire = fireDetected;
    previousSmoke = smokeDetected;
  }

  delay(100);
}
