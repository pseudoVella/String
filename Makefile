CXX = g++
CXXFLAGS = -Wall -v
INCLUDE = -Isrc

AR = ar
ARFLAGS = rvs
MAKE = make

out_dir = build

.PHONY: all
all: $(out_dir)/STR.o $(out_dir)/libSTR.a example/test
.PHONY: fixed
fixed:$(out_dir)/FSTR.o $(out_dir)/CNT.o $(out_dir)/libFSTR.a example/ftest

$(out_dir)/STR.o: CXXFLAGS += -O2 -c
$(out_dir)/STR.o: src/STR.cpp src/STR.h
	if [ ! -d build ]; then mkdir build; fi
	$(CXX) $(CXXFLAGS) -o $@ $< $(INCLUDE)

$(out_dir)/libSTR.a: $(out_dir)/STR.o
	cd $(out_dir) && $(AR) $(ARFLAGS) $(@F) $(<F)


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
example/test: LIBS = -lSTR
example/test: CXXFLAGS += -O2
example/test: example/test.cpp $(out_dir)/libSTR.a src/STR.h
	$(CXX) $(CXXFLAGS) -o $@ $< $(LIB_DIR) $(LIBS) $(INCLUDE)

example/ftest: LIBS = -lFSTR
example/ftest: CXXFLAGS += -Os
example/ftest: example/ftest.cpp $(out_dir)/libFSTR.a src/FSTR.h
	$(CXX) $(CXXFLAGS) -o $@ $< $(LIB_DIR) $(LIBS) $(INCLUDE)

.PHONY: clean
clean:
	if [ -d $(out_dir) ]; then rm -rf $(out_dir)/*.o; fi

.PHONY: dist-clean
dist-clean:
	if [ -d $(out_dir) ]; then rm -rf $(out_dir); fi
	if [ -f example/test ]; then rm -f example/test; fi

