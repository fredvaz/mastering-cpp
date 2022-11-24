/*

The C++20 Masterclass:

General Notes:


   [REF]:

   
*/

#include <iostream>
#include <ctime>

#define Test1

using namespace std;

#ifdef Test1
void test1()
{
    /*
    Notes:
    */
    // srand() has to run once per program run
    srand(time(0)); // Seed

    char prediction0[]{"a lot of kinds running in the backyard!"};
    char prediction1[]{"a lot of empty beer bootles on your work table."};
    char prediction2[]{"you Partying too much with kids wearing weird clothes."};
    char prediction3[]{"you running away from something really scary"};
    char prediction4[]{"clouds gathering in the sky and an army standing ready for war"};
    char prediction5[]{"dogs running around in a deserted empty city"};
    char prediction6[]{"a lot of cars stuck in a terrible traffic jam"};
    char prediction7[]{"you sitting in the dark typing lots of lines of code on your dirty computer"};
    char prediction8[]{"you yelling at your boss. And oh no! You get fired!"};
    char prediction9[]{"you laughing your lungs out. I've never seen this before."};

    bool end{false};

    const int max_length{15};
    char name[max_length]{};

    cout << "What's your name dear :" << endl;

    cin.getline(name, max_length); // Get input with spaces

    while (!end)
    {
        cout << "Oh dear " << name << ", I see ";

        size_t rand_num = static_cast<size_t>((rand() % 11));

        switch (rand_num)
        { // [0~10]
        case 0:
            cout << prediction0 << endl;
            break;
        case 1:
            cout << prediction1 << endl;
            break;

        case 2:
            cout << prediction2 << endl;
            break;
        case 3:
            cout << prediction3 << endl;
            break;
        case 4:
            cout << prediction4 << endl;
            break;
        case 5:
            cout << prediction5 << endl;
            break;
        case 6:
            cout << prediction6 << endl;
            break;
        case 7:
            cout << prediction7 << endl;
            break;

        case 8:
            cout << prediction8 << endl;
            break;

        case 9:
            cout << prediction9 << endl;
            break;
        default:
            cout << ", huum, I don't see anything" << endl;
        }
        cout << "Do you want me to try again ? (Y | N) : ";

        char go_on;
        cin >> go_on;

        end = ((go_on == 'Y') || (go_on == 'y')) ? false : true;
    }

    cout << "That's all I have for you today dear. Best wishes" << endl;
}
#endif

#ifdef Test2
void test2()
{
    /*
    Notes:
    */
}
#endif