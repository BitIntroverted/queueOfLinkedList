/*
 * 	Name: Lukas Friedrich
 * 	exam 2
 * 	Testing push(), pull(), isEmpty(), and peek() from Queue ADT
 */

#include "main.h"

int main()
{
    const int TESTCOUNT = 10000;
    Queue ragDoll;

    //Generate a random num from 1-4 each loop and run a correlating method from the stack class
    for (int i = 0; i < TESTCOUNT; i++)
    {
        int randMethodID = (std::rand() % 4) + 1;
        //push = 1
        if (randMethodID == 1)
        {
            bool pushed = ragDoll.push(std::rand()%2000, "testing");
            if (pushed == false)
            {
                std::cout << "Error, cannot push" << std::endl;
            }
            else {
                std::cout << "Pushed success" << std::endl;
            }
        }
        //pull = 2
        else if (randMethodID == 2)
        {
            Data temp;
            if (ragDoll.pull(temp)) {
                std::cout << "Pulled ID: " << temp.id << "Info: " << temp.information;
            }
            else {
                std::cout << "Error, cannot pull, suspect empty queue or bad data" << std::endl;
            }
            
        }
        //isEmpty = 3
        else if (randMethodID == 3)
        {
            std::cout << "Stack empty: " << ragDoll.isEmpty() << std::endl;
        }
        //peek = 4
        else if (randMethodID == 4)
        {
            Data temp;
            if (ragDoll.peek(temp)) {
                std::cout << "Peeked ID: " << temp.id << "Info: " << temp.information << endl;
            }
            else {
                std::cout << "Error, cannot peek, suspect empty queue" << std::endl;
            }

        }

    }

    return 0;
}