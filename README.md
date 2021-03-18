# CPP_GameOfLife


`Lucid Chart` - [CPP Game of Life](https://lucid.app/lucidchart/99aec52f-19a8-41a2-9398-1c6e92c4c090/edit?beaconFlowId=F92CA501A1A26C7B&page=0_0# "game_of_life")


## Index Image <br>
<img src = "https://github.com/err03/CPP_GameOfLife/blob/test-file/array_8_8.PNG" alt="8*8" title="8*8">

## Require Functions
            Graph Function - functions about update or draw graph
 - [x] `drawGraph()` - cout the graph, to watch every happen
 <br>

            About Cell Function - functions that about cells
 - [x] `generateCell()` - generate 25 cells, with random index[ROL][COL]
 - [ ] `birthCell()` - if near cells are excatly 3, then birth a cell
 - [ ] `killCell()` - if near cells are single, or more than 3, then kill the cell
 - [ ] `updateCell()` - update the current cell's status then drawGraph()
<br>


            determine Functions -  functions that determine true or false
 - [x] `determineOutOfRange()` - determine if out of range, because only 8*8 arrays
 - [ ] `determineNearCell()` - determine the number of near cell, then do killCell() or birthCell()
<br>
