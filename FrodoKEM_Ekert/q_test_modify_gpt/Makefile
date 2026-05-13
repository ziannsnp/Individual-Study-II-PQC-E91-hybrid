CC = gcc
TARGET = frodo_test

OPENSSL_INC = /opt/homebrew/opt/openssl@3/include
OPENSSL_LIB = /opt/homebrew/opt/openssl@3/lib

PARAM_N ?= 2
PARAM_Q ?= 32768

CFLAGS = -I$(OPENSSL_INC) -Wall -DFRODO_N=$(PARAM_N) -DFRODO_Q=$(PARAM_Q)
LDFLAGS = -L$(OPENSSL_LIB) -lcrypto -lm

SRC = main.c Generate_A.c Generate_S_and_E.c Compute_B.c Attack.c

all: $(TARGET)

$(TARGET): $(SRC) Generate_A.h Generate_S_and_E.h Compute_B.h Attack.h
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET)

rebuild: clean all

print-config:
	@echo "Building with N=$(PARAM_N), q=$(PARAM_Q)"
