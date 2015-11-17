#
# Makefile template for CSE 30 -- PA4(myls)
#

HEADERS		= myls.h strings.h

C_SRCS		= myls.c buildFileInfoTable.c displayFileInfo.c \
		  sizeSortDescending.c nameSortDescending.c globals.c \
		  displayOwnerName.c displayPermissions.c setDisplayMode.c

ASM_SRCS	= displayGroupName.s sizeSortAscending.s \
		  nameSortAscending.s

C_OBJS		= myls.o buildFileInfoTable.o displayFileInfo.o \
		  sizeSortDescending.o displayOwnerName.o globals.o \
		  displayPermissions.o nameSortDescending.o setDisplayMode.o

ASM_OBJS	= displayGroupName.o nameSortAscending.o \
		  sizeSortAscending.o

OBJS		= ${C_OBJS} ${ASM_OBJS}

EXE		= myls

#
# Relevant man pages:
#
# man gcc
# man as
# man lint
#

GCC		= gcc
ASM		= $(GCC)
LINT		= lint

GCC_FLAGS	= -c -g -Wall -D__EXTENSIONS__ -std=c99
LINT_FLAGS1	= -c -err=warn
LINT_FLAGS2	= -u -err=warn
ASM_FLAGS	= -c -g
LD_FLAGS	= -g -Wall

#
# Standard rules
#

.s.o:
	@echo "Assembling each assembly source file separately ..."
	$(ASM) $(ASM_FLAGS) $<
	@echo ""

.c.o:
	@echo "Linting each C source file separately ..."
	$(LINT) $(LINT_FLAGS1) $<
	@echo ""
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

$(EXE):	$(OBJS)
	@echo "2nd phase lint on all C source files ..."
	$(LINT) $(LINT_FLAGS2) *.ln
	@echo ""
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(OBJS)
	@echo ""
	@echo "Done."

${C_OBJS}:      ${HEADERS}

unitTest_buildFileInfoTable: test.h myls.h strings.h buildFileInfoTable.c \
		  unitTest_buildFileInfoTable.c ref_buildFileInfoTable.o
	@echo "Compiling unitTest_buildFileInfoTable.c"
	gcc -g -o unitTest_buildFileInfoTable unitTest_buildFileInfoTable.c \
		  ref_buildFileInfoTable.o buildFileInfoTable.c
	@echo "Done."

run_unitTest_buildFileInfoTable: unitTest_buildFileInfoTable
	@echo "Running unitTest_buildFileInfoTable"
	@./unitTest_buildFileInfoTable


unitTest_setDisplayMode: test.h myls.h strings.h setDisplayMode.c \
		  unitTest_setDisplayMode.c
	@echo "Compiling unitTest_setDisplayMode.c"
	gcc -g -o unitTest_setDisplayMode setDisplayMode.c unitTest_setDisplayMode.c
	@echo "Done."

run_unitTest_setDisplayMode: unitTest_setDisplayMode
	@echo "Running unitTest_setDisplayMode"
	@./unitTest_setDisplayMode


unitTest_sizeSortAscending: test.h myls.h sizeSortAscending.s globals.c \
		       unitTest_sizeSortAscending.c
	@echo "Compiling unitTest_sizeSortAscending.c"
	gcc -g -o unitTest_sizeSortAscending sizeSortAscending.s globals.c \
		  unitTest_sizeSortAscending.c
	@echo "Done."

run_unitTest_sizeSortAscending: unitTest_sizeSortAscending
	@echo "Running unitTest_sizeSortAscending"
	@./unitTest_sizeSortAscending


unitTest_sizeSortDescending: test.h myls.h sizeSortDescending.c globals.c \
		       unitTest_sizeSortDescending.c
	@echo "Compiling unitTest_sizeSortDescending.c"
	gcc -g -o unitTest_sizeSortDescending sizeSortDescending.c globals.c \
		  unitTest_sizeSortDescending.c
	@echo "Done."

run_unitTest_sizeSortDescending: unitTest_sizeSortDescending
	@echo "Running unitTest_sizeSortDescending"
	@./unitTest_sizeSortDescending


unitTest_nameSortAscending: test.h myls.h nameSortAscending.s \
		       unitTest_nameSortAscending.c
	@echo "Compiling unitTest_nameSortAscending.c"
	gcc -g -o unitTest_nameSortAscending nameSortAscending.s \
		  unitTest_nameSortAscending.c
	@echo "Done."

run_unitTest_nameSortAscending: unitTest_nameSortAscending
	@echo "Running unitTest_nameSortAscending"
	@./unitTest_nameSortAscending


unitTest_nameSortDescending: test.h myls.h nameSortDescending.c \
		       unitTest_nameSortDescending.c
	@echo "Compiling unitTest_nameSortDescending.c"
	gcc -g -o unitTest_nameSortDescending nameSortDescending.c \
		  unitTest_nameSortDescending.c
	@echo "Done."

run_unitTest_nameSortDescending: unitTest_nameSortDescending
	@echo "Running unitTest_nameSortDescending"
	@./unitTest_nameSortDescending


unitTest_displayPermissions: test.h myls.h displayPermissions.c \
		       unitTest_displayPermissions.c
	@echo "Compiling unitTest_displayPermissions.c"
	gcc -g -o unitTest_displayPermissions displayPermissions.c \
		  unitTest_displayPermissions.c
	@echo "Done."

run_unitTest_displayPermissions: unitTest_displayPermissions
	@echo "Running unitTest_displayPermissions"
	@./unitTest_displayPermissions


unitTest_displayOwnerName: test.h myls.h displayOwnerName.c \
		       unitTest_displayOwnerName.c
	@echo "Compiling unitTest_displayOwnerName.c"
	gcc -g -o unitTest_displayOwnerName displayOwnerName.c \
		  unitTest_displayOwnerName.c
	@echo "Done."

run_unitTest_displayOwnerName: unitTest_displayOwnerName
	@echo "Running unitTest_displayOwnerName"
	@./unitTest_displayOwnerName


unitTest_displayGroupName: test.h myls.h displayGroupName.s \
		       unitTest_displayGroupName.c
	@echo "Compiling unitTest_displayGroupName.c"
	gcc -g -o unitTest_displayGroupName displayGroupName.s \
		  unitTest_displayGroupName.c
	@echo "Done."

run_unitTest_displayGroupName: unitTest_displayGroupName
	@echo "Running unitTest_displayGroupName"
	@./unitTest_displayGroupName


unitTest_displayFileInfo: test.h myls.h displayFileInfo.c \
		       unitTest_displayFileInfo.c
	@echo "Compiling unitTest_displayFileInfo.c"
	gcc -g -o unitTest_displayFileInfo displayFileInfo.c \
		  unitTest_displayFileInfo.c
	@echo "Done."

run_unitTest_displayFileInfo: unitTest_displayFileInfo
	@echo "Running unitTest_displayFileInfo"
	@./unitTest_displayFileInfo

clean:
	@echo "Cleaning up project directory ..."
	rm -f [^ref_]*.o a.out *.ln core $(EXE)
	@echo ""
	@echo "Clean."

new:
	make --no-print-directory clean
	make --no-print-directory

