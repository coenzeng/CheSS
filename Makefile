CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -L/opt/X11/lib -I/opt/X11/include
EXEC = chess
OBJECTS = main.o game.o board.o View/chessStudio.o View/textObserver.o View/graphicalObserver.o View/subject.o View/observer.o View/window.o Pieces/piece.o Pieces/bishop.o Pieces/blankPiece.o Pieces/king.o Pieces/knight.o Pieces/pawn.o Pieces/queen.o Pieces/rook.o Player/player.o Player/human.o Player/computer1.o Player/computer2.o Player/computer3.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS} 
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11 
-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
