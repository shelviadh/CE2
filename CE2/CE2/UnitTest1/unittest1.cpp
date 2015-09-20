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
			// TODO: Your test code here
			string inputs[ARRAY_SIZE] = { "table", "apple", "friends", "dog", "car" };
			string sortedInputs[ARRAY_SIZE] = { "apple", "car", "dog", "friends", "table" };

			vector<string> hardcodedInput;

			for (int i = 0; i < ARRAY_SIZE; i++) {
				hardcodedInput.push_back(inputs[i]);
			}
			
			CommandProcessor cmdProcessor;
			cmdProcessor.setTextInputs(hardcodedInput);
			//cmdProcessor.sortText();
			
			vector<string> processedTexts;
			cmdProcessor.getTextInputs();

			for (int i = 0; i < processedTexts.size(); i++) {
				Assert::AreEqual(processedTexts[i], inputs[i]);
			}
		}

	};
}