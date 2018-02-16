CC 			= g++
SRC			= thread.cc
MAIN		= main.cc
CXXFLAGS	= -g3 -Wall 
OUTPUT 		= exe.out

all : $(OUTPUT)
	echo "compiling"

$(OUTPUT) :
	$(CC) $(CXXFLAGS) $(SRC) $(MAIN) -o $(OUTPUT)

clean:
	rm -f *.out
	rm -rf *.out.dSYM
	rm -f *.h.gch
	rm -f error