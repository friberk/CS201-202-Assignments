CXX        := g++

SRC        := .
EXECUTABLE := simulator

all: clean $(SRC)/$(EXECUTABLE)

run: all
	clear
	@-$(SRC)/$(EXECUTABLE)

$(SRC)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) -w $^ -o $@

clean:
	@-rm -f $(SRC)/$(EXECUTABLE)
