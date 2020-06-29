#include <cassert>
#include <cstdlib>
#include <cstring>
#include "NIUString.h"
#include <iostream>
#include <iomanip>
using namespace std;
using std::ostream;
using std::istream;

/***************************************************************
NIUString()
Use: Initalizesthe NIUString objecs to 0 or nullptr
Parameters:none 
Returns: nothing
***************************************************************/ 
NIUString::NIUString()
{
}

/***************************************************************
NIUString(const char* other)
Use: initializes the new nIUString object to the c string other
Parameters: const char*
Returns: nothing
***************************************************************/

NIUString::NIUString(const char* other)
{
strSize = strlen(other);
strCapacity = size();

if(strCapacity == 0)
{
	strArray = nullptr;
}

else
{
	strArray = new char[strCapacity];

        strncpy(strArray,other,strSize);
}

}
/***************************************************************
NIUString(const NIUString(const NIUString& other)
Use:Copy constructor - Copies the contents of the string  array
Parameters:const NIUString&
Returns: nothing
***************************************************************/

NIUString::NIUString(const NIUString& other)
{
strCapacity = other.strCapacity;
strSize = other.strSize;

if(strCapacity == 0)

	strArray = nullptr;

else
{
	strArray = new char[strCapacity];
	strncpy(strArray,other.strArray,strCapacity);


}
}

/***************************************************************
~NIUString
Use: Destructor method that clears the array.
Parameters: None
Returns: nothing
***************************************************************/

NIUString::~NIUString()
{

clear();

}

/***************************************************************
operator=
Use: Assigns a C string to an NIUString object
Parameters:const char*
Returns: *this
***************************************************************/

NIUString& NIUString::operator=(const NIUString& other)
{

if(this != &other)
{

	 delete[] strArray;

	 strCapacity = other.strCapacity;
	 strSize = other.strSize;

	if(strCapacity != 0)
{
		strArray = new char [strCapacity];

		for(size_t i = 0; i < strSize; ++i)
                	strArray[i] = other.strArray[i];
}
	else
{
		strArray = nullptr;
}
}
	return *this;

}

/***************************************************************
operator=
Use: Should assign a C string to an NIUString object
Parameters: cosnt char* 
Returns: *this
***************************************************************/

NIUString& NIUString::operator=(const char* other)
{
delete[] strArray;
 strSize = size();
 strCapacity = strSize;

if(strCapacity == 0)
{
	 strArray = nullptr;
}

else
{
	strArray = new char [strCapacity]; 
	for(size_t i = 0; i < strSize; ++i)
                strArray[i] = other[i];
}

return *this;
}

/***************************************************************
capacity
Use: Returns the string capacity
Parameters: none
Returns:strCapacity 
***************************************************************/

size_t NIUString::capacity() const
{
return strCapacity;
}

/***************************************************************
size
Use: Returns the string size
Parameters:none
Returns: strSize
***************************************************************/

size_t NIUString::size() const
{
return strSize;
}

/***************************************************************
empty
Use: Should return true if the string is 0.  If not it returns false.
Parameters:none
Returns:true or false
***************************************************************/

bool NIUString::empty() const
{
if(strSize == 0)

	return true;

else

	return false;
}

/***************************************************************
clear
Use: Sets the string size and string capacity to 0. Uses the delete[]
operator to delete the string array.
Parameters:none
Returns: nothing
***************************************************************/

void NIUString::clear()
{
strSize = 0;
strCapacity = 0;
delete[] strArray;
}

/***************************************************************
reserve
Use:Modifies an object's string capacity without changing its size or 
the contents of the string array.
Parameters:size_t n
Returns: nothing
***************************************************************/

void NIUString::reserve(size_t n)
{

if(n < strSize || n == strCapacity)
	return;

strCapacity = n;
char* temp;

if(strCapacity == 0)
	temp = nullptr;
else
{
	temp = new char[strCapacity];

for(size_t i = 0; i < strSize; ++i)
                temp[i] = strArray[i];
}

strCapacity = n;
delete[] strArray;

strArray = temp;
}

/***************************************************************
operator== const
Use:Returns true if the characters stored in the string array of
the object that called the method are identical to the characters
stored in the string array of the NIUString object passed in as rhs.
Parameters:const NIUString&
Returns: true
***************************************************************/

bool NIUString::operator==(const NIUString& rhs) const
{
if(size() != rhs.strSize)
{
	return false;
}
for(unsigned int i = 0; i < size(); i++)
{
	if(strArray[i] != rhs.strArray[i])
		return false;
}
	return true;
}

/***************************************************************
operator== const
Use:This method returns true if the characters stored in the string array
of the object that called the method are identical to the characters of the
C string passed in as rhs.
Parameters:cons char*
Returns: true
***************************************************************/

bool NIUString::operator==(const char* rhs) const
{

for(unsigned int i = 0; i < size(); i++)
{
        if(strArray[i] != rhs[i])
                return false;
}
	        return true;
}

/***************************************************************
operator[]
Use:returns element pos of the string array
Parameters:size_t pos
Returns: strArray[pos]
***************************************************************/

const char& NIUString::operator[](size_t pos) const
{
	return strArray[pos];
}

/***************************************************************
operator[]
Use: Returns the element pos of the string array.
Parameters:size_t pos
Returns: strArray[pos]
***************************************************************/

char& NIUString::operator[](size_t pos)
{
	return strArray[pos];
}

/***************************************************************
operator<<
Use: Loops through the characters of the string array of the NIUString
object passed in as rhs and print them one at a time using the stream object
passed in as lhs
Parameters:ostream&, const NIUString&
Returns: lhs
***************************************************************/

ostream& operator<<(ostream& lhs, const NIUString& rhs)
{
for(unsigned int i = 0; i < rhs.strSize; ++i)
{
lhs << rhs.strArray[i];
}

return lhs;
}

/***************************************************************
operator==
Use: Returns true if the characters of the C string passed in as lhs
 are identical to the characters stored in the string array of the 
NIUString object passed in as rhs.
Parameters:const char*, const NIUString&
Returns: false
***************************************************************/

bool operator==(const char* lhs, const NIUString& rhs)
{
for(unsigned int i = 0; i < rhs.strSize; i++)
{
        if(lhs[i] != rhs.strArray[i])
	{
                return false;
	}

	else
	{
	        return true;
	}
}
	return false;
}
