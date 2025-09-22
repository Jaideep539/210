import tkinter as tk
from gpiozero import LED
from time import sleep

# Setup LEDs with GPIO pins
red1 = LED(17)
red2 = LED(27)
green = LED(22)

# Make sure all LEDs are OFF at startup
red1.off()
red2.off()
green.off()
sleep(0.1)  # tiny delay to let pins settle

def turn_on(led_name):
    # Turn all off first
    red1.off()
    red2.off()
    green.off()

    # Turn selected one on
    if led_name == "red1":
        red1.on()
    elif led_name == "red2":
        red2.on()
    elif led_name == "green":
        green.on()

# GUI Setup
root = tk.Tk()
root.title("LED Controller")

choice = tk.StringVar(value="")  # no default selection

tk.Label(root, text="Select LED:").pack(pady=5)

# Buttons now match what turn_on expects
tk.Radiobutton(root, text="Red 1", variable=choice, value="red1", command=lambda: turn_on("red1")).pack()
tk.Radiobutton(root, text="Red 2", variable=choice, value="red2", command=lambda: turn_on("red2")).pack()
tk.Radiobutton(root, text="Green", variable=choice, value="green", command=lambda: turn_on("green")).pack()

tk.Button(root, text="Exit", command=root.quit).pack(pady=10)

root.mainloop()