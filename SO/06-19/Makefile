########################################################################
# Code listing from "Advanced Linux Programming," by CodeSourcery LLC  #
# Copyright (C) 2001 by New Riders Publishing                          #
# See COPYRIGHT for license information.                               #
########################################################################

### Configuration.  ####################################################

# C source files for the server.
SOURCES		= server.c module.c common.c main.c
# Object files corresponding to source files.
OBJECTS		= $(SOURCES:.c=.o)
# Server module shared library files. 
MODULES		= diskfree.so issue.so processes.so time.so calendar.so terminal.so network.so routes.so ports.so dirlist.so accesslog.so userhistory.so

### Rules.  ############################################################

.PHONY:         all clean

# Default target: build everything.
all:            server $(MODULES) rust_video.so go_module.so

# Clean up build products.
clean:
	rm -f $(OBJECTS) $(MODULES) server
	cargo clean
	go clean

# The main server program.  Link with -Wl,-export-dyanamic so
# dynamically loaded modules can bind symbols in the program.  Link in
# libdl, which contains calls for dynamic loading.
server:         $(OBJECTS)
	$(CC) $(CFLAGS) -Wl,-export-dynamic -o $@ $^ -ldl

# All object files in the server depend on server.h.  But use the
# default rule for building object files from source files.
$(OBJECTS):     server.h

# Rule for building module shared libraries from the corresponding
# source files.   Compile -fPIC and generate a shared object file.
$(MODULES): \
%.so:           %.c server.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

# Rule for building Rust module
rust_video.so: Cargo.toml src/lib.rs
	cargo build --release
	mv target/release/librust_video.so rust_video.so

# Rule for building Go module
go_module.so: main.go
	go build -buildmode=c-shared -o go_module.so main.go
