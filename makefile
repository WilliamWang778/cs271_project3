all: test usecase

# 'usecase' executable from main.cpp
usecase: main.o
	g++ main.o -o usecase

# 'test' executable from test_hash_table.cpp
test: test_hash_table.o
	g++ test_hash_table.o -o test

# Compile main.cpp
main.o: main.cpp usecase.cpp hash_table.cpp hash_table.h
	g++ -c main.cpp

test_hash_table.o: test_hash_table.cpp usecase.cpp hash_table.cpp hash_table.h
	g++ -c test_hash_table.cpp

# Keeping the example test
test_hashtable_example: test_hashtable_example.o
	g++ test_hashtable_example.o -o test_hashtable_example

test_hashtable_example.o: test_hashtable_example.cpp usecase.cpp hash_table.cpp hash_table.h
	g++ -c test_hashtable_example.cpp

clean:
	rm -f *.o test usecase test_hashtable_example