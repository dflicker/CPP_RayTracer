CC=g++
CFLAGS=-c -Wall -ggdb3 -std=gnu++11 -I gtest-1.7.0/include
LDFLAGS=-I gtest-1.7.0/include gtest-1.7.0/make/gtest-all.o
SOURCES=raytracer_test.cpp rt.cpp
OBJECTS=rt.o raytracer_test.o
HEADERS=scene.hpp light.hpp SceneObjs.hpp ray.hpp rgb.hpp vector.hpp
EXECUTABLES=raytracer_test rt

all: $(SOURCES) $(EXECUTABLES)

raytracer_test: $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $@.o -o $@ -lpthread

rt: $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $@.o -o $@ -lpthread

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLES)