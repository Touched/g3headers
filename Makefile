.PHONY: all

all: docs
	@cp -avr linker build
	@./scripts/generate_linker_script.py
	@cp -avr include build

docs:
	make -C doc
