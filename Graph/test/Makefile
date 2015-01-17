
include $(HOME)/Define.mk

IINC=-I$(INC)

all:
	$(CXX) $(IINC) -o main main.cc -L$(LIB_PATH) -lmy $(LIBS) $(CXXFLAGS)

clean:
	rm -rf main
