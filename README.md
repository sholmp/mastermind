# Mastermind

## Build instructions
```bash
mkdir build && cd build
cmake ..
make
```
## Program structure
 The game runs as a simple state machine with four states, as seen in the following diagram
 
You can create your own player by subclassing MastermindPlayer and implement the two functions ```makeGuess()``` and ```makeCode()```. I have provided three examples
- HumanPlayer
- 
- FiveGuessAI
- SimpleAI

![](/home/soren/Desktop/mastermind/mmplayer.png) 