CC=g++
CFLAGS=-I./include -I./external/doctest/doctest
BUILD_ROOT=build/
OBJ_ROOT=$(BUILD_ROOT)obj/
DEP_ROOT=$(BUILD_ROOT)deps/

.DEFAULT_GOAL := build/rmath-test

SOURCES = tests/test.cpp tests/vector_test.cpp \
    source/vector.cpp source/vector_generic.cpp \
    source/vectormath.cpp

OBJECTS = $(patsubst %.cpp,$(OBJ_ROOT)%.o,$(SOURCES))

# Some make notes:
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
# Deps on the rhs of | are order-only deps. So we don't trigger a rebuild when the directory is updated.
# $@ is the rule target, aka LHS of :, seems to be only the first item.
# $^ is the deps, aka RHS of :
# $< is the first item of the deps.
# @ at the beginning supresses echo

include $(shell find $(DEP_ROOT) -type f -name '*.d')

$(BUILD_ROOT):
	@mkdir -p $@

$(OBJ_ROOT):
	@mkdir -p $@

$(DEP_ROOT):
	@mkdir -p $@

# -MMD outputs the *.d deps files
$(OBJ_ROOT)%.o: %.cpp | $(OBJ_ROOT) $(DEP_ROOT)
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(patsubst %.cpp,$(DEP_ROOT)%.d,$<))
	$(CC) -MMD -MF $(patsubst %.cpp,$(DEP_ROOT)%.d,$<) -c -o $@ $< $(CFLAGS)

$(BUILD_ROOT)rmath-test: $(OBJECTS)  | $(BUILD_ROOT)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -r $(BUILD_ROOT)
