# # Le compilateur à utiliser
CXX = g++
# # Les options du compilateur
CXXFLAGS = --std=c++17

#
#
#
# main: main.cpp vector3.o ray.o solid.o image.o camera.o scene.o sphere.o
#
# vector3.o: vector3.cpp vector3.hpp
# image.o: image.cpp image.hpp vector3.hpp
# ray.o: ray.cpp ray.hpp vector3.hpp
# camera.o: camera.cpp camera.hpp vector3.hpp ray.hpp
#
# solid.o: solid.cpp solid.hpp vector3.hpp ray.hpp material.hpp
# sphere.o: sphere.cpp solid.hpp vector3.hpp ray.hpp material.hpp
#
# scene.o: scene.cpp scene.hpp vector3.hpp image.hpp camera.hpp ray.hpp solid.hpp sphere.hpp
#
#
# clean:
# 	rm *.io ./path/file
# all:
# 	$(main)

########################################

INCLUDE		=	./include/

DIR		=	./src/

SRC		=	$(DIR)camera.cpp				\
			$(DIR)image.cpp					\
			$(DIR)main.cpp					\
			$(DIR)ray.cpp					\
			$(DIR)solid.cpp					\
			$(DIR)scene.cpp					\
			$(DIR)sphere.cpp				\
			$(DIR)plane.cpp					\
			$(DIR)vector3.cpp				\
			$(DIR)light.cpp					\
			$(DIR)material.cpp				\
			$(DIR)point_light.cpp

# CFLAGS		=		-I$(INCLUDE) --std=c++17 -lgmpxx -lgmp -Xpreprocessor -fopenmp -O3
# #LDFLAGS += -lomp

# NAME		=	Raytracing

# all: $(NAME)

# $(NAME): $(SRC)
# 		$(CXX) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(SRC)

# clean :
# 		$(RM) $(OBJ)

# fclean:		clean
# 		$(RM) $(NAME)  *.gc*

# re:		fclean all

# .PHONY: clean fclean all re

CFLAGS		=		-I$(INCLUDE) --std=c++17

NAME		=	Raytracing

all: $(NAME)

$(NAME): $(SRC)
		g++ $(CFLAGS) -o $(NAME) $(SRC)

clean :
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)  *.gc*

re:		fclean all

.PHONY: clean fclean all re

