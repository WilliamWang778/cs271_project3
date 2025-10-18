#include <iostream>
#include "usecase.cpp"


using namespace std;


void test_get_key()
{
  cout << "Testing Element get_key()" << endl;

  try
    {   
        // Default Constructor
        Element<int> element_empty;
        if (element_empty.get_key() != -1)
        {
            cout << "Incorrect result from get key. Expected -1 for an empty element but got : " << element_empty.get_key() << endl;
        }

        // Positive Key
        Element<int> element_positive(10, 6);
        if (element_positive.get_key() != 6)
        {
            cout << "Incorrect result from get key. Expected 6 but got : " << element_positive.get_key() << endl;
        }
        
        // Negative key
        Element<string> element_negative("data1", -95);
        if (element_negative.get_key() != -95) {
            cout << "Incorrect result from get key. Expected -95 but got: " << element_negative.get_key() << endl;
        }

        // zero key
        Element<string> e_zero("data2", 0);
        if (e_zero.get_key() != 0) {
            cout << "Incorrect result from get key. Expected 0 but got: " << e_zero.get_key() << endl;
        }
        
        cout << "PASSED" << endl;

    }

    catch (exception &e)
    {
        cerr << "Error getting key from element : " << e.what() << endl;
    }
}




void test_get_data()
{
    cout << "Testing Element get_data()" << endl;
    
    try
    {
        // Default Constructor - int
        Element<int> element_empty_int;
        if (element_empty_int.get_data() != 0)
        {
            cout << "Incorrect result from get data. Expected 0 for an empty element but got: " << element_empty_int.get_data() << endl;
        }
        
        // Positive data - int
        Element<int> element_int(10, 6);
        if (element_int.get_data() != 10)
        {
            cout << "Incorrect result from get data. Expected 10 but got: " << element_int.get_data() << endl;
        }
        
        // String data
        Element<string> element_string("LukasWilliamFlynn", 69);
        if (element_string.get_data() != "LukasWilliamFlynn")
        {
            cout << "Incorrect result from get data. Expected 'LukasWilliamFlynn' but got: " << element_string.get_data() << endl;
        }
        
        // Empty string data
        Element<string> element_empty_string("", 74);
        if (element_empty_string.get_data() != "")
        {
            cout << "Incorrect result from get data. Expected empty string but got: " << element_empty_string.get_data() << endl;
        }
        
        // Double data
        Element<double> element_double(3.14159, 18);
        if (element_double.get_data() != 3.14159)
        {
            cout << "Incorrect result from get data. Expected 3.14159 but got: " << element_double.get_data() << endl;
        }
        
        // Negative data - int
        Element<int> element_negative(-999, 3);
        if (element_negative.get_data() != -999)
        {
            cout << "Incorrect result from get data. Expected -999 but got: " << element_negative.get_data() << endl;
        }
        
        cout << "PASSED" << endl;
    }
    catch (exception &e)
    {
        cerr << "Error getting data from element: " << e.what() << endl;
    }
}



void test_insert()
{
   



}





void test_remove()
{


    
   
}






void test_member()
{
    






}







void test_login()
{
    






}





int main()
{
    string file_name = "usecase.cpp";
    cout << endl
         << "Running tests for " << file_name << endl
         << endl;

    test_get_key();
    test_get_data();
    test_insert();
    test_remove();
    test_member();
    test_login();

    cout << "Testing completed" << endl;

    return 0;
}