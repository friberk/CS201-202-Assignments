CXX        := g++

SRC        := .
EXECUTABLE := hw1

all: clean $(SRC)/$(EXECUTABLE)

run: all
	clear
	$(SRC)/$(EXECUTABLE)

$(SRC)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $^ -o $@

clean:
	@-rm -f $(SRC)/$(EXECUTABLE)
