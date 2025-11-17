import serial
import keyboard
import time

ser = serial.Serial("COM3", 9600)

def parse_data(raw_data):
    parsed_data_arr = []
    parsed_data_buffer = ""

    for char in raw_data:
        if char == " ":
            parsed_data_arr.append(parsed_data_buffer)
            parsed_data_buffer = ""
            continue
        parsed_data_buffer += char

    if parsed_data_buffer:
        parsed_data_arr.append(parsed_data_buffer)

    return parsed_data_arr


def press_buttons(parsed_data):
    x_val = parsed_data[0]
    y_val = parsed_data[1]

    button_val = parsed_data[2]

    if int(button_val) == 1:
        keyboard.press_and_release("space")

    if int(x_val) < 200:  
        keyboard.press_and_release("right")
    elif int(x_val) > 800:  
        keyboard.press_and_release("left")

    if int(y_val) < 200:  
        keyboard.press_and_release("down")
    elif int(y_val) > 800:  
        keyboard.press_and_release("up")
         
while (True):
    # Unreadable code lol
    raw_data = ser.readline().decode("utf-8").replace("\n", "").replace("\r", "")
    parsed_data = parse_data(raw_data)

    print(parsed_data)

    press_buttons(parsed_data)

    time.sleep(0.01)

ser.close()
