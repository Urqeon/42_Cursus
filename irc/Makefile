NAME = ircserv

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	src/main.cpp src/Server.cpp src/Client.cpp src/SignalHandler.cpp src/PollManager.cpp src/Channel.cpp src/Bot.cpp \
		src/commands/Commands.cpp src/commands/Cap.cpp src/commands/Privmsg.cpp  src/commands/Notice.cpp \
		src/commands/Pass.cpp src/commands/Nick.cpp src/commands/User.cpp \
		src/commands/Join.cpp src/commands/List.cpp src/commands/Part.cpp src/commands/Topic.cpp \
		src/commands/Kick.cpp src/commands/Quit.cpp src/commands/Invite.cpp src/commands/Mode.cpp

OBJS = $(SRCS:src/%.cpp=obj/%.o)

INCLUDES = -Iinclude

all: obj $(NAME)

obj:
	mkdir -p obj

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re obj