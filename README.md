# Groupe de habert_j 978753
# TIC-DVC1/runner 

## **How to install the project and package necessary** ? 

### Method of procedure : 
for the first use you have to run the program using this cmd the game will autocompile and run 

```bash
./deploy.sh
```

## **How can i run this application** ? 

### Method of procedure : 
to run this application you have to make sure the project have been compiled before 
```bash
./runner 
```
## **and for the compilation** ? 

### Method of procedure : 
We use a makefile for doing this part 

we multiple arg 

clean to suppress all .o 
fclean to suppress all .o and executable 
all to target all 
re to recompile 
.PHONY for do a clean install (you can use install clean too)

for compilation the command who is recommanded to use is 
```bash
make .PHONY. 
```

## **and for play** ? 

### KEYBOAD MAPPING : 

Z = go up
Q = go left
D = go right
S = go do down 
E = Fire (only when you will have +2 point to pay)
P = to pause the game
O = to release game
