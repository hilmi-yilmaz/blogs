/* all_tests_runner.c */
#include "unity_fixture.h"

/* Which tests to run in StringJoin group */
TEST_GROUP_RUNNER(StringJoin)
{
	RUN_TEST_CASE(StringJoin, SimpleJoin);
	RUN_TEST_CASE(StringJoin, JoinWithS1EmptyString);
	RUN_TEST_CASE(StringJoin, JoinWithS2EmptyString);
	RUN_TEST_CASE(StringJoin, JoinWithBothS1AndS2EmptyString);
	RUN_TEST_CASE(StringJoin, InputNullForS1);
}