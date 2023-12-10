# How to work ia scripts

## How to create a new ia

1. Create a new file in the folder `ia` with the name of your ia

2. Add the following code in your file

```lua

function Interact(board,isWhite,movesPos)
    return -1,-1
end

```

function Interact(board,isWhite,movesPos) is the function that will be called by the game to get the move of the ia
first parameter is the board, second is a boolean that is true if the ia is white, third is a table of all the possible moves with selected piece if you doesn't select a piece it will be null

and the function must return the position of the piece to move and the position to move the piece
x and y must be between 0 and 7 and if you want to cancel the move return -1,-1