output: customer.o cashier.o cashierList.o queue.o main.o simulation.o
	g++ customer.cpp cashier.cpp cashierList.cpp queue.cpp main.cpp simulation.cpp -o output

main.o: main.cpp
	g++ -c main.cpp

customer.o: customer.cpp customer.h
	g++ -c customer.cpp

cashier.o: cashier.cpp cashier.h
	g++ -c cashier.cpp

cashierList.o: cashierList.cpp cashierList.h
	g++ -c cashierList.cpp

queue.o: queue.cpp queue.h
	g++ -c queue.cpp

simulation.o: simulation.cpp simulation.h
	g++ -c simulation.cpp

clean:
	rm *.o output Result.txt
