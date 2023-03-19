/*

Design Patterns in Modern C++ Section 2: SOLID Design Principles

General Notes:

   [REF]:

*/
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

//

#define EXAMPLE_1
#ifdef EXAMPLE_1
/*
    !Note: #define EXAMPLE_1

        * EXAMPLE: Dependency Inversion Principle
        * It's simply specifying the best way to form dependencies between different objects.
        * - the first idea is that high level modules should not depend on low level modules
        * and instead both of them should depend on abstractions.
        * - the second idea is that abstractions should not depend on the details, but rather the details should
        * depend on abstractions.
*/

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

//* Solution: moving something to a low level module and introducing an abstraction.
struct RelationshipBrowser
{
    virtual vector<Person> find_all_children_of(const string &name) = 0;
};

//* This is considered a low-level module in our design because essentially all it does is it provides
//* functionality for data storage.
// struct Relationships
// {
//     vector<tuple<Person, Relationship, Person>> relations; //! A tuple is a fixed-size collection of heterogeneous values.
//                                                            //! introduced in C++11
//                                                            //* Note that Child will be also a Person type object

//     void add_parent_and_child(const Person &parent, const Person &child)
//     {
//         relations.push_back({parent, Relationship::parent, child});
//         relations.push_back({child, Relationship::child, parent});
//     }
// };
struct Relationships : RelationshipBrowser
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person &parent, const Person &child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    //* Added from the Browser Interface
    vector<Person> find_all_children_of(const string &name) override
    {
        vector<Person> result;
        for (auto &&[first, rel, second] : relations)
        {
            if (first.name == name && rel == Relationship::parent)
            {
                result.push_back(second);
            }
        }
        return result;
    }
};

//* This is considered a high-level module in our desing
struct Research
{
    //! This is violating the depency inversion princple
    // Research(Relationships &relationships)
    // {
    //     auto &relations = relationships.relations;
    //     for (auto &&[first, rel, second] : relations)
    //     {
    //         if (first.name == "John" && rel == Relationship::parent)
    //         {
    //             cout << "Jonh has a child called " << second.name << endl;
    //         }
    //     }
    // }
    Research(RelationshipBrowser &browser)
    {
        for (auto &child : browser.find_all_children_of("John"))
        {
            cout << "John has a child called " << child.name << endl;
        }
    }
};

//

int main()
{
    std::cout << "------------------------------ EXAMPLE_1 -------------------------------------" << std::endl;

    //* 1. Supose the following case
    Person parent{"John"};
    Person child1{"Chris"}, child2{"Matt"};

    // Relationships relationships;
    // relationships.add_parent_and_child(parent, child1);
    // relationships.add_parent_and_child(parent, child2);

    // Research query(relationships);

    //! The problem: for example, the low level module decides to change the storage of relations or perhaps
    //! it just goes off and it makes the relations member variable private so it tries to hide it completely.

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research query(relationships);

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    return 0;
}

#endif // EXAMPLE_1 END

//

// struct Relationships1 : RelationshipBrowser
// {
//     vector<tuple<Person, Relationship, Person>> relations;

//     void add_parent_and_child(const Person &parent, const Person &child)
//     {
//         relations.push_back({parent, Relationship::parent, child});
//         relations.push_back({child, Relationship::child, parent});
//     }

//     vector<Person> find_all_children_of(const string &name) override
//     {
//         vector<Person> result;
//         for (auto &&[first, rel, second] : relations)
//         {
//             if (first.name == name && rel == Relationship::parent)
//             {
//                 result.push_back(second);
//             }
//         }
//     }
// };

// struct Research1
// {
//     Research1(RelationshipBrowser &browser)
//     {
//         for (auto &child : browser.find_all_children_of("John"))
//         {
//             cout << "John has a child called " << child.name << endl;
//         }
//     }
// };