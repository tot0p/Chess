# Chess


## Needed libraries

- SDL2
- SDL2_image
- SDL2_mixer
- SDL2_ttf

## How to compile

### windows

```bash
g++ -O2 src/*.cpp src/pieces/*.cpp -o bin/release/chess -IC:/SDL2/include -Iinclude -LC:/SDL2/lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -mwindows
```