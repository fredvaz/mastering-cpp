/*

The C++20 Masterclass: Anonymous Namespaces OR Unnamed namespaces

General Notes:
        Unnamed namespace definition. Its members have potential scope from their point of
        declaration to the end of the translation unit, and have internal linkage.
        
        This definition is treated as a definition of a namespace with unique name and a 
        using-directive in the current scope that nominates this unnamed namespace
        (Note: implicitly added using directive makes namespace available for the qualified name
        lookup and unqualified name lookup, but not for the argument-dependent lookup). 
        The unique name is unique over the entire program, but within a translation unit each
        unnamed namespace definition maps to the same unique name: multiple unnamed namespace 
        definitions in the same scope denote the same unnamed namespace.

   [REF]:
    https://en.cppreference.com/w/cpp/language/namespace#Unnamed_namespaces
*/
//include "namespaces_across_mutiple_files/some_other_file.cpp"

#define Test1

using namespace std;

// When the Compiler sees an anonymous namespace declaration
// it will generate an internal name for the namespace

namespace 
{
    // function declaration
    double add(double a, double b); 
}

#ifdef Test1
void test1()
{
    double result = add(10.2, 20.2);

    cout << "result : " << result << endl;

}
#endif

namespace
{
    // function implementation
    double add(double a, double b)
    {
        return a + b;
    }
}