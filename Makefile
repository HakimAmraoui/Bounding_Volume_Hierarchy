# # Le compilateur à utiliser
CXX = g++
# # Les options du compilateur
CXXFLAGS = --std=c++17

########################################

INCLUDE		=	./include/

DIR		=	./src/

SRC		=	$(INCLUDE)3D/aMaterial.hpp						\
			$(INCLUDE)defines.hpp							\
			$(INCLUDE)material/flatColorMaterial.hpp		\
			$(INCLUDE)image.hpp								\
			$(DIR)3D/aObject3D.cpp							\
			$(DIR)3D/intersection.cpp						\
			$(DIR)camera.cpp								\
			$(DIR)chrono.cpp								\
			$(DIR)implicitSphere.cpp						\
			$(DIR)light/light.cpp							\
			$(DIR)light/point_light.cpp						\
			$(DIR)main.cpp									\
			$(DIR)material/brdf.cpp							\
			$(DIR)material/lightMaterial.cpp				\
			$(DIR)plan.cpp									\
			$(DIR)ray.cpp									\
			$(DIR)scene.cpp									\
			$(DIR)sphere.cpp								\
			$(DIR)triangleMesh.cpp

# $(DIR)scene.cpp					\
# $(DIR)material.cpp				\
# $(DIR)solid.cpp					\
# $(DIR)vector3.cpp				\

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

