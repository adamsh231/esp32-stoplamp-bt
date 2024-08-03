#include <BluetoothComm.h>
#include <MDParolaCatalog.h>

BluetoothComm btComm("ESP32_BT");
MDParolaCatalog myCatalog;

void setup()
{
  Serial.begin(9600);
  btComm.begin();
  myCatalog.begin();
}

String received = "...???";
void loop()
{
  if (btComm.available())
  {
    received = btComm.receive();
    Serial.println("Received: " + received);
  }
  myCatalog.run(received);
}