all: test usecase

usecase: main.o
	g++ main.o -o usecase

test: test_hashtable.o
	g++ test_hashtable.o -o test

main.o: main.cpp usecase.cpp hash_table.cpp hash_table.h
	g++ -c main.cpp

test_hashtable.o: test_hashtable.cpp usecase.cpp hash_table.cpp hash_table.h
	g++ -c test_hashtable.cpp

# Just keep example test executable
test_hashtable_example: test_hashtable_example.o
	g++ test_hashtable_example.o -o test_hashtable_example

test_hashtable_example.o: test_hashtable_example.cpp usecase.cpp hash_table.cpp hash_table.h
	g++ -c test_hashtable_example.cpp

clean:
	rm -f *.o test usecase test_hashtable_example