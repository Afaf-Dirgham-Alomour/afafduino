#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int buttonPin = 2; // Button connected to digital pin 2
int buttonState = HIGH;   // Variable to store the button state (using INPUT_PULLUP)
int lastButtonState = HIGH; // Previous button state
int count = 0;            // Counter for tasbeeh

// OLED display setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Start the OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();  
  delay(2000);  // Pause for 2 seconds

  // Set up the button pin with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  // Clear the display buffer
  display.clearDisplay();
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button was pressed (transition from HIGH to LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    count++;
    display.clearDisplay();
    display.setTextSize(2);      // Set text size to 2
    display.setTextColor(SSD1306_WHITE);  // Set text color to white
    display.setCursor(0,0);      // Start at top-left corner
    display.print("Count: ");
    display.println(count);
    display.display();  // Update the display
    delay(200);         // Debounce delay
  }

  // Save the current button state as the last state for the next loop
  lastButtonState = buttonState;
}
