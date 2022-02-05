/* test_string_join.c */
#include "unity_fixture.h"

/* The interface (headerfile) of the module we are testing (module = C file) */
#include "../src/string_join.h"

TEST_GROUP(StringJoin);

TEST_SETUP(StringJoin)
{
}

TEST_TEAR_DOWN(StringJoin)
{
}	

/* Test Case */
TEST(StringJoin, SimpleJoin)
{
	char *s1 = "Hello ";
	char *s2 = "World!";
	char *joined_string;

	/* Our result */
	joined_string = string_join(s1, s2);

	/* 
	Compare strings with Unity function. 
	First argument is the expected result, the second argument is our result 
	*/
	TEST_ASSERT_EQUAL_STRING("Hello World!", joined_string);
}

TEST(StringJoin, JoinWithS1EmptyString)
{
	char *s1 = "";
	char *s2 = "World!";
	char *joined_string;

	/* Our result */
	joined_string = string_join(s1, s2);

	/* 
	Compare strings with Unity function. 
	First argument is the expected result, the second argument is our result 
	*/
	TEST_ASSERT_EQUAL_STRING("World!", joined_string);
}

TEST(StringJoin, JoinWithS2EmptyString)
{
	char *s1 = "Hello ";
	char *s2 = "";
	char *joined_string;

	/* Our result */
	joined_string = string_join(s1, s2);

	/* 
	Compare strings with Unity function. 
	First argument is the expected result, the second argument is our result 
	*/
	TEST_ASSERT_EQUAL_STRING("Hello ", joined_string);
}

TEST(StringJoin, JoinWithBothS1AndS2EmptyString)
{
	char *s1 = "";
	char *s2 = "";
	char *joined_string;

	/* Our result */
	joined_string = string_join(s1, s2);

	/* 
	Compare strings with Unity function. 
	First argument is the expected result, the second argument is our result 
	*/
	TEST_ASSERT_EQUAL_STRING("", joined_string);
}

TEST(StringJoin, InputNullForS1)
{
	char *s1 = NULL;
	char *s2 = "World!";
	char *joined_string;

	/* Our result */
	joined_string = string_join(s1, s2);

	/* Check whether joined_string is NULL pointer */
	TEST_ASSERT_NULL(joined_string);
}
