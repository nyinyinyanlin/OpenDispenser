# OpenDispenser

I was asked to make a set of automatic hand-sanitizer dispensers (on a short-time notice, of course) for Barcamp Yangon 2020 Event. Amid Corona/COVID-19 virus outbreak events, event organizers took public health protection in consideration and planned to hand out face masks to attending audience and place hand sanitizer dispensing stations at a number of locations.

Commercial dispensers were hard to find/buy at the moment and easier alternative would be to make it DIY. With cost efficiency and local availablity of resources/parts in consideration, we (a team of contributers) prototyped and supplied some dispensers for Barcamp Yangon 2020 event.

## Hardware

Although a simple 555-IC timer circuit would do the job, we wanted to implement (in the future events) a function that will log how many times have it been used the dispenser throughout the event. We chose a small, simple and cheap (which you can get from Aliexpress for $2) Digispark ATtiny85 USB Dev-Board (or alternative ones) as our main controller. Logging functionality will be implemented in the future through EEPROM.

Based on the viscocity of the liquid, we used a 12V/DC 120L/H submersible pump and for that a 12V AC/DC adapter is used to provide adequate power supply. This 12V supply is fed into Digispark Board's VIN pin and an onboard voltage regulater output a 5V power supply to be used with reflective sensor module and relay module.

The rest is much simple, we have used an infrared reflective sensor module to sense the hand placement and relay module to connect/cut the motor to 12V power supply. Don't forget to adjust the IR module's gain setting so that the sensor will detect the hand at a desirable distance.

An important thing we had observed is that since the pump is not geared or reciprocating one, once the pump has stopped running, the liquid inside the pipe connecting the liquid container and dispenser will flow back into the container. We have programmed the device in a way that when the sensor has detected a hand, the relay will turn on the pump for a few (hardcoded) seconds and turn off the pump after that. Then the device will be put into a pause period, for a few (hardcoded, too) seconds, so that the dispenser will not be dispensing continously. However, when the pump has stopped running, as the liquid inside flows back into the container, an air gap is formed. This causes the dispenser to be pumping liquid to fill the air gap when a hand is placed underneath the sensor, and the result is - no sanitizing liquid will not be dispensed during the set dispensing period. And the process repeats. That's why we installed a one way check valve immediately at the outlet of pump. We have used cheap plastic valves which people commonly use for aquarium installations. Kudos to [Aquar Supply](https://www.facebook.com/AquarSupply/) for contributing such valves to our activity. Such valves were hard to find in Yangon and they are the only shop in town where we can find them. When Aquar Supply knew we were working on this project, they happily contributed with their valves for free. This solved our problem.

The whole setup is enclosed in an electrical junction box. Holes are drilled to insert wires, pipes and sensor leds.

## Software

The firmware is pretty simple, two IO pins are used, one for sensor input and the other for driving the relay. The relay module works on an active_low signal and hence the output pin is pulled high when there's no output from the sensor. The dispensing and pause periods can be adjusted as wished.
