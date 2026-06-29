TARGET = soul_arte

CXX = g++

CXXFLAGS = -Wall -std=c++17

SRCS = main.cpp \
       sistema/sistema.cpp \
       usuario/usuario.cpp \
       usuario/cliente/cliente.cpp \
       usuario/artesao/artesao.cpp \
       produto/produto.cpp \
       pedido/pedido.cpp \
       produto/pintura/pintura.cpp \
       produto/escultura/escultura.cpp \
       produto/artesanato/artesanato.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)