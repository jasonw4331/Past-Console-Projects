#include <iostream>

using namespace std;

int main()
{
  CC = gcc;
  CFLAGS  = -g -Wall;

  #  the build target executable:
  TARGET = proj1.c;

  all: $(TARGET);

  $(TARGET): $(TARGET).c;
  	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

  clean:
  	$(RM) $(TARGET)
}
