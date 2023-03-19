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

        * EXAMPLE: Single Responsibility Principle (SRP)
        * A class should have a single reason to change.
        * In other words, a class should have a primary responsibility and it should not take up
        * other responsibilities.
*/

//* The Journal has to be responsible for its own title and entries and the way that you work with them
struct Journal
{
    string title;
    vector<string> entries;

    Journal(const string &tilte) : title(tilte) {}

    void add_entry(const string &entry)
    {
        static int count = 1;
        entries.push_back(lexical_cast<string>(count++) + ": " + entry);
        // boost::lexical_cast, that can convert numbers from strings
        // to numeric types like int or double and vice versa
        // an alternative to functions like std::stoi(), std::stod(), and std::to_string()
    }

    //* This method here generates a Persitance problem, if we change our Class
    //* we must change this for all objects. So the best approach is create a another Class PersitanceManager
    void save(const string &filename)
    {
        ofstream ofs(filename);
        for (auto &e : entries)
            ofs << e << endl;
    }
};

//* This is a more robust, a more reliable way of actually implementing persitance, because what happens
//* as your persitance manager grows, you have all the persistance code in a single pace
struct PersistanceManager
{
    static void save(const Journal &j, const string &filename)
    {
        ofstream ofs(filename);
        for (auto &e : j.entries)
            ofs << e << endl;
    }
};

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    Journal journal("Dear Diary");

    journal.add_entry("I ate a bug");
    journal.add_entry("I coded today");

    //! instead of calling this, and when with 100 Journal objects to save all them
    journal.save("diary.txt");
    // journal1.save("diary1.txt");
    // n ...

    //* We can call only the PersistanceManager to save all entries
    PersistanceManager pm;

    pm.save(journal, "diary.txt");

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//
