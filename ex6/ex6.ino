
// Define pins for Bluetooth communication
#define BT_SERIAL Serial1

void setup() {
  // Start communication with Bluetooth module
  BT_SERIAL.begin(9600);  // Initialize Bluetooth serial with baud rate of 9600
  // Start serial communication with PC
  Serial.begin(9600);    // Initialize serial communication with PC
}

void loop() {
  // Check if data is available from the Bluetooth module
  if (BT_SERIAL.available()) {
    char incomingByte = BT_SERIAL.read(); // Read data
    //Serial.write(incomingByte); // Send data to the Serial Monitor
    Serial.print("Received from BT: ");
     Serial.println(incomingByte);
  }

  // Check if data is available from the Serial Monitor
  if (Serial.available()) {
    char outgoingByte = Serial.read(); // Read data
    //BT_SERIAL.write(outgoingByte); // Send data to the Bluetooth module
    BT_SERIAL.print("Sending to BT: ");
    BT_SERIAL.println(outgoingByte); 
  }
}