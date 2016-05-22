String commandString;

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, hallSensorInterrupted, RISING);
}

void loop() {
}

void hallSensorInterrupted()
{
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
}

// Method checks new commands on serial port
void serialEvent()
{
  char c = Serial.read();
  if (c == ';')
  {
    Serial.println("Done comand - " + commandString);
    commandString = "";
  }
  else
  {
    commandString += c;
  }
}
