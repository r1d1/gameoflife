VERSION=alpha
#PATHTOSFML=/usr/local/SFML-2.2
EXECNAME=GameOfLife 
#all : ${EXECNAME} 

#export LD_LIBRARY_PATH=${PATHTOSFML}/lib:$LD_LIBRARY_PATH

GameOfLife : main.o Universe.o
	g++ *.o -o GameOfLife_${VERSION} -lsfml-system -lsfml-graphics -lsfml-network -lsfml-audio -lsfml-window 

*.o : *.cpp
	g++ -c *.cpp 

clean :
	rm -f *.o
	rm -f ${EXECNAME}_${VERSION}
