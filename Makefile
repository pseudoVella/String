MAKE = make


.PHONY: all
all: FSTR STR

.PHONY: FSTR
FSTR:
	cd FSTR && make

.PHONY: STR
STR:
	cd STR && make

.PHONY: clean
clean:
	cd FSTR && make clean
	cd STR && make clean

.PHONY: dist-clean
dist-clean:
	cd FSTR && make dist-clean
	cd STR && make dist-clean

