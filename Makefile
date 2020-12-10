DESTDIR :=
CC ?= gcc
PKGNAME := sahito-service
PREFIX := /usr/local

.PHONY: default
default: build

.PHONY: all
all: build install

.PHONY: build
build: src/linux/c/main.c
	mkdir build
	${CC} src/linux/c/main.c -o build/sahito-service

.PHONY: install
install: build/sahito-service
	@#Bin Files
	install -Dm755 build/sahito-service "${DESTDIR}${PREFIX}/share/${PKGNAME}/service"

.PHONY: uninstall
uninstall:
	@#Bin Files and Other Files
	rm -rf "${DESTDIR}${PREFIX}/share/${PKGNAME}"
