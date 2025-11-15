# Snake with Joysticks

---

## Overview

This project is a simple project showcasing Python interacting with Arduino. It uses an analog joystick to gather input and translates it into a form in which Python can parse it and press the appropriate keys to play the game Snake on an Arduino. This project is designed for Snake, but it can be played with any game in which there are arrow keys/WASD and optionally, a click or space button! 

## Getting Started

To get started, follow these steps:


1. Clone the repository with `git clone https://github.com/Naksh-Rathore/snake_joystick.git` (add `--depth 1` or remove `.git` if you want to)
2. Recreate the schematic from `schematic.md`
3. Move the `.ino` code into Arduino IDE
4. Upload it into your Arduino
5. Run your Python code (might take some tries to stop getting errors)
6. Play, test, and modify!

---

### Common Issues

Issue: Python code is throwing errors
Answer: Just rerun it and restart Arduino serial port until it works

Issue: The joystick is too laggy
Answer: Fix it by shortening the delay in `code/main.ino` in `void loop()` on this line: `if (joyStickXVal != 512 || joyStickYVal != 512) delay(100);`

Issue: The keypresses aren't happening
Answer: The joystick wires can get loose sometimes, first check the connectivity

## Compatible Games

This project can work with:

* Snake
* Subway Surfers
* Candy Jump
* Pacman
* Geometry Dash (click/space mostly, pushbutton works better though)

And more!

## Under the hood

How does this project work under the hood? Well, this project contains two parts, the Arduino code and the Python script. The Arduino code gets the voltage from the potentiometers of the joystick, formats them, and prints them out to serial. Then, the Python script reads that log from the serial port since both Python and Arduino can use it (although Python does require a third party library, `pyserial`), parses and maps it to a key, and uses the `keyboard` library to do a virtual key press, effectively pressing for us.

We can natively do it with other MCUs, but this fairs well to most MCUs since they usually all support serial logging but not all MCUs support keyboard presses.

## Contributing

Feel free to make an issue, pull request, or contact me at any of my socials to ask me if you want! My issues, pull requests, and DMs are always open. That being said, I would like if the issues and PRs you send are **relevant**, **concise**, and are actually **helpful** in general. Spammy and unrelated issues and PRs will either be closed or given the `info-needed` tag. Thanks!

### License

This project is licensed under the MIT License. More info in the `LICENSE` file.
