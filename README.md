# Lem-in

The project consists in running a certain amount of 'ants' in the fastest way possible in an 'anthill'. Graph data structure is used to build the map. My implementation uses Breadth-first search (BFS) algorithm.

## Getting Started


### Installing

After cloning the repository, run

```
make
```

to compile. An executable named ./lem-in should be created.

## How to use

lem-in takes commands on stdin. Tests and sample maps can be found in the [tests](tests/) folder.

```
Usage: ./lem-in  < test_map

```

### Map format (input)

A map is made of ***rooms*** and ***tubes***. ***Rooms*** are linked by ***tubes***. All distances are equal to 1.

The first line of a map must be the number of ants that will run through the map.

```
42
```

Any other line must be either a ***room descriptor***, a ***tube descriptor***, a ***command***, or a ***comment***.

#### Room

A ***room descriptor*** is a line with 3 fields separated by a space **' '**. The first field is the **room name**. Any name is legal, as long as it contains no space and doesn't start with **'L'**. The two other fields represents the coordinates of this room in a 2D environment. Those coordinates are completely ignored by the lem-in executable, but will be printed back on the output for more processing.

```
room_name x y
```

#### Tube

A ***tube descriptor*** is a line with 2 fields separated by a dash **'-'**. Each field must be the name of a valid room.

```
room_1-room_2
```

#### Command

Any line that starts with two **'#'** is a  ***command***. lem-in only interprets two commands: **'##start'** and **'##end'**. A map without one of those commands will result in an error. They must be located before a valid ***room descriptor***. Any other command will be ignored and printed back on the output for more processing.

```
##start
room_1 0 0
```

#### Comment

Any line that starts with one **'#'** is a  ***command***. Any comment will be ignored and printed back on the output.

```
##start
room_1 0 0
```

### Result (output)

First, the map is fully printed back.

Then, the result will contain as many lines as there is cycles. Each cycles contains *n* movements, which are formated as shown below:

```
Lant_id-room_name
```

