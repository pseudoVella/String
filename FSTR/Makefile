CXX = g++
CXXFLAGS = -Wall -v
INCLUDE = -Isrc

AR = ar
ARFLAGS = rvs
MAKE = make

out_dir = build

.PHONY: all
all: $(out_dir)/CNT.o $(out_dir)/FSTR.o $(out_dir)/libFSTR.a example/ftest

$(out_dir)/FSTR.o: CXXFLAGS += -Os -c
$(out_dir)/FSTR.o: src/FSTR.cpp src/FSTR.h src/CNT.h
	if [ ! -d build ]; then mkdir build; fi
	$(CXX) $(CXXFLAGS) -o $@ $< $(INCLUDE)

$(out_dir)/CNT.o: CXXFLAGS += -Os -c
$(out_dir)/CNT.o: src/CNT.cpp src/CNT.h
	if [ ! -d build ]; then mkdir build; fi
	$(CXX) $(CXXFLAGS) -o $@ $< $(INCLUDE)

$(out_dir)/libFSTR.a: $(out_dir)/FSTR.o $(out_dir)/CNT.o
	cd $(out_dir) && $(AR) $(ARFLAGS) $(@F) $(?F)

LIB_DIR = -Lbuild
example/ftest: LIBS = -lFSTR
example/ftest: CXXFLAGS += -Os
example/ftest: example/fstr_test.cpp $(out_dir)/libFSTR.a src/FSTR.h
	$(CXX) $(CXXFLAGS) -o $@ $< $(LIB_DIR) $(LIBS) $(INCLUDE)

.PHONY: clean
clean:
	if [ -d $(out_dir) ]; then rm -f $(out_dir)/*.o; fi

.PHONY: dist-clean
dist-clean:
	if [ -d $(out_dir) ]; then rm -rf $(out_dir); fi
	if [ -f example/ftest ]; then rm -f example/ftest; fi

