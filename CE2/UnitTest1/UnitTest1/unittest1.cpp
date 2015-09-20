#include "stdafx.h"
#include "CppUnitTest.h"
#include "CommandProcessor.h"
#include "ReaderWriter.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

const int ARRAY_SIZE = 5;

namespace UnitTest1
{
	TEST_CLASS(TextBuddyTest)
	{
	public:
		TEST_METHOD(sortTest)
		{
			string inputs[ARRAY_SIZE] = { "table", "apple", "friends", "dog", "car" };
			string sortedInputs[ARRAY_SIZE] = { "apple", "car", "dog", "friends", "table" };

			vector<string> hardcodedInput;

			for (int i = 0; i < ARRAY_SIZE; i++) {
				hardcodedInput.push_back(inputs[i]);
			}
			
			CommandProcessor cmdProcessor;
			cmdProcessor.setTextInputs(hardcodedInput);
			cmdProcessor.sortText();
			
			vector<string> processedTexts;
			cmdProcessor.getTextInputs();

			for (int i = 0; i < processedTexts.size(); i++) {
				Assert::AreEqual(processedTexts[i], sortedInputs[i]);
			}
		}

		TEST_METHOD(searchTest)
		{
			string word = "rains";

			string inputs[ARRAY_SIZE] = { "today", "rains", "sunny", "hi", "bye" };
			string expectedOutput[1] = { "rains" };
			vector<string> hardcodedInput;
			
			for (int i = 0; i < ARRAY_SIZE; i++) {
				hardcodedInput.push_back(inputs[i]);
			}

			vector<string> actualOutput;

			CommandProcessor cmdProcessor;
			cmdProcessor.setTextInputs(hardcodedInput);
			actualOutput.swap(cmdProcessor.searchText(word));

			for (int i = 0; i < actualOutput.size(); i++) {
				Assert::AreEqual(expectedOutput[i], actualOutput[i]);
			}

		}

	};
}