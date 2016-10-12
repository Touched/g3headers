.PHONY: all macros docs test

all: test docs macros
	@cp -avr linker build
	@./scripts/generate_linker_script.py
	@cp -avr include build

test:
	bash test/test.sh

docs:
	make -C doc

MACRO_SRC = $(wildcard macros/*.yml)
macros: $(MACRO_SRC:macros/%.yml=build/include/pokeagb/macros/%.s)
build/include/pokeagb/macros/%.s: macros/%.yml
	@mkdir -p build/include/pokeagb/macros
	./scripts/generate_script_macros.py $< $@
