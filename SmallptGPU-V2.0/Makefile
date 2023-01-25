#
# SmallptGPU2 Makefile
#

ATISTREAMSDKROOT=/home/david/src/ati-stream-sdk-v2.0-lnx64

CC=g++
CCFLAGS=-O3 -ftree-vectorize -msse -msse2 -msse3 -mssse3 -fvariable-expansion-in-unroller -Wall \
	-I$(ATISTREAMSDKROOT)/include -L$(ATISTREAMSDKROOT)/lib/x86_64 -lglut -lOpenCL -lboost_thread-gcc43-mt-1_39
# Jens's patch for MacOS, comment the 2 lines above and un-comment the lines below
#CCFLAGS=-O3 -ftree-vectorize -msse -msse2 -msse3 -mssse3 -undefined dynamic_lookup -fvariable-expansion-in-unroller \
#	-cl-fast-relaxed-math -cl-mad-enable -Wall -framework OpenCL -framework OpenGl -framework Glut -lboost_thread-xgcc40-mt-1_39

default: all

all: Makefile smallptGPU

smallptGPU: smallptGPU.cpp displayfunc.cpp renderdevice.cpp renderconfig.cpp \
	renderdevice.h camera.h displayfunc.h geom.h renderconfig.h vec.h
	$(CC) $(CCFLAGS) -o smallptGPU smallptGPU.cpp displayfunc.cpp renderdevice.cpp renderconfig.cpp

clean:
	rm -rf smallptGPU image.ppm SmallptGPU-v2.0 SmallptGPU-v2.0.tgz

tgz: clean all
	mkdir SmallptGPU-v2.0
	cp -r smallptGPU scenes LICENSE.txt Makefile README.txt \
		*.pl \
		*.cpp \
		*.h \
		*.cl \
		*.bat \
		smallptGPU.exe glut32.dll SmallptGPU-v2.0
	tar zcvf smallptgpu-v2.0.tgz SmallptGPU-v2.0
	rm -rf SmallptGPU-v2.0
