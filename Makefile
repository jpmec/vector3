all:
	rm -rf test_vector3 ; \
	g++ -Wall test_vector3.cpp -o test_vector3 ; \
	./test_vector3

clean:
	rm -rf test_vector3
