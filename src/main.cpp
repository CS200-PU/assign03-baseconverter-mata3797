//******************************************************************************
// File name:   main.cpp
// Author:      Keolakupono Mataele
// Date:        09/23/2024
// Class:       CS200
// Assignment:  03 Base Converter
// Purpose:     Convert between base-10, binary and hexidecimal numbers
// Hours:       0.25
//******************************************************************************

#include <iostream>
#include <istream>
#include <string.h>

using namespace std;

int hexCharToInt (char hexDigit);
char getBase (const string& strNumber);
string getNumber (const string& prompt);
void printTitle (const string& myTitle);
string binaryToDecimal (const string& strNumber);
string decimalToBinary (const string& strNumber);
string decimalToHex (const string& strNumber);
string hexToDecimal (const string& strNumber);
string hexToBinary (const string& strNumber);
string binaryToHex (const string& strNumber);

int main () {
  string userPrompt = "Enter your string to convert (q to quit): ";
  string myTitle = "*****HEX-DECIMAL-BINARY CONVERTER*****";
  string number;
  string output1;
  string output2;

  printTitle (myTitle);
  number = getNumber (userPrompt);

  switch (getBase (number)) {
    case 'D':
      cout << "The binary conversion is: " 
        << decimalToBinary (number) << endl;
      cout << "The hexadecimal conversion is: " 
        << decimalToHex (number) << endl;
      break;
    case 'H':
      hexToBinary (number);
      hexToDecimal (number);
      break;
    case 'B':
      binaryToDecimal (number);
      binaryToHex (number);
      break;
  }
  
  return EXIT_SUCCESS;
}

/******************************************************************************
Description: changes the value of a hex character to an integer
Parameters: hexDigit - a character representing a hex digit
Return: and integer representation of the hex character
******************************************************************************/
int hexCharToInt (char hexDigit) {
  if (hexDigit >= 48 && hexDigit <= 57) {
    return static_cast<int>(hexDigit);
  }
  else if (hexDigit >= 65 && hexDigit <= 70) {
    return (static_cast<int>(hexDigit - 13)) + 10;
  }
  else {
    return 0;
  }
}

/******************************************************************************
Description: determines what base type the number is
Parameters: strNumber - a string representing a decimal, hex, or binary number
Return: a character representing what base type the number is
******************************************************************************/
char getBase (const string& strNumber) {
  if (strNumber[0]=='0' && strNumber[1]=='b') {
    return 'B';
  }
  else if (strNumber[0]=='0' && strNumber[1]=='x') {
    return 'H';
  }
  else {
    return 'D';
  }
}

/******************************************************************************
Description: prompts the user and gets a string representation of a number
Parameters: prompt - the user prompt to get a number
Return: a string representation of a number
******************************************************************************/
string getNumber (const string& prompt) {
  string strNum;
  cout << prompt;
  cin >> strNum;
  return strNum;
}

/******************************************************************************
Description: prints out the title for the program
Parameters: myTitle - the title for the program
Return: none
******************************************************************************/
void printTitle (const string& myTitle) {
  cout << "**************************************" << endl;
  cout << myTitle << endl;
  cout << "**************************************" << endl;
}

/******************************************************************************
Description: converts a binary number to a decimal number
Parameters: strNumber - a string representing a binary number
Return: a string representation of a decimal number
******************************************************************************/
string binaryToDecimal (const string& strNumber) {

}

/******************************************************************************
Description: converts a decimal number to a binary number
Parameters: strNumber - a string representing a decimal number
Return: a string representation of a binary number
******************************************************************************/
string decimalToBinary (const string& strNumber) {
  string binary = "";
  int remainder;
  int number = stoi(strNumber);
  while (number != 0) {
    remainder = number % 2;
    number = number / 2;
    binary = to_string(remainder) + binary;
  }
  if (binary == "") {
    binary = binary + "0";
  }
  return "0b" + binary;
}

/******************************************************************************
Description: converts a decimal number to a hex number
Parameters: strNumber - a string representing a decimal number
Return: a string representation of a hex number
******************************************************************************/
string decimalToHex (const string& strNumber) {
  string hex = "";
  int remainder;
  int number = stoi(strNumber);
  while (number != 0) {
    remainder = number % 16;
    number = number / 16;
    if (remainder <= 9) {
      hex = to_string(remainder) + hex;
    }
    else if (remainder == 10) {
      hex = "A" + hex;
    }
    else if (remainder == 11) {
      hex = "B" + hex;
    }
    else if (remainder == 12) {
      hex = "C" + hex;
    }
    else if (remainder == 13) {
      hex = "D" + hex;
    }
    else if (remainder == 14) {
      hex = "E" + hex;
    }
    else if (remainder == 15) {
      hex = "F" + hex;
    }
  }
  if (hex == "") {
    hex = hex + "0";
  }
  return "0x" + hex;
}

/******************************************************************************
Description: converts a hex number to a decimal number
Parameters: strNumber - a string representing a hex number
Return: a string representation of a decimal number
******************************************************************************/
string hexToDecimal (const string& strNumber) {

}

/******************************************************************************
Description: converts a hex number to a binary number
Parameters: strNumber - a string representing a hex number
Return: a string representation of a binary number
******************************************************************************/
string hexToBinary (const string& strNumber) {

}

/******************************************************************************
Description: converts a binary number to a hex number
Parameters: strNumber - a string representing a binary number
Return: a string representation of a hex number
******************************************************************************/
string binaryToHex (const string& strNumber) {

}