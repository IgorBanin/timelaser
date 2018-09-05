# Time Laser Display

Displays the time in 24hr format on a glow in the dark sticker sheet using an ultraviolet laser. Utilizes x and y servo motors to draw out individual numbers, a tiny RTC to tell the time, and an Arduino UNO for processing. The following videos display how the laser display works in light and dark environments.

<a href="http://www.youtube.com/watch?feature=player_embedded&v=BrsYRhGEyC4
" target="_blank"><img src="http://img.youtube.com/vi/BrsYRhGEyC4/0.jpg" 
alt="Dark Laser Demo" width="240" height="180" border="10" /></a>

<a href="http://www.youtube.com/watch?feature=player_embedded&v=GYEmO1oykZE
" target="_blank"><img src="http://img.youtube.com/vi/GYEmO1oykZE/0.jpg" 
alt="Light Laser Demo" width="240" height="180" border="10" /></a>

## Getting Started

This project is programmed on an Arduino UNO, using the [Arduino IDE](https://www.arduino.cc/en/Main/Software "Arduino IDE Download"). The Arduino IDE is based on C/C++.

### Materials Used:

###### Links provided are for convenience/where I got some of my pieces. They do not necessarily reflect the best prices/best places to get parts. 

 - [Arduino UNO](https://www.amazon.com/ARDUINO-A000073-DEV-BRD-ATMEGA328/dp/B007R9TUJE/ref=sr_1_5?ie=UTF8&qid=1535558536&sr=8-5&keywords=arduino+uno)(Other UNO boards will most likely work)
 - [Breadboard Jumper Wires](https://www.amazon.com/120pcs-Multicolored-Breadboard-Arduino-Raspberry/dp/B072L1XMJR/ref=sr_1_4?ie=UTF8&qid=1535558804&sr=8-4&keywords=male+female+leads)
 - [Solderless Breadboard](https://us.banggood.com/Wholesale-Warehouse-8_5-x-5_5cm-400-Tie-Points-400-Holes-Solderless-Breadboard-Bread-Board-wp-Usa-91872.html?rmmds=search)
 - [x2 sg90 Micro Servo Motors](https://www.amazon.com/ElectroBot-Micro-Helicopter-Airplane-Controls/dp/B071KJV7DD/ref=sr_1_5?ie=UTF8&qid=1535559351&sr=8-5&keywords=micro+servo+motors)
 - [Mini Pan-Tilt Servo Mount](https://www.amazon.com/Adafruit-Mini-Pan-Tilt-Kit-Assembled/dp/B00PY3LQ2Y/ref=sr_1_fkmr1_1?ie=UTF8&qid=1535559136&sr=8-1-fkmr1&keywords=pan+tilt+servo+motor+mount+adafruit)
 - x1 220 Ohm Resistor
 - [x1 NPN transistor](https://www.amazon.com/gp/product/B06XPWS52G/ref=oh_aui_search_detailpage?ie=UTF8&psc=1)
 - 405nm UV laser pointer
 - [Tiny RTC I2C](https://www.amazon.com/gp/product/B00UUR8GJU/ref=oh_aui_search_detailpage?ie=UTF8&psc=1)
 - [12x12in plexiglass](https://www.amazon.com/gp/product/B004DYW31I/ref=oh_aui_search_detailpage?ie=UTF8&psc=1)
 - [x1 Glow in the Dark Sticker Sheet](https://www.amazon.com/gp/product/B00YU7R3H2/ref=oh_aui_search_detailpage?ie=UTF8&psc=1)
 - 12x18in wooden board
 - USB Data Sync Cable for Arduino UNO

## Assembly Instructions

### Laser Assembly

There are two types of UV lasers out there: ones with wires and ones without. I recommend getting the ones with wires because that simplifies the assembly process.

![alt text](http://static1.squarespace.com/static/58ea60f83e00be49e5d70084/58ea7704893fc0148fc119a0/5ac7eb9303ce640b6bf573a6/1528236082818/?format=1000w "UV Laser Pointer")

![alt text](https://images-na.ssl-images-amazon.com/images/I/31xnQYPuQpL.jpg "UV Laser with wires")

I'll be covering the assembly for the regular laser pointer without wires, because that is what I used for my project. The idea behind this assembly is that you want to turn the UV laser from the first image into something like the second image. Firstly, unscrew the laser so you only have the head of the laser. Grab two wires and strip a little bit off both ends; to create attachment pins on either side(you can make any jumper wires work). Take one wire and carefully solder it onto the spring of the laser, this will act as the positive terminal. Using some heat shrink and a heat gun, insulate the wire attached to the spring. Take the second wire and press it down onto the laser pointer button, and secure it with electric tape(make sure the button is pressed down), this will be ground.

![Laser](Pictures/40293604_1026385217540250_1169050661581488128_n.jpg)

### Pan and Tilt Servo Mount Assembly

Now that the proper modifications to the laser have been made, it is time to attach the laser to the pan and tilt servo mount. Cut out two pieces(rectangular boxes) of block foam that fit snugly into the top of the servo mount. Carve out a little bit of foam in the center of these two pieces(aiming for a half cylinder shape), this will be where the laser will go. Place the laser in between both pieces of foam, and secure the foam laser sandwich by tightly wrapping tape at the front and back. Once this is done, go ahead and place the foam laser sandwich, into the tight space on top of the servo mount.

### Screen Assembly 

Secure the bottom portion of plexiglass using a vice; heat it up  using a heat gun, and start to slowly bend it backwards. Once the plexiglass is bent at more than a 90 degree angle, or has achieved its desired shape, let it cool. To finish, place a glow in the dark sticker sheet on the front of the plexiglass(the side facing the laser).

### Board Assembly

Apply acrylic and wood binding glue on one side of the wooden board; place bent portion of the screen to the glue, press down and wait to dry. Place the pan and tilt servo mount with laser attached **XYZ** cm away for the screen, and secure with screws. (Optional) Use some velcro patches to create secure locations for the Arduino UNO, and breadboard behind the laser.

### Wiring


### Useful links with regard to wiring

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc
