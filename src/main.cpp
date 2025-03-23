#include <Arduino.h>

#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

HardwareSerial& debugSerial = Serial;
HardwareSerial& inputSerial = Serial;  // GPIOで指定する別ポート

void onInputReceived() {
  while (inputSerial.available()) {
    char c = inputSerial.read();
    debugSerial.print("[Input] ");
    debugSerial.println(c);
  }
}

void setup() {
  debugSerial.begin(115200);
  // inputSerial.begin(115200); // ここで設定すると、setPins()で設定した値が上書きされる

  debugSerial.println("System Starting...");

  inputSerial.setRxFIFOFull(1);
  inputSerial.setRxTimeout(3);
  inputSerial.onReceive(onInputReceived, true);
}

void loop() {
  //bleKeyboard.poll();
}

