PRODUCT=LibTest

CPPFLAGS=-Iproduct -Itest
CXXFLAGS=-Wall  -Wextra -pedantic -Wno-unused-parameter  -ggdb -std=c++11 -O0 $(CPPFLAGS)

SOURCES=$(wildcard product/*.cpp) \
        $(wildcard test/*.cpp)

HEADERS=$(wildcard product/*.h) \
        $(wildcard test/*.h)
LD_DEBUG=all make

LDFLAGS=-lgtest -lgmock -lgmock_main -lpthread

CXX=g++

.PHONY: all clean test

all: $(PRODUCT)

$(PRODUCT): $(SOURCES) $(HEADERS)
	@$(CXX) $(CXXFLAGS) $(SOURCES) -o $@ $(LDFLAGS)

clean:
	@rm -rf $(PRODUCT)
	@rm -rf kwinject.out .kwlp .kwps

klocwork:
	@kwcheck run

klocwork_after_makefile_change: clean
	@/opt/klocwork/kwenv.sh
	@kwcheck run

test: $(PRODUCT)
	@./$(PRODUCT)
