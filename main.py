"""
Using what we know how can we implement the FLoodfill algorithm? Using Models?
For starters what language would you write solution? C? Python? 
The question we ran into was creating an environment one | then creating an agent
interacting with the environment |
Its difficult to conceptualize this | its almost a whole video game
You have to create environment/level | THen have a character interact with it
Its definitely object oriented | You should use some sort of library or engine to do it

A number array won't really cut it and/or the agent is what really matters

Okay so i have the environment good | The agent itself should still have a map or meental 
creation of the map as well

So the real starting point should be creating the mental map for the agent!! 
The map can be an array and it has to have a pos | Movement is limited to pos | 
The input to the brain is any combo of walls. The brain update is non-trivial 
we create set of cuntions to handle each change
The brain will be some sort of heatmap
When we reach a spot we interact w/ one of four walls
Each interaction w/ wall changes weight on map 

We reach center from beginning by guessing | Then we solve shortest path
We need to remember at each cell which path is go and no go
Well create a BINARY TREE!!!!
The tree will start from where we are then we fill in 
Once we reach dead end we pop back up to node with a chance
Branch that reaches end will get saved ( the path )
Use recursion?? | For each cell theres one of four options | We take one
Can we keep going? Yes keep going? Can we keep going? No try next direction (turn right)
Shortest Path: When we reach a no then we have to update adjacent cells |
Technically shortest path with no walls is a straight line 


------------Breakdown---------

Brain | Map of empty maze | Do we know center or not?? | matrix or other structure 

Traversal Strategy | go forward or turn right | Smart traversal

Map Refresh Strategy | Update as we hit walls


-----------------------

Recursion Wins | We have four options per cell | up , right , down , left
we start with up | if no up go right | no right go down| no down go left
if last direction was up no down | prevent inversion 
likewise with right and left
We keep deadend counter of how many times we went in same direction 
We keep track by saving last_direction and passing count down each recursion
if deadend is reached we pop back however many times counter has 
same if we have nowhere else to go | reached end of options stack
we pop back to next optionable cell
SP: Each cell is a struct with top left right bottom walls
SP: We have a matrix of cells | Two different sides of the wall are different cells when you think about it
SP: Once we find a wall we update adjacent cell
SP: THE WALLS ARE THE SOLUTION | the path with the least number of walls is the solution | Use BST traversal

The maze itself is just a set of instructions for our agent | We feed the agent simulator data
That data is just a... that input needs to be thought about | How we feed agent matters
We're feeding it cells with our desired values 

We print semantics of mental map
Or generate maze based on instructions???
"""


"""
    Add 
"""
import csv

f = open("/home/davae/Floodfill/Test.csv", newline="") 

matrix = []
for row in csv.reader(f):
    numbers = [int(value) for value in row]
    matrix.append(numbers) 

for row in matrix:
    print(row)

#Convert matrix to maze format 
maze = []#[[] for _ in range(len(matrix))]
for r,row in enumerate(matrix):
    maze.append([])
    for c,col in enumerate(row):
        #print(col)
        n,e,s,w = col&1,col&2,col&4,col&8
        maze[r].append({"north": n, "east": e, "south": s, "west": w})

for row in maze:
    print(row)

#maze.reverse()



import tkinter as tk

CELL_SIZE = 80
WALL_WIDTH = 4

rows = len(maze)
columns = len(maze[0])

root = tk.Tk()
root.title("Maze Viewer")

canvas = tk.Canvas(
    root,
    width=columns * CELL_SIZE,
    height=rows * CELL_SIZE,
    background="white"
)
canvas.pack()


def draw_maze():
    canvas.delete("all")

    for row in range(rows):
        for column in range(columns):
            cell = maze[row][column]

            x1 = column * CELL_SIZE
            y1 = row * CELL_SIZE
            x2 = x1 + CELL_SIZE
            y2 = y1 + CELL_SIZE

            if cell["north"]:
                canvas.create_line(
                    x1, y1, x2, y1,
                    fill="black",
                    width=WALL_WIDTH
                )

            if cell["east"]:
                canvas.create_line(
                    x2, y1, x2, y2,
                    fill="black",
                    width=WALL_WIDTH
                )

            if cell["south"]:
                canvas.create_line(
                    x1, y2, x2, y2,
                    fill="black",
                    width=WALL_WIDTH
                )

            if cell["west"]:
                canvas.create_line(
                    x1, y1, x1, y2,
                    fill="black",
                    width=WALL_WIDTH
                )


draw_maze()
root.mainloop()



