# Unit Testing your C functions with Unity

> We’ve all done it—written a bunch of code and then toiled to make it
work. Build it and then fix it. Testing was something we did after the
code was done. It was always an afterthought, but it was the only way
we knew ~ _Test-Driven-Development for Embedded C by James W. Grenning_

## Contents

1. My experiences.
2. Installing Unity: A unit-test framework for C.
3. An example of the Test-Driven-Development workflow.

## My experiences
---

Writing unit-tests first, and the functions after worked magical for me. Some positive experiences I had/have:

1. The bugs in my code almost vanished. The few bugs that are present are located very fast thanks to the unit-tests.
2. Because you write the test first, you need to think about the function, it's arguments and return value so that you don't start to code immediately without thinking. This makes my code better and straight to the point.
3. When you refactor your code or try to add small functionalities, the unit tests immediately show you whether you broke your code by changing things.

## Installing Unity: A unit-test framework for C.
---

[Unity](https://github.com/ThrowTheSwitch/Unity) is the unit-testing framework I use but there are a lot of others as well and they all do the same: Improve you code!

First create a directory for the example later in this tutorial:

```sh
mkdir unit_tesing_example
```

Then clone Unity through GitHub:

```sh
git clone https://github.com/ThrowTheSwitch/Unity.git unity
```

Installing Unity is as simple as that! Now let's go on to an example in which we will be using Unity.

## An example of the Test-Driven-Development workflow.
---

### Project structure

The project will have the following structure:

```
unit_testing_example/
| ---> 	src/
|		| ---> 	string_join.c
|		| --->	string_join.h
|
| ---> 	test/
|		| ---> 	main/
|		|		| ---> all_tests.c
|		|		| ---> all_tests_runner.c
|		|
|		| ---> 	test_string_join.c
```

We are going to write a string join function in C. We are first going to write a test, before writing our _string_join_ function itself. So let's thinks about how the function prototype looks like:

```C
char *string_join(char *s1, char *s2);
```

A test case could be the following:

- Input _s1_: "Hello "
- Input _s2_: "World!"
- Output should be: "Hello World!".

Create a _test_ directory and a _test_string_join.c_ file:

```sh
mkdir test
touch test/test_string_join.c
```

Open _test/test_string_join.c_ in your favorite editor:

1. First we have to include the _unity_fixture.h_ headerfile to make use of Unity.

	```C
	#include "unity_fixture.h"
	```
2. Also include the headerfile of the function we test, in this case _string_join.h_ (we'll create this later).
	```C
	#include "../src/string_join.h"
	```
3. Create a test group called _StringJoin_.
	```C
	TEST_GROUP(StringJoin)
	```

4. Create a test setup and teardown function. Whatever you write in these function will execute before and after each test. You could for example free allocated memory after each test. For now, we leave them empty (they have to be present in the test, otherwise it won't compile).
	```C
	TEST_SETUP(StringJoin)
	{
	}

	TEST_TEAR_DOWN(StringJoin)
	{
	}	
	``` 

5. Write our first test using the example above, namning this test _SimpleJoin_.

	```C
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
	```