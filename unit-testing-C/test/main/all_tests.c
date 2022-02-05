/* all_tests.c */

#include "unity_fixture.h"

/* Which test groups to run */
static void	run_all_tests(void)
{
	RUN_TEST_GROUP(StringJoin);
}

int	main(int argc, const char *argv[])
{
	return (UnityMain(argc, argv, run_all_tests));
}