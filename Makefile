CC=g++
CXXFLAGS=-Wall -Wextra -pedantic '-std=c++17' -g -O0
resourcedir=resources
staticresourcessrc=$(shell find /usr/local/share/Wt/resources -type f)
staticresourcesdest=$(staticresourcessrc:/usr/local/share/Wt/%=dist/app/%)
distdir=dist
executable=$(distdir)/meals
sources=$(wildcard src/*.cpp)
objects=$(sources:src/%.cpp=obj/%.o)
headers=$(wildcard src/*.hpp)
artifactssrc=$(wildcard $(resourcedir)/*)
artifactsdest=$(artifactssrc:$(resourcedir)/%=$(distdir)/%)

all: $(executable) $(artifactsdest) $(staticresourcesdest) Makefile

$(executable): $(distdir) $(objects) Makefile
	$(CC) $(CXXFLAGS) -o $(executable) \
	$(objects) \
	-lwt -lwthttp -lwtdbo -lwtdbosqlite3 \
	-lboost_signals -lboost_thread -lboost_atomic

$(distdir) :
	if [ ! -e $(distdir) ]; then mkdir $(distdir); fi;

$(staticresourcesdest) : dist/app/resources/% : /usr/local/share/Wt/resources/% Makefile | dist
	@mkdir -p $(dir $@);
	@cp -r $< $@;

$(artifactsdest) : $(distdir)/% : $(resourcedir)/% $(distdir)
	echo copying $< to $@
	cp -r $< $@

$(objects): | obj

obj:
	@mkdir -p $@

$(objects) : obj/%.o : src/%.cpp $(headers)
	$(CC) -c $(CXXFLAGS) $< -o $@

clean :
	rm -rf $(distdir) obj

echo :
	echo sources $(sources)
	echo objects $(objects)
	echo headers $(headers)
	echo executable $(executable)
	echo artifactsdest $(artifactsdest)
	echo artifactssrc $(artifactssrc)
