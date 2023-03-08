all:
	g++ -std=c++11 main.cpp -o a.out

clean: 
	rm -rf *.o
	rm -f *.out
	rm -f *~*.hgch *#
	rm -f *~ *.h.gch *#
	rm -f *.ppm

val:
	valgrind ./a.out

run:
	./a.out

run-test:
	./mytest.out