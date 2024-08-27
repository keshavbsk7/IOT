#define BT_SERIAL Serial1
#define BUFFER_SIZE 100  // Define the maximum size of the buffer

char incomingData[BUFFER_SIZE];  // Array to hold incoming data
int dataIndex = 0;  // Index to keep track of the current position in the array

void setup() {
  BT_SERIAL.begin(9600);  
  Serial.begin(9600);    
}

void loop() {
  // Check if data is available from the Bluetooth module
  if (BT_SERIAL.available()) {
    while (BT_SERIAL.available()) {
      char incomingByte = BT_SERIAL.read();  // Read data from Bluetooth

      // Add the received byte to the array if there's space
      if (dataIndex < BUFFER_SIZE - 1) {
        incomingData[dataIndex++] = incomingByte;
      }

      // Check if the incoming byte is the end of the message (e.g., newline)
      if (incomingByte == '\n' || incomingByte == '\r') {
        incomingData[dataIndex] = '\0';  // Null-terminate the string
        Serial.print("Received from BT: ");
        Serial.println(incomingData);  // Print the entire message
        dataIndex = 0;  // Reset the index for the next message
      }
    }
  }

  // Check if data is available from the Serial Monitor
  if (Serial.available()) {
    char outgoingData[BUFFER_SIZE];
    int outgoingIndex = 0;

    // Read data from Serial Monitor until a newline or buffer end
    while (Serial.available() && outgoingIndex < BUFFER_SIZE - 1) {
      outgoingData[outgoingIndex++] = Serial.read();
    }

    // Null-terminate and send the data to the Bluetooth module
    outgoingData[outgoingIndex] = '\0';
    BT_SERIAL.print("Sending to BT: ");
    BT_SERIAL.println(outgoingData); 
  }
}
