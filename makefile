CC=g++
CFLAGS=-c -Wall -ggdb3 -std=gnu++11 -I gtest-1.7.0/include
LDFLAGS=-I gtest-1.7.0/include gtest-1.7.0/make/gtest-all.o
SOURCES=rt.cpp scene.cpp light.cpp SceneObjs.cpp ray.cpp rgb.cpp vector.cpp camera.cpp vector.cpp SceneReader.cpp
OBJECTS=scene.o light.o SceneObjs.o ray.o rgb.o vector.o camera.o SceneReader.o
HEADERS=scene.hpp light.hpp SceneObjs.hpp ray.hpp rgb.hpp vector.hpp camera.hpp vector.hpp SceneReader.hpp
EXECUTABLES=rt

all: rt

raytracer_test: raytracer_test.o $(OBJECTS)
	$(CC) $(LDFLAGS) $@.o $(OBJECTS) -o $@ -lpthread

$(OBJECTS): $(HEADERS) $(SOURCES)

rt: rt.o $(HEADERS) $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $@.o -o $@ -lpthread

.cpp.o: $(HEADERS) $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@

test: raytracer_test

clean:
	rm *.o $(EXECUTABLES)