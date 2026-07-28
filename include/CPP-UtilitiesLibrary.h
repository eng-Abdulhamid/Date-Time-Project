#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
#define PI = 3.14;

class clsUtil
{
public:
    enum enCharType { 
        SamallLetter = 1,    // Lowercase letters (ASCII range 97-122)
        CapitalLetter = 2,   // Uppercase letters (ASCII range 65-90)
        Digit = 3,            // Digits (ASCII range 48-57)
        SpecialCharacter = 4,// Special characters (ASCII range 33-47)
        MixChars = 5
    };
    static void ResetMonitor()
    {
        system("cls");      // Clear The Screen ...
        system("color 0F"); // Reset to Black ... 
    }
    static void  EncryptText(string& Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }
    }    
    static string  ReturnEncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }


    static void  DecryptText(string& Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }

    }
    static string  ReturnDecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

	
    static string Taps(int Num)
    {
        string tap = "";
        for (int i = 0;i<=Num;i++)
        {
            tap += '\t';
        }
        return tap;
    }
    static string charToRepeat(char ch , short RepeatNumber , short NumberOfCharInEveryLoop = 1)
    {
        string Repeated = "";
        for (int i = 0;i<RepeatNumber;i++)
        {
            Repeated += ch;
            if (NumberOfCharInEveryLoop > 1)
            {
                for (int j = 0;j<NumberOfCharInEveryLoop - 1;j++)
                {
                    Repeated += ch;
                }
            }
        }
        return Repeated;
    }

    static char ReadChar()
    {
        char c = '0';
        cout << "Enter Character.." << endl;
        cin >> c;
        return c;
    }

    static int ReadIntNumber(string Message)
    {
        int Number = 0;
        cout << Message << endl;
        cin >> Number;
        return Number;
    }

    static string ReadString(string Message)
    {
        string S = "";
        cout << Message << endl;
        getline(cin >> ws, S);
        return S;
    }

    // Before you called the randome function, use this `srand` func.
    static void Srand()
    {
        // Seed the random number generator with the current time.
        // This ensures that different sequences of random numbers are produced on each run.
        srand((unsigned)time(NULL));
    }
    static int RandomNumber(int From, int To)
    {
        // Generate a random number between 0 and (To - From), then add From to shift the range.
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }
    static int GetSequenceRandomNumber(int SequenceNumber , int from , int to)
    {
        int seq = 0;
        for (int i = 0;i<SequenceNumber;i++)
        {
            seq += RandomNumber(from , to);
            if (i != SequenceNumber -1)
               {seq *= 10;}
            
        }
        return seq;
    }
    static void GetListOfSequenceRandomNumber(int listOfSequenceRandomNumbe,int SequenceNumber, int form , int to)
    {
        for (int i = 0;i<listOfSequenceRandomNumbe;i++)
        {
            cout << GetSequenceRandomNumber(SequenceNumber, form , to) << endl;
        }
    }
    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == enCharType::MixChars)
        {
            CharType = (enCharType) RandomNumber(1,3);
        }
        switch (CharType)
        {
            case enCharType::SamallLetter:
            {
                // Generate a random lowercase letter (ASCII: 97 'a' to 122 'z').
                return char(RandomNumber(97, 122));
                break; // break is not necessary after return.
            }
            case enCharType::CapitalLetter:
            {
                // Generate a random uppercase letter (ASCII: 65 'A' to 90 'Z').
                return char(RandomNumber(65, 90));
                break;
            }
            case enCharType::SpecialCharacter:
            {
                // Generate a random special character (ASCII: 33 '!' to 47 '/').
                return char(RandomNumber(33, 47));
                break;
            }
            case enCharType::Digit:
            {
                // Generate a random digit (ASCII: 48 '0' to 57 '9').
                return char(RandomNumber(48, 57));
                break;
            }
            default:
                return char(RandomNumber(97, 122));

        }
        // If no valid type is provided, return a null character.
        return '\0';
    }
    static int ReadPositiveNumber(string Message)
    {
        int Number = 0;  // Variable to store the user's input.
        do
        {
            cout << Message << endl; // Display the prompt message.
            cin >> Number;           // Read the number from the user.
        } while (Number <= 0);       // Continue prompting until a positive number is entered.
        return Number;
    }
    // static string GenerateWord(enCharType CharType, short Length)
    // {
    //     string Word;  // Initialize an empty string to build the word.

    //     // Loop for the number of characters specified by Length.
    //     for (int i = 1; i <= Length; i++)
    //     {
    //         // Append a random character of the specified type to the word.
    //         Word = Word + GetRandomCharacter(CharType);
    //     }
    //     return Word;
    // }
    // static string GenerateKey()
    // {
    //     string Key = "";  // Initialize an empty key string.

    //     // Concatenate four groups of 4 random uppercase letters, separated by hyphens.
    //     Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    //     Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    //     Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    //     Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
        
    //     return Key;
    // }
    static void GenerateKeys(short NumberOfKeys, enCharType Type)
    {
        // Loop from 1 to NumberOfKeys.
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            // Print the current key number and the generated key.
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(Type) << endl;
        }
    }
    static void ReadArray(int arr[100], int &arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;  // Read the total number of elements the user wishes to input.
        
        cout << "\nEnter array elements: \n";
        // Loop from 0 to arrLength - 1 to read each array element.
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "] : ";  // Display a prompt for each element (using 1-based indexing for clarity).
            cin >> arr[i];                           // Read the current element into the array.
        }
        cout << endl;  // Print an extra newline for formatting.
    }
    static void PrintArray(int arr[100], int arrLength , string dilem = " ")
    {
        // Loop through the array and print each element followed by a space.
        for (int i = 0; i < arrLength; i++)
            cout << arr[i] << dilem;
        
        cout << "\n";  // Print a newline after all elements are printed.
    }
    static void PrintArray(double arr[100], int arrLength , string dilem = " ")
    {
        // Loop through the array and print each element followed by a space.
        for (int i = 0; i < arrLength; i++)
            cout << arr[i] << dilem;
        
        cout << "\n";  // Print a newline after all elements are printed.
    }
    static void PrintArray(float arr[100], int arrLength , string dilem = " ")
    {
        // Loop through the array and print each element followed by a space.
        for (int i = 0; i < arrLength; i++)
            cout << arr[i] << dilem;
        
        cout << "\n";  // Print a newline after all elements are printed.
    }
    static void PrintArray(string arr[100], int arrLength , string dilem = " ")
    {
        // Loop through the array and print each element followed by a space.
        for (int i = 0; i < arrLength; i++)
            cout << arr[i] << dilem;
        
        cout << "\n";  // Print a newline after all elements are printed.
    }



    static int TimesRepeated(int Number, int arr[100], int arrLength)
    {
        int count = 0;  // Initialize a counter to zero.
        // Loop through the array indices from 0 to arrLength - 1.
        for (int i = 0; i <= arrLength - 1; i++)
        {
            if (Number == arr[i])  // If the current element equals the number we're checking,
            {
                count++;  // Increment the counter.
            }
        }
        return count;  // Return the total count.
    }
    static void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;  // Read the desired number of elements from the user.

        // Fill the array with random numbers between 1 and 100.
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(1, 100);
    }




    static int MaxNumberInArray(int arr[100], int arrLength)
    {
        int Max = 0;  // Initialize Max to 0. (Note: This assumes array elements are positive.)
        
        // Loop through the array to find the maximum element.
        for (int i = 0; i < arrLength; i++)
        {
            // If the current element is greater than the current Max, update Max.
            if (arr[i] > Max)
            {
                Max = arr[i];
            }
        }
        return Max;  // Return the maximum number found.
    }
    static int MinNumberInArray(int arr[100], int arrLength)
    {
        int Min = arr[0];  // Initialize Min with the first element of the array.
        
        // Loop through the array to find the smallest element.
        for (int i = 0; i < arrLength; i++)
        {
            // If the current element is less than the current minimum, update Min.
            if (arr[i] < Min)
            {
                Min = arr[i];
            }
        }
        return Min;  // Return the minimum value found.
    }
    static int SumArray(int arr[100], int arrLength)
    {
        int Sum = 0;  // Initialize sum to zero.
        
        // Loop through each element of the array and add it to Sum.
        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }
        
        return Sum;  // Return the calculated sum.
    }
        
    //     return Sum;  // Return the computed sum.
    // }
    static float ArrayAverage(int arr[100], int arrLength)
    {
        // Compute the average by casting the sum to float to ensure floating-point division.
        return (float)SumArray(arr, arrLength) / arrLength;
    }
    static void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
    {
        // Loop through each element up to arrLength and copy from source to destination.
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[i];
    }
    enum enPrimNotPrime { Prime = 1, NotPrime = 2 };
    static enPrimNotPrime CheckPrime(int Number)
    {
        // Compute M as roughly half of Number.
        // Note: Using round(Number / 2) here might not be the best approach
        // since for small numbers it may not be accurate; typically, we check until sqrt(Number).
        int M = round(Number / 2);
        
        // Loop from 2 to M to test for divisibility.
        for (int Counter = 2; Counter <= M; Counter++)
        {
            // If Number is divisible by any Counter, then it is not a prime.
            if (Number % Counter == 0)
                return enPrimNotPrime::NotPrime;  // Return NotPrime immediately.
        }
        
        // If no divisors were found, return Prime.
        return enPrimNotPrime::Prime;
    }
    static void FillArray(int arr[100], int &arrLength)
    {
        cout << "\nEnter number of elements:\n";
        cin >> arrLength;  // Read the number of elements from the user.
        
        // For each position in the array (from 0 to arrLength - 1),
        // fill the element with a random number between 1 and 100.
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(1, 100);
    }
    static void CopyOnlyPrimaryNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arr2Lenght)
    {
        int Counter = 0;  // Initialize a counter for the destination array index.
        
        // Loop through each element in the source array.
        for (int i = 0; i < arrLength; i++)
        {
            // If the current element is prime...
            if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
            {
                // Copy it to the destination array at the current counter index.
                arrDestination[Counter] = arrSource[i];
                Counter++;  // Increment the counter.
            }
        }
        
        // The code decrements Counter by 1 before assigning it to arr2Lenght.
        // Note: This is unusual as it reduces the count by one. It may be intended to adjust for 0-based indexing,
        // but typically the counter already reflects the number of primes found.
        arr2Lenght = --Counter;
    }
    static void FillArrayWithRandomNumbers(int arr[100], int arrLength  ,int form = 1 , int to = 100)
    {
        // Loop through the array from index 0 to arrLength - 1.
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(form,to);  // Assign each element a random number between 1 and 100.
    }
    static void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
    {
        // Loop through each index and add the corresponding elements from arr1 and arr2.
        for (int i = 0; i < arrLength; i++)
        {
            arrSum[i] = arr1[i] + arr2[i];  // Store the sum in the arrSum array.
        }
    }

    static void Swap(int& A, int& B)
    {
        int Temp;    // Temporary variable to hold the value of A.
        Temp = A;    // Save the value of A in Temp.
        A = B;       // Copy the value of B into A.
        B = Temp;    // Copy the value of Temp (original A) into B.
    }
    static void Swap(double& A, double& B)
    {
        double Temp;    // Temporary variable to hold the value of A.
        Temp = A;    // Save the value of A in Temp.
        A = B;       // Copy the value of B into A.
        B = Temp;    // Copy the value of Temp (original A) into B.
    }
    static void Swap(float& A, float& B)
    {
        float Temp;    // Temporary variable to hold the value of A.
        Temp = A;    // Save the value of A in Temp.
        A = B;       // Copy the value of B into A.
        B = Temp;    // Copy the value of Temp (original A) into B.
    }
    static void Swap(string& A, string& B)
    {
        string Temp;    // Temporary variable to hold the value of A.
        Temp = A;    // Save the value of A in Temp.
        A = B;       // Copy the value of B into A.
        B = Temp;    // Copy the value of Temp (original A) into B.
    }

    static void FillArrayWith1toN(int arr[100], int arrLength)
    {
        // Loop through each index and assign the value (index + 1) to that element.
        for (int i = 0; i < arrLength; i++)
            arr[i] = i + 1;
    }
    static void ShuffleArray(int arr[100], int arrLength)
    {
        // Loop through each element of the array.
        // For each iteration, swap two randomly chosen elements.
        for (int i = 0; i < arrLength; i++)
        {
            // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
            // Subtract 1 to convert it to a valid 0-based index.
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;
            // Swap the elements at the two randomly chosen indices.
            Swap(arr[index1], arr[index2]);
        }
    }
    static void ShuffleArray(double arr[100], int arrLength)
    {
        // Loop through each element of the array.
        // For each iteration, swap two randomly chosen elements.
        for (int i = 0; i < arrLength; i++)
        {
            // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
            // Subtract 1 to convert it to a valid 0-based index.
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;
            // Swap the elements at the two randomly chosen indices.
            Swap(arr[index1], arr[index2]);
        }
    }
    static void ShuffleArray(float arr[100], int arrLength)
    {
        // Loop through each element of the array.
        // For each iteration, swap two randomly chosen elements.
        for (int i = 0; i < arrLength; i++)
        {
            // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
            // Subtract 1 to convert it to a valid 0-based index.
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;
            // Swap the elements at the two randomly chosen indices.
            Swap(arr[index1], arr[index2]);
        }
    }

    static void ShuffleArray(string arr[100], int arrLength)
    {
        // Loop through each element of the array.
        // For each iteration, swap two randomly chosen elements.
        for (int i = 0; i < arrLength; i++)
        {
            // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
            // Subtract 1 to convert it to a valid 0-based index.
            int index1 = RandomNumber(1, arrLength) - 1;
            int index2 = RandomNumber(1, arrLength) - 1;
            // Swap the elements at the two randomly chosen indices.
            Swap(arr[index1], arr[index2]);
        }
    }


    static void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
    {
        // Loop through each element of the source array.
        // For each index i, copy the element at position (arrLength - 1 - i)
        // from the source array into the destination array at index i.
        for (int i = 0; i < arrLength; i++)
            arrDestination[i] = arrSource[arrLength - 1 - i];
    }
    static void PrintStringArray(string arr[100], int arrLength)
    {
        cout << "\nArray elements:\n\n";
        // Loop through the array and print each element with its index.
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Array[" << i << "] : ";
            cout << arr[i] << "\n";
        }
        cout << "\n"; // Extra newline for formatting.
    }
    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word;  // Initialize an empty string.
        // Append random characters to the word one by one.
        for (int i = 1; i <= Length; i++)
        {
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }
    static string GenerateKey(enCharType Type)
    {
        string Key = "";
        // Generate 4 groups of 4 uppercase letters, separated by hyphens.
        Key = GenerateWord(Type, 4) + "-";
        Key = Key + GenerateWord(Type, 4) + "-";
        Key = Key + GenerateWord(Type, 4) + "-";
        Key = Key + GenerateWord(Type, 4);
        return Key;
    }
    static void FillArrayWithKeys(enCharType Type,string arr[100], int arrLength)
    {
        // Loop through the array indices and generate a key for each element.
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(Type);
    }
    static void FillArrayWithRandomSequenceRandomNumber(int arr[100], int arrLength , int from , int to)
    {
        // Loop through the array indices and generate a key for each element.
        for (int i = 0; i < arrLength; i++)
            arr[i] = GetSequenceRandomNumber(6,from , to );
    }

    static void FillArrayWithRandomWords(enCharType Type,string arr[100], int arrLength)
    {
        // Loop through the array indices and generate a key for each element.
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(Type, arrLength);
    }



    static short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
    {
        // Loop through each element in the array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the current element equals the searched number.
            if (arr[i] == Number)
                return i; // Return the index immediately when the number is found.
        }
        
        // If the loop completes without finding the number, return -1.
        return -1;
    }
    static int ReadNumber()
    {
        int Number;
        cout << "\nPlease enter a number to search for?\n";
        cin >> Number;
        return Number;
    }
    static bool IsNumberInArray(int Number, int arr[100], int arrLength)
    {
        // Use FindNumberPositionInArray and check if the result is not -1.
        return FindNumberPositionInArray(Number, arr, arrLength) != -1;
    }
    static void AddArrayElement(int Number, int arr[100], int &arrLength)
    {
        // Since it's a new element, increase the array length by 1.
        arrLength++;
        // Store the new element at the index corresponding to the updated length (using zero-based indexing).
        arr[arrLength - 1] = Number;
    }

    static void InputUserNumbersInArray(int arr[100], int &arrLength)
    {
        bool AddMore = true;  // Boolean flag to control whether more numbers will be added.

        // Continue looping as long as the user wants to add more numbers.
        do
        {
            // Read a number from the user and add it to the array.
            AddArrayElement(ReadNumber(), arr, arrLength);

            // Ask the user if they want to add more numbers.
            // Input 0 for No, 1 for Yes.
            cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
            cin >> AddMore;  // Read user's decision (true if 1, false if 0).

        } while (AddMore);  // Continue looping if the user inputs true.
    }
    
    static void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
    {
        // Loop through each element of the source array.
        for (int i = 0; i < arrLength; i++)
            // Use AddArrayElement to copy the element to the destination array and update its length.
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
    }
    

    static void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
    {
        // Loop through each element of the source array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the current element is odd.
            if (arrSource[i] % 2 != 0)
            {
                // If odd, add it to the destination array using the AddArrayElement function.
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
            }
        }
    }
    
    
    static void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
    {
        // Loop through each element of the source array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the current element is prime using the CheckPrime function.
            if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
            {
                // If the number is prime, add it to the destination array.
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
            }
        }
    }
    static void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int &DestinationLength)
    {
        // Loop through each element in the source array.
        for (int i = 0; i < SourceLength; i++)
        {
            // If the current element is not already in the destination array...
            if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
            {
                // ...then add it to the destination array.
                AddArrayElement(arrSource[i], arrDestination, DestinationLength);
            }
        }
    }
    
    static bool IsPalindromeArray(int arr[100], int Length)
    {
        // Loop through each element of the array.
        // We only need to check up to the middle of the array.
        for (int i = 0; i < Length; i++)
        {
            // Compare the element at position i with its corresponding element from the end.
            if (arr[i] != arr[Length - i - 1])
            {
                return false;  // If any pair doesn't match, the array is not a palindrome.
            }
        }
        
        // If all corresponding pairs match, the array is a palindrome.
        return true;
    }
    static int OddCount(int arr[100], int arrLength)
    {
        int Counter = 0;  // Initialize the odd number counter to 0.

        // Loop through each element in the array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the element is odd (i.e., its remainder when divided by 2 is not 0).
            if (arr[i] % 2 != 0)
            {
                Counter++;  // Increment the counter if the element is odd.
            }
        }

        return Counter;  // Return the total count of odd numbers.
    }
    static int EvenCount(int arr[100], int arrLength)
    {
        int Counter = 0;  // Initialize counter for even numbers to 0.

        // Loop through each element of the array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the current element is even.
            if (arr[i] % 2 == 0)
            {
                Counter++;  // Increment the counter if the element is even.
            }
        }

        return Counter;  // Return the total count of even numbers.
    }

    static int PositiveCount(int arr[100], int arrLength)
    {
        int Counter = 0;  // Initialize a counter for positive numbers.
        
        // Loop through each element of the array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the current element is positive (or zero).
            if (arr[i] >= 0)
            {
                Counter++;  // Increment the counter if the condition is met.
            }
        }
        
        return Counter;  // Return the total count of positive numbers.
    }
    static int NegativeCount(int arr[100], int arrLength)
    {
        int Counter = 0;  // Initialize a counter for negative numbers.
        
        // Loop through each element of the array.
        for (int i = 0; i < arrLength; i++)
        {
            // Check if the current element is negative.
            if (arr[i] < 0)
            {
                Counter++;  // Increment the counter if the condition is met.
            }
        }
        
        return Counter;  // Return the total count of negative numbers.
    }
    static float MyABS(float Number)
    {
        // If the number is positive or zero, return it as is.
        if (Number > 0)
            return Number;
        else
            return Number * -1;  // If negative, multiply by -1 to make it positive.
    }

    static float GetFractionPart(float Number)
    {
        // Subtract the integer part of the number from the original number to get the fractional part.
        return Number - int(Number);
    }
    static int MyRound(float Number)
    {
        int IntPart;  // Variable to store the integer part of the number.
        IntPart = int(Number);  // Extract the integer part.

        // Compute the fractional part using the GetFractionPart function.
        float FractionsPart = GetFractionPart(Number);

        // If the absolute value of the fractional part is 0.5 or more, round the number accordingly.
        if (abs(FractionsPart) >= 0.5)
        {
            // If the number is positive, round up.
            if (Number > 0)
                return ++IntPart;  
            // If the number is negative, round down.
            else
                return --IntPart;
        }
        else
        {
            // If the fractional part is less than 0.5, keep the integer part as is.
            return IntPart;
        }
    }
    static int MyFloor(float Number)
    {
        // If the number is positive or zero, return its integer part.
        if (Number > 0)
            return int(Number);
        else
            // If the number is negative and has a fractional part, subtract 1 to get the floor value.
            return int(Number) - 1;
    }

    static int MyCeil(float Number)
    {
        // If the number has a fractional part greater than zero, round up if positive.
        if (abs(GetFractionPart(Number)) > 0)
        {
            if (Number > 0)
                return int(Number) + 1;  // Round up for positive numbers.
            else
                return int(Number);  // Keep the integer part for negative numbers.
        }
        else
            return Number;  // If the number is already an integer, return it as is.
    }
    static float MySqrt(float Number)
    {
        return pow(Number, 0.5);  // Compute the square root using the power function.
    }

