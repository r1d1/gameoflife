VERSION=alpha
#PATHTOSFML=/usr/local/SFML-2.2
EXECNAME=GameOfLife 
#all : ${EXECNAME} 

#export LD_LIBRARY_PATH=${PATHTOSFML}/lib:$LD_LIBRARY_PATH

GameOfLife : main.o Universe.o
	g++ *.o -o GameOfLife_${VERSION} -lsfml-system -lsfml-graphics -lsfml-network -lsfml-audio -lsfml-window 
	#g++ *.o -o SimpleRumble_${VERSION} -L${PATHTOSFML}/lib -lsfml-system -lsfml-graphics -lsfml-network -lsfml-audio -lsfml-window 

#main.o : main.cpp
#	g++ -c main.cpp -I${PATHTOSFML}/include 

*.o : *.cpp
	g++ -c *.cpp 
	#g++ -c *.cpp -I${PATHTOSFML}/include 

clean :
	rm -f *.o
	rm -f ${EXECNAME}_${VERSION}
