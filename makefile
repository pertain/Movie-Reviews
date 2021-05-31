
CC = g++
FLAG = -c -Wall
SRC = Movie.cpp MovieList.cpp MovieReviews.cpp
OBJ = $(SRC:.cpp=.o)
BIN = movieReviews


.PHONY: depend clean

all: $(SRC) $(BIN)
    
$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@

.cpp.o:
	$(CC) $(FLAG) $< -o $@
