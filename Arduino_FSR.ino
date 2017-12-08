// This is the code for the arduino that controls all force sensitive resistors(FSRs)

int fsr1 = 0;                       // Initialise the pins for FSRs
int fsr2 = 1;
int fsr3 = 2;
int fsr4 = 3;
int fsr5 = 4;
int fsrR1;                          // Initialise variable for storing FSR values
int fsrR2;
int fsrR3;
int fsrR4;
int fsrR5;
 
void setup() {                      // Initialise serial connection for the RPI
    Serial.begin(9600);
}
 
void loop(void) {                   // Main loop
    fsrR1 = analogRead(fsr1);       // Read values from all five FSRs
    fsrR2 = analogRead(fsr2);
    fsrR3 = analogRead(fsr3);
    fsrR4 = analogRead(fsr4);
    fsrR5 = analogRead(fsr5);
    
    if (fsrR1 > 3) {                // When the FSR value is greater than 3, Arduino sends '1' to RPI
    Serial.write(1);
    }
    else if (fsrR2 > 3) {           // Each FSR has its own identity number (1-5) so RPI knows which FSR is triggered
    Serial.write(2);
    }
    else if (fsrR3 > 3) {
    Serial.write(3);
    }
    else if (fsrR4 > 3) {
    Serial.write(4);
    }
    else if (fsrR5 > 3) {
    Serial.write(5);
    }
    else {
    Serial.write(0);                // If none of the FSRs are triggered, send '0' to RPI
    }
}                                   // Looped without any delays to avoid lag
