/*

Design Patterns in Modern C++ Section 2: SOLID Design Principles

General Notes:

   [REF]:

*/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

        * EXAMPLE: Interface Segregation Principle
        * The idea of the interface segregation principle is basically to get you to not create interfaces
        * which are too large and which require the implementors to maybe implement too much.
        * The core of the interface aggregation principle is to avoid
        * stuffing too much into a single interface and instead, if it makes sense, if you don't want to force
        * declined to implement too much, just break up your interface into separate interfaces or just at least
        * make them smaller so that whenever a client uses one of these chunks, it's all coherent.
*/

//* Forward declaration
struct Document;

//* 1. Supose a Interface that is a Pinters able to print, scan, and fax of a Document
struct IMachine
{
    virtual void print(Document &doc) = 0; //* pure virtual function
    virtual void scan(Document &doc) = 0;
    virtual void fax(Document &doc) = 0;
};

//* 2. We want to use the Interface to implement a multifunction printer
struct MFP : IMachine
{
    void print(Document &doc) override
    {
        // ok
    }
    void scan(Document &doc) override
    {
    }
    void fax(Document &doc) override
    {
    }
};

//* 3. Now, the problem that you typically encounter is what happens if you need to implement just a printer
//* or just a scanner because you only have this AI machine interface to work with.
struct Scanner : IMachine
{
    void print(Document &doc) override
    {
        //! We could levae this methods null, make a try catch if the user try to used, or just not leave with nothing
    }
    void scan(Document &doc) override
    {
        // ok
    }
    void fax(Document &doc) override
    {
    }
};

//* 4. The approach is Segregate the Interface instead only in the functions that will do
struct IPrinter
{
    virtual void print(Document &doc) = 0;
};

struct IScanner
{
    virtual void scan(Document &doc) = 0;
};

struct IFax
{
    virtual void fax(Document &doc) = 0;
};

//* 5. Now, if you we want to implement a Printer with a specific function we only have to call the specific Interface
struct Printer : IPrinter
{
    void print(Document &doc) override
    {
        // ok
    }
};

//* 8. Also we implement a Scanner
struct Scanner : IScanner
{
    void scan(Document &doc) override
    {
        // ok
    }
};

//* 6. A more completed machine with mutiple functions we do:
struct IMachine1 : IPrinter, IScanner
{
    //* We can leave it null
};

//* 7. And the user could then implement the functions required
struct Machine1 : IMachine1
{
    IPrinter &printer;
    IScanner &scanner;

    Machine1(IPrinter &printer, IScanner &scanner) : printer(printer), scanner(scanner) {}

    void print(Document &doc) override
    {
        printer.print(doc);
    }
    void scan(Document &doc) override
    {
        scanner.scan(doc);
    }
};

//

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
