import RPi.GPIO as GPIO
import time

# Use BCM numbering
GPIO.setmode(GPIO.BCM)

led = 11  # GPIO 11 (BCM)
GPIO.setup(led, GPIO.OUT)

print("LED will blink 5 times")

# Make sure LED is off at start
GPIO.output(led, False)

try:
    for i in range(5):
        GPIO.output(led, True)   # Turn LED on
        time.sleep(1)
        GPIO.output(led, False)  # Turn LED off
        time.sleep(1)
finally:
    GPIO.cleanup()  # Reset GPIO pins