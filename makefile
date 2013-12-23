CC=g++
CFLAGS=-c -Wall -std=gnu++11 -I gtest-1.7.0/include
LDFLAGS=-I gtest-1.7.0/include gtest-1.7.0/make/gtest-all.o
SOURCES=raytracer_test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=scene.hpp light.hpp SceneObjs.hpp ray.hpp rgb.hpp vector.hpp
EXECUTABLES=raytracer_test

all: $(SOURCES) $(EXECUTABLES)

raytracer_test: $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lpthread

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLES)