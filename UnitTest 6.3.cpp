#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 6.3./Project 6.3.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63
{
	TEST_CLASS(UnitTest63)
	{
	public:
		
		
		TEST_METHOD(TestMethod_Min_Int)
			{
				// Тест для звичайної функції Min
				const int size = 5;
				int arr[size] = { 3, -10, 5, 0, 8 };

				int expected = -10;
				int actual = Min(arr, size);

				Assert::AreEqual(expected, actual);
			}

			TEST_METHOD(TestMethod_MinTemplate_Double)
			{
				// Тест для шаблону функції MinTemplate
				const int size = 5;
				double arr[size] = { 2.5, -4.2, 0.0, 10.1, -1.8 };

				double expected = -4.2;
				double actual = MinTemplate(arr, size);

				Assert::AreEqual(expected, actual, 0.0001);
			}
		
	};
}
