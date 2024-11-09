NAME = cpp98-test-framework
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I./include

SRCS = src/test.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

examples: $(NAME)
	$(MAKE) -C examples/basic
	$(MAKE) -C examples/string_test

tests: $(NAME)
	$(MAKE) -C tests

clean:
	$(RM) $(OBJS)
	$(MAKE) -C examples/basic clean
	$(MAKE) -C examples/string_test clean
	$(MAKE) -C tests clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C examples/basic fclean
	$(MAKE) -C examples/string_test fclean
	$(MAKE) -C tests fclean

re: fclean all

.PHONY: all examples tests clean fclean re
