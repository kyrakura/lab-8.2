#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 8.2/lab 8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
        TEST_METHOD(TestFind)
        {
            // Arrange
            std::string input1 = "This is a (sample (text) with nested) parentheses.";
            size_t startPos1 = 10;

            std::string input2 = "Another (example) with (nested (parentheses)).";
            size_t startPos2 = 8;

            // Act
            size_t result1 = find(input1, startPos1);
            size_t result2 = find(input2, startPos2);

            // Assert
            Assert::AreEqual(size_t(36), result1);
            Assert::AreEqual(size_t(16), result2);
        }
	};
}
