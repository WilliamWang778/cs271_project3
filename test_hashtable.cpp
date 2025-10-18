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