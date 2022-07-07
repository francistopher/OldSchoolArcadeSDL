# Pong

- i didn't know about this game until high school pretty sad

## Object file build command for Apple Silicon

```
clang -v program.c -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -o program.o
```
## To do

- draw paddles pixel by pixel
- add movement to the ball and the paddles
- have ball bounce off paddles
- reset ball when it goes out of bounds

- draw score labels for each paddle
- create system for determining winner
- draw intro text
- draw game over text

- add spin property to ball
- add acceleration property to ball and paddles
- add impulse property to ball and paddles
- add friction to ball and paddles
