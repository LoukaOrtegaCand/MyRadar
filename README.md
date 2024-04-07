# My Radar :airplane:
## Description :world_map:
"My Radar" is an air traffic simulator in C. It visualizes aircrafts and control towers in a 2D space, simulating real-time air traffic with potential collision scenarios.

## Control Keys :keyboard:
[L]: Switch hitboxes and areas visibility
[S]: Switch entities visibility
[ESC]: Back to menu
[Q]: Quit

## Running the scripts generator :floppy_disk:
I've programmed a python script generator to simplify and pseudo-randomize the utilization of my program.
To run the script generator, execute the following command in your terminal:

```./gen```

Make sure to replace the values and script name as you need into the ```generator.py``` file.

## Running the Simulator :arrow_forward:
To run the game, execute the following command in your terminal:

```./my_radar script.rdr```

Make sure to replace 'script.rdr' with the path to your script file.

## Example Script :scroll:
A valid map can only contain 'A' and 'T' followed respectively by 6 and 3 values.
Entities are separated by a ‘\n’.
The pieces of information are separated by tabs or spaces.
#### Aircrafts are described by:
• The letter ‘A’,
• Two integers corresponding to the departure x- and y-coordinates,
• Two integers corresponding to the arrival x- and y-coordinates,
• One integer corresponding to the aircraft’s speed (in pixels per second),
• One integer corresponding to the delay (in seconds) before the aircraft takes off.
#### Control towers are described by:
• The letter ‘T’,
• Two integers corresponding to the control tower x- and y-coordinates,
• One integer corresponding to the radius of the tower’s control area (corresponding to the percentage of the greatest side of the window in pixel).
#### A valid script may look like this:
```
A 815 321 1484 166 5 0
A 1589 836 811 936 2 0
A 202 894 103 34 3 0
T 93 47 19
T 49 56 25
```

## Exiting the Game :door:
At the end of the game, when all planes crash or land, the program exits.

Have fun using My Radar !
