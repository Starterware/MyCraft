# Bowling

This kata consist of computing the score of a bowling game of one player.
A bowling game consists of 10 frames during which a player will have to try to knock down 10 pins.
During each frame, the player will have 2 tries to knock as much pins as possible. 
Afterwards, all the 10 pins are reset.

The scoring goes as follows:
* When less than 10 pins are knocked down, the frame value will be equal to the number of pins that are knocked down
* When all 10 pins are knocked on the first roll (called stricke) the frame value is equal to 10 pins plus the value of the next two rolls
* When all 10 pins are knocked on the second roll (called spare), the frame value is equal to 10 pins plus the value of the next roll
* In case of a spare or stricke in the last frame, three rolls will be done in the frame. When there are no pins left, they are reset if a roll still needs to be done
* The final score is equal to the addition of all the frame scores

I made the kata a bit more complicated by adding the validation part and by computing the score from a string that represents the game.

The string format:
* The frames are separated by a whitespace
* The character \ represents a spare
* The character X represents a strick
* The character - represents a gutter roll, ie. 0
* All other values are represented by the corresponding digit

Example: 34 2\ 45 X X 71 -5 3- 81 X25

The validation is much more complicated than expected due to a lot of corner cases. 
The fact that there are different symbols is adding even more validation errors.
For instance, a frame 28 cannot exists because it should be 2\.
