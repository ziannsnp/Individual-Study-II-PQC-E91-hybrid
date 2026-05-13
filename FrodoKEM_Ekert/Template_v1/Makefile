# 1. กำหนดตัวแปรพื้นฐาน
CC = gcc
TARGET = frodo_test

# 2. ระบุ Path ของ OpenSSL ตามที่คุณให้มา
OPENSSL_INC = /opt/homebrew/opt/openssl@3/include
OPENSSL_LIB = /opt/homebrew/opt/openssl@3/lib

# 3. กำหนด Flags สำหรับ Compiler และ Linker
CFLAGS = -I$(OPENSSL_INC) -Wall
LDFLAGS = -L$(OPENSSL_LIB) -lcrypto

# 4. รายชื่อไฟล์ Source Code (ใช้ *.c เพื่อความสะดวกในการเพิ่มไฟล์ Phase 2, 3)
SRC = main.c Generate_A.c Generate_S_and_E.c Compute_B.c Attack.c

# --- Rules ---

# คำสั่งหลัก: แค่พิมพ์ 'make' ใน terminal
all:
	$(CC) -o $(TARGET) $(SRC) $(CFLAGS) $(LDFLAGS)

# คำสั่งสำหรับลบไฟล์ที่ compile แล้ว: พิมพ์ 'make clean'
clean:
	rm -f $(TARGET)