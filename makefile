make: hash test test_hashtable

hash: main.o
	g++ main.o -o hash

test: test_hashtable_example.o 
	g++ test_hashtable_example.o -o test_hashtable_example

test_hashtable: test_hashtable.o
	g++ test_hashtable.o -o test_hashtable

main.o: main.cpp usecase.cpp hash_table.cpp hash_table.h
	g++ -c main.cpp

test_hashtable_example.o: test_hashtable_example.cpp usecase.cpp hash_table.cpp hash_table.h
	g++ -c test_hashtable_example.cpp

test_hashtable.o: test_hashtable.cpp usecase.cpp hash_table.cpp hash_table.h
	g++ -c test_hashtable.cpp

clean:
	rm -f *.o hash test_hashtable_example test_hashtable
