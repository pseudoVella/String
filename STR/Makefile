CXX = g++
CXXFLAGS = -Wall -v
INCLUDE = -Isrc

AR = ar
ARFLAGS = rvs
MAKE = make

out_dir = build

.PHONY: all
all: $(out_dir)/STR.o $(out_dir)/libSTR.a example/dtest

$(out_dir)/STR.o: CXXFLAGS += -O2 -c
$(out_dir)/STR.o: src/STR.cpp src/STR.h
	if [ ! -d build ]; then mkdir build; fi
	$(CXX) $(CXXFLAGS) -o $@ $< $(INCLUDE)

$(out_dir)/libSTR.a: $(out_dir)/STR.o
	cd $(out_dir) && $(AR) $(ARFLAGS) $(@F) $(<F)

LIB_DIR = -Lbuild
example/dtest: LIBS = -lSTR
example/dtest: CXXFLAGS += -O2
example/dtest: example/str_test.cpp $(out_dir)/libSTR.a src/STR.h
	$(CXX) $(CXXFLAGS) -o $@ $< $(LIB_DIR) $(LIBS) $(INCLUDE)

.PHONY: clean
clean:
	if [ -d $(out_dir) ]; then rm -rf $(out_dir)/*.o; fi

.PHONY: dist-clean
dist-clean:
	if [ -d $(out_dir) ]; then rm -rf $(out_dir); fi
	if [ -f example/dtest ]; then rm -f example/dtest; fi

