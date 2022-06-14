CXX        := g++

SRC        := .
EXECUTABLE := hw4

all: clean $(SRC)/$(EXECUTABLE)

run: all
	clear
	@-$(SRC)/$(EXECUTABLE)

$(SRC)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) -w $^ -o $@

clean:
	@-rm -f $(SRC)/$(EXECUTABLE)
