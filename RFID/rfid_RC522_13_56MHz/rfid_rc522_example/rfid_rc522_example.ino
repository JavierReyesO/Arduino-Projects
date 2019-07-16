#include "SPI.h"
#include "MFRC522.h"

#define SS_PIN 10
#define RST_PIN 9
#define SP_PIN 8

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  // Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println(rfid.PICC_GetTypeName(piccType));

  String strID = "";
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();

  // เมื่อถึงส่วนนี้ ตัวแปร strID จะเก็บค่า UID ของแท็กไว้แล้ว
  // สามารถนำไปใช้งานได้เลย เช่น นำไปเข้า IF เพื่อให้หลอด
  // LED ติดสว่าง หรือดับได้
  Serial.print("Tap card key: ");
  Serial.println(strID);



  if(strID == "E5:72:63:76"){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    Serial.println("entro");
    }
    
   if(strID == "79:17:17:CB"){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    Serial.println("entro");
    }
  
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
