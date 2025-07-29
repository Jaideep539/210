int led = LED_BUILTIN;  // Use built-in LED (usually D13 on Nano 33 IoT)

void setup() {
  pinMode(led, OUTPUT);  // Set LED pin as output
}

void loop() {
  blinkLetterJ(); delay(800);
  blinkLetterA(); delay(800);
  blinkLetterI(); delay(1500); // Pause before repeating
}

// Morse Unit Functions
void blinkDot() {
  digitalWrite(led, HIGH);
  delay(200);                // dot: short blink
  digitalWrite(led, LOW);
  delay(200);                // pause between dots/dashes
}

void blinkDash() {
  digitalWrite(led, HIGH);
  delay(600);                // dash: long blink
  digitalWrite(led, LOW);
  delay(200);
}

// Letters in Morse Code
void blinkLetterJ() { blinkDot(); blinkDash(); blinkDash(); blinkDash(); } // J = .---
void blinkLetterA() { blinkDot(); blinkDash(); }                           // A = .-
void blinkLetterI() { blinkDot(); blinkDot(); }                            // I = ..