private:
    static int Random(int From , int To)
    {
        return rand() % (To - From + 1) + From;
    }
    static void Fill3x3Matrix(int arr[3][3] , short Rows , short colomn)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < colomn; j++)
            {
                arr[i][j] = Random(1,100);
            }
        }
    }
    static int SumRow(int arr[3][3] , short Row , short colomn)
    {   
        int Sum = 0;
        for (int i = 0;i<colomn;i++)
        {
            Sum += arr[Row][i];
        }
        return Sum;
    }
    static void PrintEachRowSumIn3x3Matrix(int arr[3][3] , short Rows , short colomn)
    {
        for (int i = 0; i < Rows;i++)
        {
            cout << "Row " << i + 1 << " Sum " << SumRow(arr, i , colomn) << endl;
        }
    }
    static void Print3x3Matrix(int arr[3][3] , short Rows , short colomn)
    {
        for (int i = 0; i < Rows;i++)
        {
            for (int j = 0; j < colomn; j++)
            {
                cout << setw(3)<< arr[i][j] << '\t';
            }
            cout << endl;
        }
    }
    static void Fill3x3MatrixWithRandomNumber(int arr[3][3] , short Row , short Colomn)
    {
        for (int i = 0;i < Row;i++)
        {
            for (int j = 0;j<Colomn;j++)
            {
                arr[i][j] = Random(1, 100);
            }
        }
    }
    static int SumColomn(int arr[3][3] , short Row , short ColNumber)
    {
        int Sum = 0;
        for (int i = 0;i<Row;i++)
        {
            Sum += arr[i][ColNumber];
        }
        return Sum;
    }
    static void PrintMatrix(int arr[3][3] , short Row , short Colomn)
    {
        for (int i = 0;i<Row;i++)
        {
            for (int j = 0; j< Colomn;j++)
            {
                cout << setw(3) << arr[i][j] << '\t';
            }
            cout << endl;
        }
    }
    static void PrintSumOfColomnInMatrix(int arr[3][3]  , int Row , int Colomn)
    {
        for (int i = 0;i<Colomn;i++)
        {
            cout << "Colomn " << i + 1 << " Sum = " << SumColomn(arr , Row , i) << endl;
        }
    }
    static void Fill3x3MatrixWithOrderedNumbers(int arr[3][3] ,short Row , short Colomn)
    {
        short Counter = 0;
        for (int i = 0;i<Row;i++)
        {
            for (int j = 0;j < Colomn;j++)
            {
                Counter++;
                arr[i][j] = Counter;
            }
        }
    }
    static void PrintOrderMatrix(int arr[3][3] , int Row , int Colomn)
    {
        for (int i = 0;i<Row;i++)
        {
            for (int j = 0;j < Colomn;j++)
            {
                cout <<  arr[i][j] << '\t';
            }
            cout << '\n';
        }
    }
    static void TrasposeMatrix(int arr[3][3], int Transpose[3][3], short Row , short Colomn)
    {
        for (int i = 0;i< Row;i++)
        {
            for (int j = 0; j< Colomn;j++)
            {
                Transpose[j][i] = arr[i][j];
            }
        }
    }
    static void FillMatrix3x3WithRandomNumber(int arr[3][3] ,short Row , short Colomn)
    {
        for (int i = 0; i < Row; i++)
        {
            for (int j = 0;j< Colomn;j++)
            {
                arr[i][j] = Random(0,1);
            }
        }
    }
    static void PrintMatrix3x3(int arr[3][3], short Row , short Colomn) {
        for (int i = 0; i < Row;i++)
        {
            for (int j = 0; j < Colomn;j++)
            {
                printf("%0*d\t",2 , arr[i][j]); // Formating
            }
            cout << endl;
        }
    }
    static bool CheckIdentityMatreces(int arr[3][3], short Row , short Colomn)
    {
        if (Row != Colomn) return false;// To Check if Squair Matrix
        for (int i = 0;i<Row;i++)
        {
            for (int j = 0;j<Colomn;j++)
            {
                // we must to verification of two condition to Check if Identity Matrix 

                // check for diagonals element
                if (i == j && arr[i][j] != 1) return false;      // 1 --> A First Condition to verification 
                // check for rest element
                else if (i != j && arr[i][j] != 0) return false; // 2 --> A Second Condition to verification 

                // if (i == j) 
                // {
                //     if (arr[i][j] != 1) return false;
                //     continue;
                // }
                // else if (arr[i][j] != 0) return false;
            }
        }
        // when all of Conditions are will verfiication above 
        return true;
    }
    static bool IfScalarMatrix(int arr[3][3] , short Row , short Colomn)
    {
        short TheFirstDiagonalElementInMatrix = arr[0][0];
        // Check if Diagonal is Have a same number and rest/Remmaining value have Number 0; => Scalar
        for (int i = 0;i<Row;i++)
        {
            for (int j = 0;j<Colomn;j++)
            {
                if (i == j && arr[i][j] != TheFirstDiagonalElementInMatrix)
                {
                    return false;
                }
                
                if (i != j && arr[i][j] != 0) return false;
            }
        }
        return true;
    }
    static short count_number_in_Matrix(int arr[3][3] , int NumberToCounter, short Row , short Colomn)
    {
        int Counter = 0;
        for (int i =0;i<Row;i++)
        {
            for (int j = 0;j<Colomn;j++)
            {
                if (arr[i][j] == NumberToCounter)
                {
                    Counter++;
                }
            }
        }
        return Counter;
    }
    static bool CheckSparseMatrix(int arr[3][3] , short Row , short Colomn)
    {
        short CounterOfzeroNumber = 0;
        short CounterOtherNumber = 0;
        for (int i = 0;i<Row;i++)
        {
            for (int j = 0;j<Colomn;j++)
            {
                if (arr[i][j] == 0)
                {
                    CounterOfzeroNumber++;
                }
                else
                {
                    CounterOtherNumber++;
                }
            }
        }
        return CounterOfzeroNumber > CounterOtherNumber;
    }
    static short ReadShortNumber(string Message)
    {
        short Number = 0;
        cout << Message << endl;
        cin >> Number;
        return Number;
    }
    static bool CheckNumberExist(int arr[3][3] , int Number, short Row ,short Colomn)
    {
        for (int i = 0;i<Row;i++)
        {
            for (int j = 0;j<Colomn;j++)
            {
                if (arr[i][j] == Number) return true;
            }
        }
        return false;
    }
    static bool IfNumberIntersectedIN(int arr1Number , int arr2Search[3][3], int Row , int Colomn)
    {   
        for (int i = 0; i<Row;i++)
        {
            for (int j = 0; j<Colomn;j++)
            {
                if (arr1Number == arr2Search[i][j]) return true;       
            }
        }
        return false;
    }
    static string IntersectedNumberInMatrix(int arr1[3][3] , int arr2[3][3] , int Row , int Colomn)
    {
        string theSimilerNumber = "";
        for (int i = 0;i<Row;i++)
        {
            for (int j = 0;j<Colomn;j++)
            {
                if (IfNumberIntersectedIN(arr1[i][j], arr2,Row , Colomn))
                {
                    theSimilerNumber += to_string(arr1[i][j]) + '\t';
                }
            }
        }
        return theSimilerNumber;
    }
    static bool IsPalindromeMatrix(int arr[3][3] , int Row , int Colomn)
    {
        int k = Colomn - 1;
        for (int i = 0;i<Colomn;i++)
        {
            for (int j = 0;j<Colomn;j++)
            {
                if (arr[i][j] != arr[i][Colomn - 1 - j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    static void GetFiboacciSeries(short Number, int arr[10])
    {
        arr[0] = 1;
        short Previous1 = 0 , Previous2 = 0;
        for (short i = 1;i<= Number - 1;i++)
        {
            Previous1 = arr[i - 1];
            Previous2 = arr[i - 2];
            arr[i] = Previous1 + Previous2;
        }
    }
    static void Fibonacci(int Number , int previous1 , int previous2)
    {
        // Start number in Fibonacci is 0 and 1 : to get 1 1 2 ...
        int FibNumber = 0;
        if (Number > 0)
        {
            // To get current Fibonacci Number
            FibNumber = previous2 + previous1;

            // Number Upgraded 
            previous2 = previous1;
            previous1 = FibNumber; 
            
            cout << FibNumber << ' ';
            // Loop By Recursion
            Fibonacci(Number - 1, previous1 , previous2);
        }
    }



};
