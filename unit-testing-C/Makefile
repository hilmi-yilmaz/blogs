CC = gcc
CFLAGS = -Wall -Wextra -Werror

TESTEXE = test_exec

UNITY_CONFIG_DEFINES = 	-D UNITY_OUTPUT_COLOR \
						-D UNITY_FIXTURE_NO_EXTRAS

UNITY_INCL = 	-I./unity/src/ \
				-I./unity/extras/fixture/src

TEST_FILES = 	unity/src/unity.c \
				unity/extras/fixture/src/unity_fixture.c \
				test/main/all_tests.c \
				test/main/all_tests_runner.c \
				test/test_string_join.c \
				src/string_join.c

# Test object files
TEST_OBJ_DIR = test_obj
TEST_OBJ_FILES= $(TEST_FILES:%.c=$(TEST_OBJ_DIR)/%.o)

# Create test executable
test: $(TEST_OBJ_DIR) $(TESTEXE)

# Create and run test executable
test_run: test
	@./$(TESTEXE) -v

# Create test_obj directory
$(TEST_OBJ_DIR):
	mkdir -p $@

# Unit tests
$(TESTEXE): $(TEST_OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_OBJ_FILES): $(TEST_OBJ_DIR)/%.o : %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(UNITY_CONFIG_DEFINES) $(UNITY_INCL) -c $< -o $@

clean:
	rm -rf $(TEST_OBJ_DIR)

fclean: clean
	rm -f $(TESTEXE)

re: fclean all

.PHONY = test clean fclean re