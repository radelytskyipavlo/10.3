#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <sstream>
#include "../Project1/Source.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(FriendManagementTests)
    {
    public:

        TEST_METHOD(CreateFriendListTest)
        {
            const string filename = "testfile.txt";
            const int numFriends = 2;
            stringstream input("John Doe\n1234567890\n1 1 1990\nJane Smith\n0987654321\n2 2 2000\n");
            streambuf* oldcin = cin.rdbuf(input.rdbuf());

            createFriendList(filename);
            cin.rdbuf(oldcin);
            ifstream file(filename);
            Assert::IsTrue(file.is_open());

            Friend friends[numFriends];
            for (int i = 0; i < numFriends; ++i) {
                file >> friends[i].firstName >> friends[i].lastName >> friends[i].phoneNumber
                    >> friends[i].birthday[0] >> friends[i].birthday[1] >> friends[i].birthday[2];
            }

            file.close();

            Assert::AreEqual(string("John"), friends[0].firstName);
            Assert::AreEqual(string("Doe"), friends[0].lastName);
            Assert::AreEqual(string("1234567890"), friends[0].phoneNumber);
            Assert::AreEqual(1, friends[0].birthday[0]);
            Assert::AreEqual(1, friends[0].birthday[1]);
            Assert::AreEqual(1990, friends[0].birthday[2]);

           
            remove(filename.c_str());      
        }
    };
}