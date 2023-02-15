/*

The C++20 Masterclass: Anonymous Namespaces OR Unnamed namespaces

General Notes:

   [REF]: No
*/


namespace{
    double add(double a, double b){ // Only usable in this translation unit
        return a + b;
    }
} 