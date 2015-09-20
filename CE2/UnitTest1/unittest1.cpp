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
			string searchForWord = "rains";

			string inputs[ARRAY_SIZE] = { "it rains today", "today is sunny", "bring umbrella when it rains", "tomorrow will rain", "bring coat" };
			string expectedOutput = "tomorrow will rain";
			vector<string> hardcodedInput;
			
			for (int i = 0; i < ARRAY_SIZE; i++) {
				hardcodedInput.push_back(inputs[i]);
			}

			vector<string> actualOutput;

			CommandProcessor cmdProcessor;
			cmdProcessor.setTextInputs(hardcodedInput);
			actualOutput = cmdProcessor.searchText(searchForWord);

			Assert::AreEqual(expectedOutput, actualOutput);

		}

	};
}